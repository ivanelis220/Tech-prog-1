#include "boat.h"

Boat::Boat()
{
	cout << "BOAT" <<endl;
	try
	{
		setType(3);
		cout << "Enter the hull material of the boat = ";
		cin.ignore(256, '\n');
		getline(cin, material);
		if(material == "")
			throw (string)"The material cannot be empty";
		cout << "Enter driving characteristics = ";
		getline(cin, _class);
		if (_class == "")
			throw (string)"Driving qualities cannot be empty";
		cout << "Enter the number of crew = ";
		cin >> this->people;
		if (this->people < 0)
		{
			throw (string)"The number of crew cannot be negative";
		}
		cout << "[1]Peaceful или [2]Military = ";
		cin >> this->destination;
		if (this->destination < 1 || this->destination > 2)
		{
			throw (string)"The wrong purpose of the sailboat";
		}
		cout << "Enter the speed of the sailboat = ";
		cin >> this->speed;
		if (this->speed < 0)
		{
			throw (string)"The speed cannot be negative";
		}
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Boat::Boat(ifstream& fin)
{
	setType(3);
	fin >> this->destination;
	fin.ignore(256, '\n');
	getline(fin, material);
	fin >> this->speed >> this->people;
	fin.ignore(256, '\n');
	getline(fin, _class);
}

Boat::~Boat()
{
	cout << "The destructor of the Boat class was called" << endl;
}

void Boat::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Select an option to change:" << endl
			<< "[1] The materials" << endl
			<< "[2] Driving qualities" << endl
			<< "[3] The crew" << endl
			<< "[4] The purpose" << endl
			<< "[5] The speed" << endl
			<< "Your choise: ";
		cin >> index;
		if (index < 1 || index > 6)
		{
			throw (string)"There is no parameter with this index";
		}
		cout << "The original value: ";
		switch (index)
		{
		case 1:
			cout << material << endl;
			cout << "The new value: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"The material can't be empty";
			material = sTmp;
			break;
		case 2:
			cout << _class << endl;
			cout << "The new value: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Driving qualities can't be empty";
			_class = sTmp;
			break;
		case 3:
			cout << people << endl;
			cout << "The new value: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"The amount of the crew can't be negative";
			}
			people = iTmp;
			break;
		case 4:
			if (destination == 1)
			{
				cout << "Peaceful" << endl;
			}
			else
			{
				cout << "<Military" << endl;
			}
			cout << "The new value [1/2]: ";
			cin >> iTmp;
			if (iTmp < 1 || iTmp > 2)
			{
				throw (string)"The purpose should be [1/2]";
			}
			destination = iTmp;
			break;
		case 5:
			cout << speed << endl;
			cout << "The new value: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"The speed can't be negative";
			}
			speed = iTmp;
			break;
		default:
			break;
		}
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

void Boat::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->destination << endl
		<< this->material << endl
		<< this->speed << endl
		<< this->people << endl
		<< this->_class << endl;
}

void Boat::print(ostream& out)
{
	out << "BOAT" << endl;
	if (this->destination == 1)
	{
		out << "The purpose : Peaceful" << endl;
	}
	else
	{
		out << "The purpose : Military" << endl;
	}
	out << "The material : " << this->material << endl
		<< "The speed : " << this->speed << endl
		<< "The crew : " << this->people << endl
		<< "Driving qualities : " << this->_class << endl;
}