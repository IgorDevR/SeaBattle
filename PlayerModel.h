#pragma once
#include <vector>
#include <array>
#include <iostream>
#include "ShipsModel.h"
using namespace std;

#pragma region Field
//размер поля вместе с клетками разметки (Models.)
int const SizeField = 10;
//горизонтальная разметка
const array<char, SizeField  > HorizontalBoard_X = { 'A','B','C','D','E','F','G','H','I','J' };
//разметка - точки
const array<char, SizeField  > DotArrayUS = { '.','.','.','.','.','.','.','.','.','.' };
//вертикальная разметка
const array<char, SizeField  > VertBoard_Y = { '0','1','2','3','4','5','6','7','8','9' };
//номер игрока
static int ID = 0;


/// <summary>
///модель игрока
/// </summary>
class PlayerModel
{
public:

	//useAutoInstallShipsMode автостанока ? /useStrategyForPcMode по стратегии?/ isThisPlayerUser_First этот игрок пользователь?/ isFirstMove этот игрок ходит первым?
	PlayerModel(bool useAutoInstallShipsMode, bool useStrategyForPcMode, bool isThisPlayerUser_First, bool isFirstMove);

	//имя игрока
	string NamePlayer;

	//этот игрок пользователь?  
	bool IsThisPlayerUser;
	///Поле с разметкой и кораблями игрока
	array<array<char, SizeField >, SizeField> PlayerFieldArray;
	///Поле с разметкой и кораблями противника(скрыто, нужно для точго что бы знать расположение кораблей врага при атаке)
	array<array<char, SizeField >, SizeField> EnemyFieldArray;
	///Поле с разметкой и кораблями для вывода на экран
	array<array<char, SizeField >, SizeField> ForPrintFieldArray;

	//координаты введеные пользователем Ячейки: 0 - X1, 1 - Y1, 2 - X2, 3 - Y2. X2 и Y2 используются при ручной кстановке    
	array<int, 6>CoordinatesEnteredByUser;
	// координаты последнего успешного выстрела
	array<int, 2>  LastShotSuccessfulCoordArr;
	//Полседний выстрел 
	array<int, 2>  LastShoot_X_Y;
	// последний выстрел по стратегии    
	array<int, 2> LastShotOnStrategy_X_Y;
	//Кодинаты первого попадания по тактике
	array<int, 2>  FirstShotSuccessful_X_Y;
	//используется для переключения начального значения итераций выстрелов
	int TacticalIterator;
	//кто ходит первый, в дальнейшем чей ход
	bool IsMoveFirst;
	//указывает находится ли pc в поиске корябля для добивания или атакует по стратегии 
	bool IsSearchForFinishingMode;
	//играет по стратегии? если нет то рандом.
	bool IsPlaysWithStrategy;
	///последний выстрел успешный
	bool IsLastShotSuccessful;
	//игра завершена
	bool IsFinish;
	//Тип кстановки кораблей true == автоустановка
	bool AutoInstallShipsMode;

	//выводить сообщение об уничтожении корабля противника?
	bool shipEnemyDestFlag;
	//выводить сообщение об уничтожении корабля игрока?
	bool shipYouDestFlag;

	ShipsModel shipsPlayer;

	int cntShip1;
	int cntShip2;
	int cntShip3;
	int cntShip4;

	int cntShip1Enemy;
	int cntShip2Enemy;
	int cntShip3Enemy;
	int cntShip4Enemy;


private:
	void Intial();
};


