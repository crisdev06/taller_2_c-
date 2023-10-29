#pragma once
#include<string>
#include<list>
#include "AdyacencyMatrix.h"
using namespace std;

class ReadFileAventura {
public:
    ReadFileAventura(string& name);
    list<AdyacencyMatrix> read();
    string trimCpp(const string& line);
private:
    string name;
    std::list<AdyacencyMatrix> adyMatrix;
};