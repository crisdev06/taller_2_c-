#pragma once
#include <string>
#include <List>
#include <stdexcept> 
#include "Place.h"
using namespace std;

class ReadFileLugares {
public:
    ReadFileLugares(string& name);
    list<Place> read();
private:
    string name;
    std::list<Place> places;
};
