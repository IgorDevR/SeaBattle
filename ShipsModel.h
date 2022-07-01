#pragma once
#include <array>
#include <vector>
#include <iostream>
using namespace std;

enum  ShipsEnum;

enum  ShipsEnum
{
	none = 0,

	ship1_1 = 100,
	ship1_2 = 101,
	ship1_3 = 102,
	ship1_4 = 103,

	ship2_1 = 104,
	ship2_2 = 105,
	ship3_3 = 106,

	ship3_1 = 107,
	ship3_2 = 108,

	ship4_1 = 109,
};

//модель кораблей с массивами внутри
class ShipsModel
{
public:

	//модель Ship1 корабля
	class Ship1
	{
	public:
		bool isLive_1 = true;
		int HP_1 = 1;
		array<array<int, 2 >, 1>arrShip1;
		
	};
	//модель Ship2 корабля
	class Ship2
	{
	public:
		bool isLive_2 = true;
		int HP_2 = 2;
		array<array<int, 2 >, 2>arrShip2;
		
	};
	//модель Ship3 корабля
	class Ship3
	{
	public:
		bool isLive_3 = true;
		int HP_3 = 3;
		array<array<int, 2 >, 3>arrShip3;
		
	};
	//модель Ship4 корабля
	class Ship4
	{
	public:
		
		bool isLive_4 = true;
		int HP_4 = 4;
		array<array<int, 2 >, 4>arrShip4;
		
	};

	//массив координат для модели корабля
	array <Ship1, 4> arrShips1;
	//массив координат для модели корабля
	array <Ship2, 3> arrShips2;
	//массив координат для модели корабля
	array <Ship3, 2> arrShips3;
	//массив координат для модели корабля
	array <Ship4, 1> arrShips4;	

};

