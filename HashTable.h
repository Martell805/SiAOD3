#ifndef SIAOD3_HASHTABLE_H
#define SIAOD3_HASHTABLE_H

#include "vector"
#include "iostream"
#include "phoneBookUtil.h"

using namespace std;

struct HashElement{
public:
    char phone[10]{};
    bool state;
    int n;

    HashElement(char phone_[10], int n_) {
        strcpy(this->phone, phone_);
        this->state = true;
        this->n = n_;
    }
};

class HashTable {
protected:
    int size;
    int bufferSize;
    int sizeAll;
    vector<HashElement*> arr;

public:
    int hashFunction(const char phone[10], int key) const;
    int hashFunction1(char phone[10]) const;
    int hashFunction2(char phone[10]) const;
public:
    HashTable();
    void resize();
    void rehash();

    int get(char phone[10]);
    int del(char phone[10]);
    void add(char phone[10], int n);

    void printTable(bool printEmptyElements = false, bool printDeletedElements = false);
    int getSize() const;
};


#endif //SIAOD3_HASHTABLE_H
