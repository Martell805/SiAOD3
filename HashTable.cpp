#include "HashTable.h"

int HashTable::hashFunction(const char phone[10], int key) const {
    int hashResult = 0;

    for (int q = 0; q < 10; q++){
        hashResult = (key * hashResult + phone[q]) % this->bufferSize;
    }

    hashResult = (hashResult * 2 + 1) %  this->bufferSize;

    return hashResult;
}

int HashTable::hashFunction1(char phone[10]) const{
    return hashFunction(phone,  this->bufferSize - 1);
}

int HashTable::hashFunction2(char phone[10]) const{
    return hashFunction(phone,  this->bufferSize + 1);
}

HashTable::HashTable() {
    this->bufferSize = 8;
    this->size = 0;
    this->sizeAll = 0;
    this->arr.resize(bufferSize);
}

void HashTable::resize() {
    this->bufferSize *= 2;

    this->rehash();
}

void HashTable::rehash() {
    this->size = 0;
    this->sizeAll = 0;

    vector<HashElement*> newArr(bufferSize, nullptr);
    this->arr.swap(newArr);

    for(auto el: newArr){
        if(el && el->state){
            add(el->phone, el->n);
        }
    }
}

int HashTable::get(char phone[10]) {
    int pos = hashFunction1(phone);
    int step = hashFunction2(phone);
    int q = 0;

    while (this->arr[pos] != nullptr && q < bufferSize){
        if(strcmp(this->arr[pos]->phone, phone) == 0 && this->arr[pos]->state){
            return this->arr[pos]->n;
        }

        pos = (pos + step) % this->bufferSize;
        q++;
    }

    return -1;
}

int HashTable::del(char *phone) {
    int pos = hashFunction1(phone);
    int step = hashFunction2(phone);
    int q = 0;

    while (this->arr[pos] != nullptr && q < bufferSize){
        if(strcmp(this->arr[pos]->phone, phone) == 0 && this->arr[pos]->state){
            this->arr[pos]->state = false;
            this->size--;
            return this->arr[pos]->n;
        }

        pos = (pos + step) % this->bufferSize;
        q++;
    }

    return -1;
}

void HashTable::add(char phone[10], int n) {
    if(this->size + 1 > int(0.75 * this->bufferSize)){
        resize();
    } else if (this->sizeAll > 2 * size) {
        rehash();
    }

    int pos = hashFunction1(phone);
    int step = hashFunction2(phone);
    int q = 0;
    int firstDeleted = -1;

    while (this->arr[pos] != nullptr && q < bufferSize){
        if(strcmp(this->arr[pos]->phone, phone) == 0 && this->arr[pos]->state){
            this->arr[pos]->n = n;
            return;
        }

        if(!this->arr[pos]->state && firstDeleted == -1)
            firstDeleted = pos;

        pos = (pos + step) % this->bufferSize;
        q++;
    }

    if (firstDeleted == -1){
        this->arr[pos] = new HashElement(phone, n);
        this->sizeAll++;
    } else {
        strcpy(this->arr[firstDeleted]->phone, phone);
        this->arr[firstDeleted]->state = true;
        this->arr[firstDeleted]->n = n;
    }
    this->size++;
}

void HashTable::printTable(bool printEmptyElements, bool printDeletedElements){
    for(HashElement* el: this->arr){
        if(printEmptyElements && el == nullptr) cout << "Empty element" << endl;
        else if(printDeletedElements && el != nullptr && !el->state) cout << "Deleted element" << endl;
        else if(el != nullptr && el->state) cout << el->phone << " " << el->n << endl;
    }
}

int HashTable::getSize() const {
    return this->size;
}

