#include "BinHashTable.h"


BinHashTable::BinHashTable(string filename, bool createNewFile) {
    this->recordsCount = 0;
    this->filename = filename;

    if(createNewFile) {
        createFile(filename);
        return;
    }

    ifstream infile(filename, ios::binary);
    assertFileOpened(infile);

    PhoneUser phoneUser{};

    while(infile.read((char*)&phoneUser, sizeof(char) * 110)){
        HashTable::add(phoneUser.phone, this->recordsCount);
        this->recordsCount++;
    }

    assertFileErrors(infile);
    infile.close();
}

void BinHashTable::add(const PhoneUser &phoneUser) {
    int oldN = HashTable::get((char *) phoneUser.phone);

    if (oldN != -1) {
        rewriteRecord(this->filename, phoneUser, oldN);
        return;
    }

    HashTable::add((char *) phoneUser.phone, recordsCount);
    this->recordsCount++;
    appendRecord(this->filename, phoneUser);
}

void BinHashTable::del(char phone[10]) {
    int oldN = HashTable::del(phone);

    if(oldN == -1) throw -3;

    this->recordsCount--;
    PhoneUser lastRecord = getRecord(this->filename, recordsCount);
    deleteRecord(this->filename, oldN);
    HashTable::add(lastRecord.phone, oldN);
}

PhoneUser BinHashTable::get(char *phone) {
    int oldN = HashTable::get(phone);

    if(oldN == -1) throw -3;

    return getRecord(this->filename, oldN);
}
