#pragma once
#include <string>
using namespace std;

class ReadFileAventura {
public:
    ReadFileAventura(string& name);
    bool read();
private:
    string name;
};