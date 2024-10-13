#include "Keeper.h"

Keeper::Keeper()
{
	this->data = nullptr;
	this->size = 0;
}

Keeper::~Keeper()
{
	delete[] data;
}

int Keeper::getSize()
{
	return size;
}

void Keeper::add()
{
	int type; // Тип наследника
	try
	{
		cout << "Select a class: " << endl
			<< "[1] The submarine" << endl
			<< "[2] The sailboat" << endl
			<< "[3] The boat" << endl
			<< "Your choise: ";
		cin >> type;
		if (type > 3 || type < 1)
		{
			throw (string)"The wrong class is selected";
		}
		Ship** tmp = new Ship * [size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		switch (type)
		{
		case 1:
			tmp[size] = new Submarine;
			break;
		case 2:
			tmp[size] = new Sail;
			break;
		case 3:
			tmp[size] = new Boat;
			break;
		default:
			break;
		}
		if (tmp[size]->isError())
		{
			cout << "The item was not added" << endl;
			system("pause");
			return;
		}
		size++;
		if (data)
			delete[] data;
		data = tmp;
		cout << "The item has been added successfully" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}

void Keeper::add(int _type, ifstream &fin)
{
	Ship** tmp = new Ship * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = data[i];
	}
	switch (_type)
	{
	case 1:
		tmp[size] = new Submarine(fin);
		break;
	case 2:
		tmp[size] = new Sail(fin);
		break;
	case 3:
		tmp[size] = new Boat(fin);
		break;
	default:
		break;
	}
	size++;
	if (data)
		delete[] data;
	data = tmp;
}

void Keeper::edit()
{
	int index;
	if (!size)
	{
		cout << "[INFO] The container is empty!" << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i << "] ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "Submarine" << endl;
				break;
			case 2:
				cout << "Sailboat" << endl;
				break;
			case 3:
				cout << "Boat" << endl;
				break;
			default:
				break;
			}
		}
		cout << "Select the element to change: ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"The selected item does not exist";
		data[index]->edit();
		if (data[index]->isError())
		{
			cout << "The element has not been changed due to an error" << endl;
		}
		else
		{
			cout << "The item has been changed successfully" << endl;
		}
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}

void Keeper::del()
{
	int index;
	if (!size)
	{
		cout << "[INFO] The container is empty!" << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i << "] ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "Submarine" << endl;
				break;
			case 2:
				cout << "Sailboat" << endl;
				break;
			case 3:
				cout << "Boat" << endl;
				break;
			default:
				break;
			}
		}
		cout << "Select the item to delete: ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"The selected item does not exist";
		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "The item was deleted successfully" << endl;
			size--;
			system("pause");
			return;
		}
		Ship** tmp = new Ship * [size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (index == i)
				continue;
			tmp[j] = data[i];
		}
		delete[] data;
		data = tmp;
		size--;
		cout << "The item was deleted successfully" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}
void Keeper::save()
{
	ofstream fout("output.txt");
	for (int i = 0; i < size; i++)
	{
		data[i]->save(fout);
	}
	fout.close();
	cout << "The items have been successfully saved to a file" << endl;
	system("pause");
}

void Keeper::load()
{
	ifstream fin("output.txt");
	if(fin.fail())
	{
		cout << "The file is empty!" << endl;
		system("pause");
		return;
	}
	int type = 0;
	while (fin)
	{
		fin >> type;
		if (fin.peek() == -1)
		{
			break;
		}
		add(type, fin);
	}
	fin.close();
	cout << "The items were successfully loaded from the file" << endl;
	system("pause");
}
ostream& operator<<(ostream& out, Keeper& obj)
{
	if (!obj.size)
	{
		cout << "[INFO] The container is empty!" << endl;
		system("pause");
		return out;
	}
	for (int i = 0; i < obj.size; i++)
	{
		obj.data[i]->print(out);
	}
	system("pause");
	return out;
}