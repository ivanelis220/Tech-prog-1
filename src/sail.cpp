#include "sail.h"

Sail::Sail()
{
	cout << "SAILBOAT" << endl;
	try
	{
		setType(2);
		cout << "Enter the name of the sailboat = ";
		cin.ignore(256, '\n');
		getline(cin, name);
		if(name == "")
			throw (string)"The name can't be empty";
		cout << "Enter the type of the sailboat = ";
		getline(cin, typeSail);
		if (typeSail == "")
			throw (string)"The type can't be empty";
		cout << "Enter the amount of the crew = ";
		cin >> this->people;
		if (this->people < 0)
		{
			throw (string)"The amount of the crew can't be negative";
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
			throw (string)"The speed can't be negative";
		}
		cout << "Enter the length of the sailboat = ";
		cin >> this->_long;
		if (this->_long < 0)
		{
			throw (string)"The lenth can't be negative";
		}
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Sail::Sail(ifstream& fin)
{
	setType(2);
	fin.ignore(256, '\n');
	getline(fin, name);
	fin.ignore(256, '\n');
	getline(fin, typeSail);
	fin >> this->destination >> this->_long >> this->speed >> this->people;
}

Sail::~Sail()
{
	cout << "The destructor of the Sail class was called" << endl;
	system("pause");
}

void Sail::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Select an option to change:" << endl
			<< "[1] The name" << endl
			<< "[2] The type" << endl
			<< "[3] The crew" << endl
			<< "[4] The purpose" << endl
			<< "[5] The speed" << endl
			<< "[6] The length" << endl
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
			cout << name << endl;
			cout << "The new value: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"The name can't be empty";
			name = sTmp;
			break;
		case 2:
			cout << typeSail << endl;
			cout << "The new value: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"The type can't be empty";
			typeSail = sTmp;
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
				cout << "Military" << endl;
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
		case 6:
			cout << _long << endl;
			cout << "The new value: ";
			cin >> iTmp;
			if (!iTmp || iTmp < 0)
			{
				throw (string)"The length can't be negative";
			}
			_long = iTmp;
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

void Sail::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->name << endl
		<< this->typeSail << endl
		<< this->destination << endl
		<< this->_long << endl
		<< this->speed << endl
		<< this->people << endl;
}

void Sail::print(ostream& out)
{
	out << "SAILBOAT" << endl
		<< "The name : " << this->name << endl
		<< "The type : " << this->typeSail << endl;
		if (this->destination == 1)
		{
			out << "The purpose : Peaceful" << endl;
		}
		else
		{
			out << "he purpose : Military" << endl;
		}
		out << "The length : " << this->_long << endl
		<< "The speed : " << this->speed << endl
		<< "The crew : " << this->people << endl;
}