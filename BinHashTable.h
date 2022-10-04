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
    BinHashTable(string filename, bool createNewFile = true);
    void add(const PhoneUser &phoneUser);
    void del(char phone[10]);
    PhoneUser get(char phone[10]);
};


#endif //SIAOD3_BINHASHTABLE_H
