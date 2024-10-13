#include <iostream>
#include "Keeper.h"
#include "windows.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Keeper Konten;
	int menu;
	do
	{
		system("cls");
		cout << "Number of items in the container : [" << Konten.getSize() << "]" << endl
			<< "[1] Add item" << endl
			<< "[2] Delete item" << endl
			<< "[3] Save data in file" << endl
			<< "[4] Download data from a file" << endl
			<< "[5] Change the item data" << endl
			<< "[6] Output data from the container" << endl
			<< "[0] Exit" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
			Konten.add();
			break;
		case 2:
			Konten.del();
			break;
		case 3:
			Konten.save();
			break;
		case 4:
			Konten.load();
			break;
		case 5:
			Konten.edit();
			break;
		case 6:
			cout << Konten;
			break;
		case 0:
			return 0;
		default:
			break;
		}
	} while (true);
}