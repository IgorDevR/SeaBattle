#pragma once
#include "CoutText.h"
#include "PlayerModel.h"
#include "GetGameSettings.h"
#include "System.h"
#include <string>
using namespace std;


enum class CharCellTypeEnum
{
	None,
	Miss_ = '*', // *
	Hit_ = 'X', // x
	ReservedPlace_ = '.', // /
	FreePlace_ = 196, // .
	Ship_ = 254,

};

char static const Miss_char = (char)CharCellTypeEnum::Miss_;
char static const Hit_char = (char)CharCellTypeEnum::Hit_;
char static const FreePlace_char = (char)CharCellTypeEnum::FreePlace_;
char static const ReservedPlace_char = (char)CharCellTypeEnum::ReservedPlace_;
char static const Ship_char = (char)CharCellTypeEnum::Ship_;

 

//цикл для резервирования места  вокруг корабля для метода ReservedPlace
void ReservedPlaceAxis_(array <array<char, SizeField>, SizeField>& arrayP, array<int, 6>& coord, int size, char charCell);

//выстрел по координатам
void ShotFor_X_Y(PlayerModel& player, int x, int y);

/// ввод координат для выстрела или растановки кораблей
void RequestInputOfCoordinates(PlayerModel& player, int cntCoord, void (*func)());

//проверка и конвертация координат
bool  ManualCoordAndCheck(PlayerModel& player, array<int, 6>& coord, int cntCoordin);
//проверка на то что рядом нет корабля и есть место для установки
bool NotNearCheck(PlayerModel& player, array<int, 6>& coord);
//резервируем место вокруг корабля для облегчения дальнейшей установки и после уничтожения
void ReservedPlace( array <array<char, SizeField>, SizeField>& arrayP, array<int, 6>& coord, int x, int y, string axis, char charCell);
//проверка ячейки на свободное место
bool IsCellFreePlaceCheck(PlayerModel& player, int x, int y);
//проверка на выход за границы массива
bool IsInsideAnArrayCheck(int nextX, int nextY);


//очистка текста на консоли(заполнение пустимы символами)
void ClearDispPrint();
//вывод информации и игры на экран
void OutputOnDisplay(PlayerModel& playerAtack, PlayerModel& playerTake);
//вывод процесса растановки кораблей и резервирование мета под них для отладки
void ScreenPrintDebug(PlayerModel& player);


//воод с клавиатуры цифр
int inputInt(int m, int n, void (*func)());
//ввод с клавиатуры строки
void inputString(array <int, 6>& coord, void (*func)());
string inputString(void (*func)());
