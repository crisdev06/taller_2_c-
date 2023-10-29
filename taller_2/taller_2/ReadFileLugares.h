#pragma once
#include <string>
#include <List>
#include <stdexcept> 
using namespace std;

class ReadFileLugares {
public:
    ReadFileLugares(string& name);
    list<Place> read();
private:
    string name;
    std::list<Place> places;
};
