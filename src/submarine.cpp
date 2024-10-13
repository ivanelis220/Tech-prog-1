#include "submarine.h"

Submarine::Submarine()
{
	cout << "SUBMARINE" << endl;
	try
	{
		setType(1);
		cout << "Enter the length of the submarine = ";
		cin >> this->length;
		if (!this->length || this->length < 0)
		{
			throw (string)"The length of the submarine is zero or negative";
		}
		cout << "Enter the width of the submarine = ";
		cin >> this->wigth;
		if (!this->wigth || this->wigth < 0)
		{
			throw (string)"The width of the submarine is zero or negative";
		}
		cout << "Enter the amount of crew = ";
		cin >> this->people;
		if (this->people < 0)
		{
			throw (string)"The amount of crew is zero or negative";
		}
		cout << "Enter the amount of time spent underwater = ";
		cin >> this->time;
		if (this->time < 0)
		{
			throw (string)"Time can't be negative";
		}
		cout << "Enter the speed of the submarine = ";
		cin >> this->speed;
		if (this->speed < 0)
		{
			throw (string)"Speed cannot be negative";
		}
		cin.ignore(256, '\n');
		cout << "Enter the boat's armament : ";
		getline(cin, this->arms);
		if(arms == "")
			throw (string)"The armament can't be empty";
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Submarine::Submarine(ifstream& fin)
{
	setType(1);
	fin >> this->length  >> this->wigth >> this->people >> this->speed >> this->time;
	fin.ignore(256, '\n');
	getline(fin, arms);
}

Submarine::~Submarine()
{
	cout << "The destructor of the submarine class was called" << endl;
	system("pause");
}

void Submarine::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Select an option to change:" << endl
			<< "[1] Length" << endl
			<< "[2] Width" << endl
			<< "[3] Crew" << endl
			<< "[4] Speed" << endl
			<< "[5] Time underwater" << endl
			<< "[6] Armament" << endl
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
			cout << length << endl;
			cout << "New value: ";
			cin >> iTmp;
			if (!iTmp || iTmp < 0)
			{
				throw (string)"The length of the submarine is zero or negative";
			}
			length = iTmp;
			break;
		case 2:
			cout << wigth << endl;
			cout << "New value: ";
			cin >> iTmp;
			if (!iTmp || iTmp < 0)
			{
				throw (string)"The width of the submarine is zero or negative";
			}
			wigth = iTmp;
			break;
		case 3:
			cout << people << endl;
			cout << "New value: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"The amount of crew is zero or negative";
			}
			people = iTmp;
			break;
		case 4:
			cout << speed << endl;
			cout << "New value: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"The speed can't be negative";
			}
			speed = iTmp;
			break;
		case 5:
			cout << time << endl;
			cout << "New value: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"The time can't be negative";
			}
			time = iTmp;
			break;
		case 6:
			cout << arms << endl;
			cout << "New value: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if(sTmp == "")
				throw (string)"The armament can't be empty";
			arms = sTmp;
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

void Submarine::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->length << endl
		<< this->wigth << endl
		<< this->people << endl
		<< this->speed << endl
		<< this->time << endl
		<< this->arms << endl;
}

void Submarine::print(ostream& out)
{
	out << "SUBMARINE" << endl
		<< "The length : " << length << endl
		<< "The width : " << wigth << endl
		<< "The crew : " << people << endl
		<< "The underwater time : " << time << endl
		<< "The speed : " << speed << endl
		<< "The armament : " << arms << endl;
}