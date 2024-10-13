#pragma once
#include "ship.h"

class Submarine : public Ship
{
	int length;
	int wigth;
	int people;
	int time;
	int speed;
	string arms;
public:
	Submarine();
	Submarine(ifstream &fin);
	~Submarine();
	void edit();
	void save(ofstream& fout);
	void print(ostream& out);
};