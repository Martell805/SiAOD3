#ifndef SIAOD3_BINHASHTABLE_H
#define SIAOD3_BINHASHTABLE_H

#include "phoneBookUtil.h"
#include "HashTable.h"

using namespace std;

class BinHashTable: public HashTable {
protected:
    string filename;
    int recordsCount;
public:
    BinHashTable(const string& filename, bool createNewFile = true);
    void add(const PhoneUser &phoneUser);
    void del(char phone[10]);
    PhoneUser get(char phone[10]);
    void addRecordFromFile(const string& otherFilename, int n);
};


#endif //SIAOD3_BINHASHTABLE_H
