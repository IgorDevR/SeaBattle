#include "SeaBattle.h"
#include <chrono>


//индекс ячейки для массива модели корабля
int indexCell = 0;

static int cntIter = 0;
static int cntIter2 = 0;

//разделением по осям для для метода ReservedPlaceAxis_ и вызов метода InstallingShipAxis_ для установки по координатам
void SetupShip(PlayerModel& player, array<int, 6> coord, int size, ShipsEnum shipsEnum);

//запись координат кораблей в поле игрока и запись в модель кораблей координат для дальнейшей статистики
void IstallShip(PlayerModel& player, int size, int x, int y, ShipsEnum shipsEnum, int iteratorForArrShip);
//цикл записи координат для метода IstallShip
void InstallingShipAxis_(PlayerModel& player, array<int, 6> coord, int size, ShipsEnum shipsEnum);



//проверка на то что рядом нет корабля и есть место для установки
//bool NotNear(PlayerModel& player);
//двигаем координаты от начальных к конечным в выбранную сторону
void SideMoveCoord(int side, array<int, 6>& coord, int size);

bool AutoCoordAndCheck(PlayerModel& player, array<int, 6>& coord, int size);


//Префиксный инкремент.
ShipsEnum& operator-(ShipsEnum& m, int num)
{
	m = static_cast<ShipsEnum>(static_cast<int>(m) - num);
	return m;
}
//проверка надлину выбранного корабля для ручной установки
bool CorrectLengthShipInstallCheck(array<int, 6>& coordInt, int cntCoord);
//проверка. формат введеных координат - первая буква и цифра в верном диапазоне, пробел и снова одна буква и цифра
bool CheckingForCorrectInput(array<int, 6>& coord, int cntCoord);

void ManualInstall(PlayerModel& player)
{
	int size = 4;
	int cntShip = 5 - size;
	int cntForPercent = 0;
	auto shipsEnum = ShipsEnum::ship4_1;

	
	while (true)
	{
		array<int, 6> coord;
		ClearDispPrint();
		OutputOnDisplay(player, player);
		IstallShipsText(player, size);
		RequestInputOfCoordinates(player, size, CoutEnterCoordInstallShip2_3_4);
		coord[0] = player.CoordinatesEnteredByUser[0];
		coord[1] = player.CoordinatesEnteredByUser[1];
		coord[2] = player.CoordinatesEnteredByUser[2];
		coord[3] = player.CoordinatesEnteredByUser[3];
		coord[4] = player.CoordinatesEnteredByUser[4];

		/*if (!ManualCoordAndCheck(player, coord, size))
		{
			CoutPressEnterContinue();
			continue;
		}*/
		if (!CorrectLengthShipInstallCheck(coord, size))
		{
			CoutNotCorrectlength();
			CoutPressEnterContinue();
			continue;
		}
		if (!NotNearCheck(player, coord))
		{
			CoutShipAreNearby();
			CoutPressEnterContinue();
			continue;
		}

		//установка точек вокруг корабля и установка корабля
		SetupShip(player, coord, size, shipsEnum);

		indexCell++;
		cntShip--;
		shipsEnum = operator-(shipsEnum, 1);
		if (cntShip == 0)
		{
			indexCell = 0;
			size--;
			cntShip = 5 - size;

		}
		if (size == 0)
		{
			ClearDispPrint();
			cout << endl << "Install complete";
			OutputOnDisplay(player, player);
			cout << endl;
			CoutPressEnterContinue();
			break;
		}
	
	}
}
void AutoInstall(PlayerModel& player)
{
	int size = 4;
	int cntShip = 5 - size;
	int cntForPercent = 0;
	auto shipsEnum = ShipsEnum::ship4_1;
	array<int, 6> coord;
	auto start = chrono::high_resolution_clock::now();
	while (true)
	{		
			coord[0] = coord[1] = coord[3] = coord[4] = 0;
			//задаем стартовые координаты
			srand(time(NULL));
			int side = rand() % 4 + 1;//1 - right; 2 - left; 3 - down; 4 - up 
			//int side = sideTmp < 3 ? 1 : 3;
			coord[0] = coord[3] = rand() % 10;
			coord[1] = coord[4] = rand() % 10;

			//заполняем конечные координаты
			SideMoveCoord(side, coord, size);

			if(!AutoCoordAndCheck( player, coord,  size))
				continue;

		//установка точек вокруг корабля и установка корабля
		SetupShip(player, coord, size, shipsEnum);

		indexCell++;
		cntShip--;
		shipsEnum = operator-(shipsEnum, 1);
		if (cntShip == 0)
		{
			indexCell = 0;
			size--;
			cntShip = 5 - size;

		}
		if (size == 0 )
		{
			cout << "Installation in progress. Wait.... " << "100" << "%" << endl;
			ClearDispPrint();
			cout << "Install complete";
			OutputOnDisplay(player, player);
			break;
		}		
			cntForPercent++;
			int percent = cntForPercent == 1 ? 10 : cntForPercent == 2 ? 20 : cntForPercent == 3 ? 30 : cntForPercent == 4 ? 40 : cntForPercent == 5 ? 50 :
				cntForPercent == 6 ? 60 : cntForPercent == 7 ? 70 : cntForPercent == 8 ? 80 : cntForPercent == 9 ? 90 : 100;

			cout << endl;
			cout << "Installation in progress. Wait.... " << percent << "%";
		
		
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration < float>duration = end - start;
	cout << endl;
	cout << "Time generation: " << duration.count() << "s";
}

void SetupShip(PlayerModel& player, array<int, 6> coord, int size, ShipsEnum shipsEnum)
{
	//движемлся резервируем место вокруг корабля по Y
	if (coord[0] == coord[3])
	{
		ReservedPlaceAxis_(player.PlayerFieldArray, coord, size, ReservedPlace_char);
	}
	//движемлся резервируем место вокруг корабля по X
	else if (coord[1] == coord[4])
	{
		ReservedPlaceAxis_(player.PlayerFieldArray, coord, size, ReservedPlace_char);
	}
	//идем в установку корабля
	InstallingShipAxis_(player, coord, size, shipsEnum);
}


void InstallingShipAxis_(PlayerModel& player, array<int, 6> coord, int size, ShipsEnum shipsEnum)
{
	if (size == 4)
		player.cntShip4++;
	if (size == 3)
		player.cntShip3++;
	if (size == 2)
		player.cntShip2++;
	if (size == 1)
		player.cntShip1++;



	int startX = coord[0];
	int endX = coord[3];
	int startY = coord[1];
	int endY = coord[4];

	int iteratorForArrShip = 0;
	for (int i = 0; i < size; i++)
	{
		//запись кораля по координатым в поле и в модель корабля
		IstallShip(player, size, startX, startY, shipsEnum, iteratorForArrShip);

		if (startX != endX)
		{
			startX++;
		}
		if (startY != endY)
		{
			startY++;
		}

		iteratorForArrShip++;

	}


}

void IstallShip(PlayerModel& player, int size, int x, int y, ShipsEnum shipsEnum, int iteratorForArrShip)
{
	//size - размер корабля
	if (size == 4)
	{
		player.PlayerFieldArray[x][y] = (char)shipsEnum;
		player.shipsPlayer.arrShips4[indexCell].arrShip4[iteratorForArrShip][0] = x;
		player.shipsPlayer.arrShips4[indexCell].arrShip4[iteratorForArrShip][1] = y;

	}
	else if (size == 3)
	{
		player.PlayerFieldArray[x][y] = (char)shipsEnum;
		player.shipsPlayer.arrShips3[indexCell].arrShip3[iteratorForArrShip][0] = x;
		player.shipsPlayer.arrShips3[indexCell].arrShip3[iteratorForArrShip][1] = y;
	}
	else if (size == 2)
	{
		player.PlayerFieldArray[x][y] = (char)shipsEnum;
		player.shipsPlayer.arrShips2[indexCell].arrShip2[iteratorForArrShip][0] = x;
		player.shipsPlayer.arrShips2[indexCell].arrShip2[iteratorForArrShip][1] = y;
	}
	else if (size == 1)
	{
		player.PlayerFieldArray[x][y] = (char)shipsEnum;
		player.shipsPlayer.arrShips1[indexCell].arrShip1[iteratorForArrShip][0] = x;
		player.shipsPlayer.arrShips1[indexCell].arrShip1[iteratorForArrShip][1] = y;
	}
}

void ReservedPlaceAxis_(array <array<char, SizeField>, SizeField>& arrayP, array<int, 6>& coord, int size, char charCell)
{

	int startX = coord[0];	int endX = coord[3];	int startY = coord[1];	int endY = coord[4];

	string axis;
	if (startX == endX)
		axis = "Y";
	if (startY == endY)
		axis = "X";	


	for (int i = 0; i < size; i++)
	{
		ReservedPlace(arrayP, coord, startX, startY, axis, charCell);

		if (startX != endX)
			startX++;

		if (startY != endY)
			startY++;
	}
}



void ReservedPlace(array <array<char, SizeField>, SizeField>& arrayP, array<int, 6> &coord, int x, int y, string axis, char charCell)
{
	bool ruleX_minus_1 = x - 1 >= 0;
	bool ruleY_minus_1 = y - 1 >= 0;
	bool ruleX_plus_1 = x + 1 < SizeField;
	bool ruleY_plus_1 = y + 1 < SizeField;

	int x_minus_1 = x - 1;
	int y_minus_1 = y - 1;
	int x_plus_1 = x + 1;
	int y_plus_1 = y + 1;

	if (axis == "Y")
	{
		if (y == coord[1] && ruleY_minus_1)//заполняем край слева и диагональ верх низ
		{
			arrayP[x][y_minus_1] = charCell;


			if (ruleX_minus_1)
			{
				arrayP[x_minus_1][y_minus_1] = charCell;
			}


			if (ruleX_plus_1)
			{
				arrayP[x_plus_1][y_minus_1] = charCell;
			}

		}

		if (y == coord[4] && ruleY_plus_1)//заполняем край справа и диагональ верх низ
		{
			arrayP[x][y_plus_1] = charCell;


			if (ruleX_minus_1)
			{
				arrayP[x_minus_1][y_plus_1] = charCell;
			}

			if (ruleX_plus_1)
			{
				arrayP[x_plus_1][y_plus_1] = charCell;
			}
		}

		if (ruleX_minus_1)//заполняем по движению выше
		{
			arrayP[x_minus_1][y] = charCell;

		}
		if (ruleX_plus_1)//заполняем по движению ниже
		{
			arrayP[x_plus_1][y] = charCell;

		}

	}
	else if (axis == "X")
	{
		if (x == coord[0] && ruleX_minus_1)//заполняем край верх и диагональ слева справа
		{
			arrayP[x_minus_1][y] = charCell;


			if (ruleY_minus_1)
			{
				arrayP[x_minus_1][y_minus_1] = charCell;
			}

			if (ruleY_plus_1)
			{
				arrayP[x_minus_1][y_plus_1] = charCell;
			}
		}

		if (x == coord[3] && ruleX_plus_1)//заполняем край низ и диагональ слева справа
		{
			arrayP[x_plus_1][y] = charCell;


			if (ruleY_minus_1)
			{
				arrayP[x_plus_1][y_minus_1] = charCell;
			}

			if (ruleY_plus_1)
			{
				arrayP[x_plus_1][y_plus_1] = charCell;
			}


		}

		if (ruleY_minus_1)//заполняем по движению левее
		{
			arrayP[x][y_minus_1] = charCell;

		}
		if (ruleY_plus_1)//заполняем по движению правее
		{
			arrayP[x][y_plus_1] = charCell;

		}

	}

}

void SideMoveCoord(int side, array<int, 6>& coord, int size)
{
	//смещаем координаты старт в указаную сторону на величину size
	size = size - 1;

	if (side == 1)
		coord[4] = coord[1] + size;
	else if (side == 2)
		coord[4] = coord[1] - size;
	else if (side == 3)
		coord[3] = coord[0] + size;
	else if (side == 4)
		coord[3] = coord[0] - size;
}

