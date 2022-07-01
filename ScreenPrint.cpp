#include <iostream>
#include "SeaBattle.h"
using namespace std;


//печать правого поля
void PrintFieldRight(int i, PlayerModel& player);
//печать левого поля
void PrintFieldLeft(int i, PlayerModel& player);
//вывод предыдущих атак
void OutputOfAPreviousAttacks(PlayerModel& playerAtack, PlayerModel& playerTake);
//вывод на экран массивов полей с кораблями и атаками
void PrintFields(PlayerModel& player);
//вывод информации
void PrintInfo(PlayerModel& player1, PlayerModel& playerEnemy);

void OutputOnDisplay(PlayerModel& playerAtack, PlayerModel& playerTake)
{
	if (playerTake.NamePlayer != playerAtack.NamePlayer)
		PrintInfo(playerAtack, playerTake);

	PrintFields(playerAtack);
}



void PrintFields(PlayerModel& player)
{

	cout << endl;

	cout << "_______________________";
	cout << "\t\t_______________________";
	cout << endl;

	cout << "\t" << player.NamePlayer << " field \t";
	cout << "\t Enemy field \t";
	cout << "\t\t";

	cout << endl;

	cout << "/" << "/" << " ";

	for (int j = 0, q = true; j < SizeField; j++)
	{

		cout << HorizontalBoard_X[j] << " ";
		if (j + 1 == SizeField && q)
		{
			q = false;
			j = -1;
			cout << "\t\t";
			cout << "/" << "/" << " ";

		}
	}
	cout << endl;
	cout << "------------------------";
	cout << "\t------------------------";
	cout << endl;

	for (int i = 0; i < SizeField; i++)
	{

		PrintFieldLeft(i, player);

		cout << "\t";

		PrintFieldRight(i, player);

	}

	cout << "------------------------";
	cout << "\t------------------------";

}
void PrintFieldLeft(int i, PlayerModel& player)
{
	for (int j = 0; j < SizeField; j++)
	{
		if (j == 0)
		{
			cout << VertBoard_Y[i] << "|" << " ";

			char debugChar = player.PlayerFieldArray[i][j];
			if (player.PlayerFieldArray[i][j] >= 'd' && player.PlayerFieldArray[i][j] <= 'm')
			{
				cout << Ship_char << " ";
			}
			else
			{
				if (player.PlayerFieldArray[i][j] == Miss_char || player.PlayerFieldArray[i][j] == Hit_char)
					cout << player.PlayerFieldArray[i][j] << " ";
				else
					cout << FreePlace_char << " ";
			}
		}
		else
		{
			if (player.PlayerFieldArray[i][j] >= 'd' && player.PlayerFieldArray[i][j] <= 'm')
			{
				cout << Ship_char << " ";
			}
			else
			{
				if (player.PlayerFieldArray[i][j] == Miss_char || player.PlayerFieldArray[i][j] == Hit_char)
					cout << player.PlayerFieldArray[i][j] << " ";
				else
					cout << FreePlace_char << " ";
			}
		}
		if (j + 1 == SizeField)
		{
			cout << "|";
		}
	}

}

void PrintFieldRight(int i, PlayerModel& player)
{
	for (int j = 0; j < SizeField; j++)
	{
		if (j == 0)
		{
			cout << VertBoard_Y[i] << "|" << " ";

			if (player.ForPrintFieldArray[i][j] == Hit_char || player.ForPrintFieldArray[i][j] == Miss_char)
			{
				cout << player.ForPrintFieldArray[i][j] << " ";
			}
			else
			{
				cout << FreePlace_char << " ";
			}
		}
		else
		{
			if (player.ForPrintFieldArray[i][j] == Hit_char || player.ForPrintFieldArray[i][j] == Miss_char)
			{
				cout << player.ForPrintFieldArray[i][j] << " ";
			}
			else
			{
				cout << FreePlace_char << " ";
			}
		}
		if (j + 1 == SizeField)
		{
			cout << "|";
			cout << endl;
		}
	}
}


void PrintInfo(PlayerModel& playerAtack, PlayerModel& playerTake)
{
	ClearDispPrint();
	string playerName = playerAtack.IsMoveFirst ? playerAtack.NamePlayer : playerTake.NamePlayer;

	cout << endl;
	cout << "\tTurn " << playerName;
	cout << endl << endl;


	OutputOfAPreviousAttacks(playerAtack, playerTake);
	if (playerAtack.shipEnemyDestFlag)
	{
		cout << endl;
		CoutEnemyShipDestr();
		playerAtack.shipEnemyDestFlag = false;
	}
	if (playerAtack.shipYouDestFlag)
	{
		cout << endl;
		CoutYouShipDestr();
		playerAtack.shipYouDestFlag = false;
	}


	cout << endl;

	cout << "-------------------------: " << endl;
	cout << "Your ships: " << endl;
	cout << "\t Ship size 1 - " << playerAtack.cntShip1 << " pieces" << endl;
	cout << "\t Ship size 2 - " << playerAtack.cntShip2 << " pieces" << endl;
	cout << "\t Ship size 3 - " << playerAtack.cntShip3 << " pieces" << endl;
	cout << "\t Ship size 4 - " << playerAtack.cntShip4 << " pieces" << endl;
	cout << "-------------------------: " << endl;


	cout << "Enemy ships: " << endl;
	cout << "\t Ship size 1 - " << playerAtack.cntShip1Enemy << " pieces" << endl;
	cout << "\t Ship size 2 - " << playerAtack.cntShip2Enemy << " pieces" << endl;
	cout << "\t Ship size 3 - " << playerAtack.cntShip3Enemy << " pieces" << endl;
	cout << "\t Ship size 4 - " << playerAtack.cntShip4Enemy << " pieces" << endl;
	cout << "-------------------------: " << endl;

}


void OutputOfAPreviousAttacks(PlayerModel& playerAtack, PlayerModel& playerTake)
{
	if (playerAtack.LastShoot_X_Y[1] >= 0)
	{
		if (playerAtack.IsLastShotSuccessful)
		{
			CoutYouHit(); cout << " Coordinate: " << (char)(playerAtack.LastShoot_X_Y[1] + 65) << playerAtack.LastShoot_X_Y[0];
			cout << endl;

		}
		else
		{
			CoutYouMissed(); cout << " Coordinate: " << (char)(playerAtack.LastShoot_X_Y[1] + 65) << playerAtack.LastShoot_X_Y[0];
			cout << endl;
			if (playerTake.IsLastShotSuccessful)
			{
				CoutEnemyHit(); cout << " Coordinate: " << (char)(playerTake.LastShoot_X_Y[1] + 65) << playerTake.LastShoot_X_Y[0];
			}
			else
			{
				CoutEnemyMissed();  cout << " Coordinate: " << (char)(playerTake.LastShoot_X_Y[1] + 65) << playerTake.LastShoot_X_Y[0];
			}
			cout << endl;
		}
	}
}

//for debug
void PrintFieldRightD(int i, PlayerModel& player);
void PrintFieldLeftD(int i, PlayerModel& player);


void ScreenPrintDebug(PlayerModel& player)
{

	cout << endl;

	cout << "_______________________";
	cout << "\t\t_______________________";
	cout << endl;

	cout << "\t" << player.NamePlayer << " field \t";
	cout << "\t Enemy field \t";
	cout << "\t\t";

	cout << endl;

	cout << "/" << "/" << " ";

	for (int j = 0, q = true; j < SizeField; j++)
	{

		cout << HorizontalBoard_X[j] << " ";
		if (j + 1 == SizeField && q)
		{
			q = false;
			j = -1;
			cout << "\t\t";
			cout << "/" << "/" << " ";

		}
	}
	cout << endl;
	cout << "------------------------";
	cout << "\t------------------------";
	cout << endl;

	for (int i = 0; i < SizeField; i++)
	{

		PrintFieldLeftD(i, player);

		cout << "\t";

		PrintFieldRightD(i, player);

	}

	cout << "------------------------";
	cout << "\t------------------------";

}

void PrintFieldRightD(int i, PlayerModel& player)
{
	for (int j = 0; j < SizeField; j++)
	{
		if (j == 0)
		{
			cout << VertBoard_Y[i] << "|" << " ";
			cout << player.ForPrintFieldArray[i][j] << " ";
		}
		else
		{
			cout << player.ForPrintFieldArray[i][j] << " ";
		}
		if (j + 1 == SizeField)
		{
			cout << "|";
			cout << endl;
		}
	}
}

void PrintFieldLeftD(int i, PlayerModel& player)
{
	for (int j = 0; j < SizeField; j++)
	{
		if (j == 0)
		{
			cout << VertBoard_Y[i] << "|" << " ";
			cout << player.PlayerFieldArray[i][j] << " ";
		}
		else
		{
			cout << player.PlayerFieldArray[i][j] << " ";
		}
		if (j + 1 == SizeField)
		{
			cout << "|";
		}

	}
}


