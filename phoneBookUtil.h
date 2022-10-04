#ifndef SIADO2_PHONEBOOKUTIL_H
#define SIADO2_PHONEBOOKUTIL_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

struct PhoneUser{
    char phone[10];
    char address[50];
    char name[50];
};

void assertFileOpened(const ifstream &file);
void assertFileOpened(const ofstream &file);
void assertFileOpened(const fstream &file);
void assertFileErrors(const ifstream &file);
void assertFileErrors(const ofstream &file);
void assertFileErrors(const fstream &file);

void createFile(const string &filename);
void convertTextToBinary(const string& textFilename, const string& binFilename);
void convertBinaryToText(const string& binFilename, const string& textFilename);
void printBinaryFile(const string& filename);
PhoneUser getRecord(const string& filename, int n);
void deleteRecord(const string& filename, int n);
void appendRecord(const string& filename, const PhoneUser &phoneUser);
void rewriteRecord(const string& filename, const PhoneUser &phoneUser, int n);

#endif //SIADO2_PHONEBOOKUTIL_H
