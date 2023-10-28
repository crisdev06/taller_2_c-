#pragma once
#include<string>
using namespace std;

class ReadFileAventura {
public:
    ReadFileAventura(string& name);
    bool read();
    string trimCpp(const string& line);
private:
    string name;
};