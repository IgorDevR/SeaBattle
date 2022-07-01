#include <string>
#include <iostream>
#include "SeaBattle.h"
using namespace std;



int inputInt(int m, int n, void (*func)())
{	
	while (true)
	{		
		func();

		int select = 0;
		if (((cin >> select).good() && (m <= select) && (select <= n)))
		{
			cin.clear();
			cin.sync();
			while (cin.get() != '\n');
			cout << endl;
			return select;
		}
		if (cin.fail())
		{			
			CoutErrorRetry();			
			cin.clear();
			cin.sync();
			while (cin.get() != '\n');
			cout << endl;
			continue;
		}	
		else
		{
			CoutErrorRetry();
			cin.clear();
			cin.sync();
			while (cin.get() != '\n');
			cout << endl;
			continue;
		}
	}
		
}

void inputString(array <int, 6>& coord, void (*func)())
{	
	while (true)
	{
		
		func();

		string enterUserStr;
		getline(cin, enterUserStr);

		if (enterUserStr == "")
		{
			CoutErrorRetry();
			cin.clear();
			cin.sync();
			//while (cin.get() != '\n');
			cout << endl;
			continue;
		}
		
		for (int i = 0; i < enterUserStr.size(); i++)
		{			
			coord[i] = enterUserStr[i];
		}
		cin.clear();
		cin.sync();
		//while (cin.get() != '\n');
		cout << endl;
		break;
	}
	
}

string inputString( void (*func)())
{
	while (true)
	{
	
	func();
	
		string enterUserStr;
		getline(cin, enterUserStr);

		if (enterUserStr == "")
		{
			CoutErrorRetry();
			cin.clear();
			cin.sync();
			while (cin.get() != '\n');
			cout << endl;
			continue;
		}

		cin.clear();
		cin.sync();
		//while (cin.get() != '\n');
		cout << endl;
		return  enterUserStr;
	}
}


