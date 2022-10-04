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

int main() {
    try {
    testBinHashTable();
    } catch (int i) {
        cout << i;
    }

    return 0;
}
