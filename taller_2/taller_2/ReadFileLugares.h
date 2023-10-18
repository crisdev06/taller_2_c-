#pragma once
#include <string>
using namespace std;

class ReadFileLugares {
public:
    ReadFileLugares(string& name);
    bool read();
private:
    string name;
};
