#include "SeaBattle.h"

//конвертер координат из char в int 
void ConverterCoord(array<int, 6>& coord, int cntCoord);
//сортировка координат от меньшего в [0][1] к большему в [3][4] 
void SortCoordinates(array<int, 6>& coordInt);

bool CorrectLengthShipInstallCheck(array<int, 6>& coordInt, int cntCoord)
{

	if (cntCoord >= 2)
	{
		int size1 = abs(coordInt[0] - coordInt[3]);
		int size2 = abs(coordInt[1] - coordInt[4]);

		if (size1 > 0 && size2 > 0)
			return false;

		if (size1 != 0 && size1 != cntCoord - 1)
		{
			return false;
		}
		if (size2 != 0 && size2 != cntCoord - 1)
		{
			return false;
		}
	}
	return true;
}
bool CheckingForCorrectInput(array<int, 6>& coord, int cntCoord)
{
	coord[0] = toupper(coord[0]);
	coord[3] = toupper(coord[3]);
	bool correct1SymborEnter = false;
	bool correct2SymborEnter = false;
	bool correct3SymborEnter = false;
	bool correct4SymborEnter = false;
	bool correctSpaceSeparatorSymborEnter = false;

	char tmp = coord[0];
	coord[0] = coord[1];
	coord[1] = tmp;
	if (cntCoord >= 2)
	{
		tmp = coord[3];
		coord[3] = coord[4];
		coord[4] = tmp;
	}

	for (int i = 0; i < SizeField; i++)
	{
		if ((coord[0] == VertBoard_Y[i]))
		{
			correct1SymborEnter = true;
		}
		if ((coord[1] == HorizontalBoard_X[i]))
		{
			correct2SymborEnter = true;
		}
		if (cntCoord >= 2)
		{
			if ((coord[2] == ' '))
			{
				correctSpaceSeparatorSymborEnter = true;
			}
			if ((coord[3] == VertBoard_Y[i]))
			{
				correct3SymborEnter = true;
			}
			if ((coord[4] == HorizontalBoard_X[i]))
			{
				correct4SymborEnter = true;
			}
		}
	}
	if (correct1SymborEnter == false || correct2SymborEnter == false)
	{
		return false;
	}

	if (cntCoord >= 2 && (correctSpaceSeparatorSymborEnter == false || correct3SymborEnter == false || correct4SymborEnter == false))
	{
		return false;
	}

	return true;

}

bool NotNearCheck(PlayerModel& player, array<int, 6>& coord)
{
	int X1 = coord[0];
	int Y1 = coord[1];
	int X2 = coord[3];
	int Y2 = coord[4];

	//проверяем на свободное место
	for (int x = X1; x <= X2; x++)
	{
		for (int y = Y1; y <= Y2; y++)
		{
			if (player.PlayerFieldArray[x][y] != FreePlace_char)
				return false;
		}
	}
	return true;
}

bool IsInsideAnArrayCheck(int nextX, int nextY)
{

	if (nextX >= 10 || nextX < 0)
		return false;

	if (nextY >= 10 || nextY < 0)
		return false;

	return true;
}

bool ManualCoordAndCheck(PlayerModel& player, array<int, 6>& coord, int size)
{
	if (!CheckingForCorrectInput(coord, size))
	{
		CoutNotCorrectInput();
		CoutPressEnterContinue();
		return false;
	}
	ConverterCoord(coord, size);

	if (size >= 2)
	{
		SortCoordinates(coord);
	}

	if (!IsInsideAnArrayCheck(coord[0], coord[1]) ||
		(size >= 2 && !IsInsideAnArrayCheck(coord[3], coord[4])))
	{
		CoutExitingForField();
		CoutPressEnterContinue();
		return false;
	}



	return true;
}
bool AutoCoordAndCheck(PlayerModel& player, array<int, 6>& coord, int size)
{

	//сортировка(для того что бы менишие значения координат всегда были слева и были точной отсчета
	SortCoordinates(coord);

	//проверить на выход за границы начало и конец
	if (!IsInsideAnArrayCheck(coord[0], coord[1]) || !IsInsideAnArrayCheck(coord[3], coord[4]))
	{
		return false;
	}
	//проверка на свободное место
	if (!NotNearCheck(player, coord))//NotNear(player);
	{
		return false;
	}
	return true;
}

void SortCoordinates(array<int, 6>& coordInt)
{
	int X1 = min(coordInt[0], coordInt[3]);//0 1_3 4
	int Y1 = min(coordInt[1], coordInt[4]);
	int X2 = max(coordInt[0], coordInt[3]);
	int Y2 = max(coordInt[1], coordInt[4]);

	coordInt[0] = X1;
	coordInt[1] = Y1;
	coordInt[3] = X2;
	coordInt[4] = Y2;


}

void ConverterCoord(array<int, 6>& coord, int cntCoord)
{
	coord[0] = coord[0] - 48;
	coord[1] = coord[1] - 65;
	coord[3] = coord[3] - 48;
	coord[4] = coord[4] - 65;

	if (cntCoord == 1)
	{
		coord[3] = coord[0];
		coord[4] = coord[1];
	}

}