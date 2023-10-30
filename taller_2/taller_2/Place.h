#pragma once
#include <iostream>
using namespace std;

class Place {

public:

	Place(string nameNode, string name, bool state);
	~Place();

private:

	string nameNode;
	string name;
	bool state;


};
