#include "phoneBookUtil.h"

void assertFileOpened(const ifstream &file){
    if(file.is_open()) return;
    throw -1;
}

void assertFileOpened(const ofstream &file){
    if(file.is_open()) return;
    throw -1;
}

void assertFileOpened(const fstream &file){
    if(file.is_open()) return;
    throw -1;
}

void assertFileErrors(const ifstream &file){
    if(file.good() or file.eof()) return;
    throw -2;
}

void assertFileErrors(const ofstream &file){
    if(file.good() or file.eof()) return;
    throw -2;
}

void assertFileErrors(const fstream &file){
    if(file.good() or file.eof()) return;
    throw -2;
}

void createFile(const string &filename){
    ofstream file(filename);
    assertFileOpened(file);

    assertFileErrors(file);
    file.close();
}

void convertTextToBinary(const string& textFilename, const string& binFilename){
    ifstream infile(textFilename);
    assertFileOpened(infile);

    ofstream outfile(binFilename, ios::binary);
    assertFileOpened(outfile);

    PhoneUser phoneUser{};

    while(infile >> phoneUser.phone){
        infile >> phoneUser.address;
        infile >> phoneUser.name;

        outfile.write((char*)&phoneUser, sizeof(char) * 110);
    }

    assertFileErrors(infile);
    infile.close();

    assertFileErrors(outfile);
    outfile.close();
}

void convertBinaryToText(const string& binFilename, const string& textFilename){
    ifstream infile(binFilename, ios::binary);
    assertFileOpened(infile);

    ofstream outfile(textFilename);
    assertFileOpened(outfile);

    PhoneUser phoneUser{};

    while(infile.read((char*)&phoneUser, sizeof(char) * 110)){
        outfile << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl;
    }

    assertFileErrors(infile);
    infile.close();

    assertFileErrors(outfile);
    outfile.close();
}

void printBinaryFile(const string& filename){
    ifstream infile(filename, ios::binary);
    assertFileOpened(infile);

    PhoneUser phoneUser{};

    while(infile.read((char*)&phoneUser, sizeof(char) * 110)){
        cout << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl;
    }

    assertFileErrors(infile);
    infile.close();
}

PhoneUser getRecord(const string& filename, int n){
    ifstream infile(filename, ios::binary);
    assertFileOpened(infile);

    PhoneUser phoneUser{};

    infile.seekg(n * sizeof(char) * 110);

    infile.read((char*)&phoneUser, sizeof(char) * 110);

    assertFileErrors(infile);
    infile.close();

    return phoneUser;
}

void deleteRecord(const string& filename, int n){
    fstream file(filename, ios::binary | ios::in);
    assertFileOpened(file);

    vector<PhoneUser> users;

    PhoneUser record{};

    while(file.read((char*)&record, sizeof(char) * 110)) {
        users.push_back(record);
    }

    users[n] = record;

    assertFileErrors(file);
    file.close();

    file.open(filename, ios::binary | ios::out);
    assertFileOpened(file);

    for(int q = 0; q < users.size() - 1; q++)
        file.write((char*)&users[q], sizeof(char) * 110);

    assertFileErrors(file);
    file.close();
}

void appendRecord(const string& filename, const PhoneUser &phoneUser){
    fstream file(filename, ios::binary | ios::in | ios::out);
    assertFileOpened(file);

    file.seekg(0, ios::end);
    file.write((char*)&phoneUser, sizeof(char) * 110);

    assertFileErrors(file);
    file.close();
}

void rewriteRecord(const string& filename, const PhoneUser &phoneUser, int n){
    fstream file(filename, ios::binary | ios::in | ios::out);

    file.seekg(n * sizeof(char) * 110);
    file.write((char*)&phoneUser, sizeof(char) * 110);

    assertFileErrors(file);
    file.close();
}
