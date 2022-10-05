#include <iostream>
#include "HashTable.h"
#include "BinHashTable.h"

using namespace std;

void testHashTable(){
    HashTable hashTable;

    hashTable.add("111122233", 0);
    hashTable.add("222244411", 1);
    hashTable.add("345345656", 2);
    hashTable.add("578674777", 3);
    hashTable.add("357362457", 4);
    hashTable.add("457636345", 5);
    hashTable.add("536646655", 6);
    hashTable.add("563645665", 7);
    hashTable.add("213112233", 8);

    hashTable.add("111122233", 10);

    cout << hashTable.del("357362457") << endl;
    cout << hashTable.del("999999999") << endl;
    cout << endl;

    hashTable.printTable(true, true);
    cout << endl;

    hashTable.add("357362457", 11);

    hashTable.printTable(true, true);

    cout << hashTable.get("536646655") << endl;
    cout << hashTable.get("999999999") << endl;
}

void testBinHashTable(){
    BinHashTable binHashTable("../bht.dat");

    binHashTable.add(PhoneUser{"111111111", "add1", "name1"});
    binHashTable.add(PhoneUser{"222222222", "add1", "name2"});
    binHashTable.add(PhoneUser{"333333333", "add1", "name3"});
    binHashTable.add(PhoneUser{"444444444", "add1", "name4"});

    printBinaryFile("../bht.dat");
    cout << endl;
    binHashTable.printTable();
    cout << endl;

    binHashTable.del("222222222");

    printBinaryFile("../bht.dat");
    cout << endl;
    binHashTable.printTable();
    cout << endl;

    PhoneUser phoneUser = binHashTable.get("111111111");
    cout << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl << endl;

    BinHashTable newBinHashTable("../bht.dat", false);
    binHashTable.printTable();
    cout << endl;

    convertTextToBinary("../records.txt", "../records.dat");

    binHashTable.addRecordFromFile("../records.dat", 2);

    printBinaryFile("../bht.dat");
    cout << endl;
    binHashTable.printTable();
    cout << endl;
}

void task1(){
    string binFilename;
    int command;
    bool createNewFile;
    char phone[10], address[50], name[50];
    PhoneUser phoneUser{};

    cout << "Enter binary file name:" << endl;
    cin >> binFilename;
    cout << "Do you want to rewrite or create new file? (1 or 0)" << endl;
    cin >> createNewFile;

    BinHashTable hashTable("../" + binFilename, createNewFile);

    while(true){
        cout << "Choose operation:" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - add record" << endl;
        cout << "2 - get record" << endl;
        cout << "3 - delete record" << endl;
        cout << "4 - print file" << endl;
        cout << "5 - print table" << endl;
        cin >> command;

        try {
            switch (command) {
                case 0:
                    return;
                case 1:
                    cout << "Enter phone:" << endl;
                    cin >> phone;
                    strcpy(phoneUser.phone, phone);
                    cout << "Enter adders:" << endl;
                    cin >> address;
                    strcpy(phoneUser.address, address);
                    cout << "Enter name:" << endl;
                    cin >> name;
                    strcpy(phoneUser.name, name);

                    hashTable.add(phoneUser);
                    break;
                case 2:
                    cout << "Enter phone:" << endl;
                    cin >> phone;

                    phoneUser = hashTable.get(phone);
                    cout << "Record is:" << endl;
                    cout << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl;
                    break;
                case 3:
                    cout << "Enter phone:" << endl;
                    cin >> phone;

                    hashTable.del(phone);
                    break;
                case 4:
                    cout << "File is:" << endl;
                    printBinaryFile("../" + binFilename);
                    break;
                case 5:
                    cout << "Table is:" << endl;
                    hashTable.printTable();
                    break;
                default:
                    cout << "There is no such a command" << endl;
                    break;
            }
        } catch (int errCode) {
            switch (errCode) {
                case -1:
                    cout << "Error in file opening" << endl;
                    break;
                case -2:
                    cout << "Error occurred while working with file" << endl;
                    break;
                case -3:
                    cout << "Trying to access non-existing element" << endl;
                    break;
                default:
                    return;
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Choose task 0 for testHashTable, 1 for testBinHashTable or 2 for task:" << endl;
    cin >> n;

    switch(n){
        case 0:
            testHashTable();
            break;
        case 1:
            testBinHashTable();
            break;
        case 2:
            task1();
            break;
        default:
            cout << "There is no such a task" << endl;
            break;
    }
}
