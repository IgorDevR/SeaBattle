#include "SeaBattle.h"

array<int, 6> coord;

//при попадании отнимает жизнь у корабли, при достижении 0 ставится статус isLive_ = false
void SearchHitToShip(PlayerModel& playerTake, int indexCell, int iteratorForArrShip, PlayerModel& playerAtack, int size);
//корабль противника уничтожен? в статистике корабль противника будет отмечен как уничтоженный ТОЛЬКО кода клетки вокруг него будут разведаны выстрелами
void isEmenyShipDestr(PlayerModel& playerAtack, PlayerModel& playerTake, array<int, 6> coord, int indexCell, int size);
//резервироование места после уничтожения корабля
//void ReservedPlaceAxis_AfterDestrShipEnemy(PlayerModel& player, int x1, int y1, int x2, int y2, int size, char charCell);


void CheckDestroyerHitShip(PlayerModel& playerAtack, PlayerModel& playerTake)
{
	
	int size = 4;
	int cntShip = 5 - size;
	int indexCell = 0;
	int iteratorForArrShip = 0;

	while (true)
	{
		iteratorForArrShip = 0;
		for (int i = 0; i < size; i++)
		{
			SearchHitToShip(playerTake, indexCell, iteratorForArrShip, playerAtack, size);

			iteratorForArrShip++;
		}

		indexCell++;
		cntShip--;
		if (cntShip == 0)
		{
			indexCell = 0;
			size--;
			cntShip = 5 - size;

		}
		if (size == 0)
		{
			break;
		}
	}
}
void CheckDestroyerEnemyShip(PlayerModel& playerAtack, PlayerModel& playerTake)
{
	int size = 4;
	int cntShip = 5 - size;
	int indexCell = 0;
	array<int, 6> coord = { 0,0,0,0,0,0 };

	while (true)
	{
		for (int i = 0; i < 1; i++)
		{
			isEmenyShipDestr(playerAtack, playerTake, coord, indexCell, size);
		}

		indexCell++;
		cntShip--;
		if (cntShip == 0)
		{
			indexCell = 0;
			size--;
			cntShip = 5 - size;

		}
		if (size == 0)
		{
			break;
		}
	}
}


void SearchHitToShip(PlayerModel& playerTake, int indexCell, int iteratorForArrShip, PlayerModel& playerAtack, int size)
{
	//через цикл ищем попадание по модели корабля, при попадании отнимаем HP 
	if (size == 4)
	{
		if (playerTake.shipsPlayer.arrShips4[indexCell].arrShip4[iteratorForArrShip][0] == playerAtack.LastShoot_X_Y[0] &&
			playerTake.shipsPlayer.arrShips4[indexCell].arrShip4[iteratorForArrShip][1] == playerAtack.LastShoot_X_Y[1])
		{
			if (playerTake.shipsPlayer.arrShips4[indexCell].HP_4 > 0)
			{
				playerTake.shipsPlayer.arrShips4[indexCell].HP_4--;
				if (playerTake.shipsPlayer.arrShips4[indexCell].HP_4 == 0)
				{
					playerTake.shipsPlayer.arrShips4[indexCell].isLive_4 = false;
					playerTake.shipYouDestFlag = true;
					playerTake.cntShip4--;
				}
			}
		}
	}
	else if (size == 3)
	{
		if (playerTake.shipsPlayer.arrShips3[indexCell].arrShip3[iteratorForArrShip][0] == playerAtack.LastShoot_X_Y[0] &&
			playerTake.shipsPlayer.arrShips3[indexCell].arrShip3[iteratorForArrShip][1] == playerAtack.LastShoot_X_Y[1])
		{
			if (playerTake.shipsPlayer.arrShips3[indexCell].HP_3 > 0)
			{
				playerTake.shipsPlayer.arrShips3[indexCell].HP_3--;
				if (playerTake.shipsPlayer.arrShips3[indexCell].HP_3 == 0)
				{
					playerTake.shipsPlayer.arrShips3[indexCell].isLive_3 = false;
					playerTake.shipYouDestFlag = true;
					playerTake.cntShip3--;
				}
			}
		}
	}
	else if (size == 2)
	{
		if (playerTake.shipsPlayer.arrShips2[indexCell].arrShip2[iteratorForArrShip][0] == playerAtack.LastShoot_X_Y[0] &&
			playerTake.shipsPlayer.arrShips2[indexCell].arrShip2[iteratorForArrShip][1] == playerAtack.LastShoot_X_Y[1])
		{
			if (playerTake.shipsPlayer.arrShips2[indexCell].HP_2 > 0)
			{
				playerTake.shipsPlayer.arrShips2[indexCell].HP_2--;
				if (playerTake.shipsPlayer.arrShips2[indexCell].HP_2 == 0)
				{
					playerTake.shipsPlayer.arrShips2[indexCell].isLive_2 = false;
					playerTake.shipYouDestFlag = true;
					playerTake.cntShip2--;
				}
			}
		}
	}
	else if (size == 1)
	{
		if (playerTake.shipsPlayer.arrShips1[indexCell].arrShip1[iteratorForArrShip][0] == playerAtack.LastShoot_X_Y[0] &&
			playerTake.shipsPlayer.arrShips1[indexCell].arrShip1[iteratorForArrShip][1] == playerAtack.LastShoot_X_Y[1])
		{
			if (playerTake.shipsPlayer.arrShips1[indexCell].HP_1 > 0)
			{
				playerTake.shipsPlayer.arrShips1[indexCell].HP_1--;
				if (playerTake.shipsPlayer.arrShips1[indexCell].HP_1 == 0)
				{
					playerTake.shipsPlayer.arrShips1[indexCell].isLive_1 = false;
					playerTake.shipYouDestFlag = true;
					playerTake.cntShip1--;
				}
			}
		}
	}
}

//void ReservedPlaceAxis_AfterDestrShipEnemy(PlayerModel& player, array<int, 6>& coord, int size, char charCell)
//{
//
//	int startX = coord[0];
//	int endX = coord[1];
//	int startY = coord[3];
//	int endY = coord[4];
//
//	string axis;
//
//	if (startX == endX)
//	{
//		axis = "Y";
//	}
//	if (startY == endY)
//	{
//		axis = "X";
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		ReservedPlace(player, player.ForPrintFieldArray, coord, startX, startY, axis, charCell);
//
//		if (startX != endX)
//		{
//			startX++;
//		}
//		if (startY != endY)
//		{
//			startY++;
//		}
//
//	}
//}

void isEmenyShipDestr(PlayerModel& playerAtack, PlayerModel& playerTake, array<int, 6> coord, int  indexCell, int size)
{
	bool isDestr = true;

	int x1;
	int y1;
	int x2;
	int y2;

	//смотрим что бы клетки вокруг конечных точек корабля были отсреляны, если да, то считается как уничтоженный
	if (size == 4)
	{
		coord[0] = x1 = playerTake.shipsPlayer.arrShips4[indexCell].arrShip4[0][0];
		coord[1] = y1 = playerTake.shipsPlayer.arrShips4[indexCell].arrShip4[0][1];
		coord[3] = x2 = playerTake.shipsPlayer.arrShips4[indexCell].arrShip4[3][0];
		coord[4] = y2 = playerTake.shipsPlayer.arrShips4[indexCell].arrShip4[3][1];		

		if (playerTake.shipsPlayer.arrShips4[indexCell].isLive_4 == false && playerTake.cntShip4 >= 0 && x1 != -1)
		{
			//отнимаем корабль для статистики в своем классе, поднимаем флаг для вывода сообщения, затираем коорджинаты, что бы избежать повторгого захода
			playerAtack.cntShip4Enemy--;
			playerAtack.shipEnemyDestFlag = true;
			ReservedPlaceAxis_(playerAtack.ForPrintFieldArray, coord, size, Miss_char);
			playerTake.shipsPlayer.arrShips4[indexCell].arrShip4[0][0] = -1;
			playerAtack.IsSearchForFinishingMode = false;//если вокруг не осталось свободного места для атаки то корабль считается добитым и режим добивания отключается
			playerAtack.FirstShotSuccessful_X_Y[1] = -1;

		}
	}
	else if (size == 3)
	{
		coord[0] = x1 = playerTake.shipsPlayer.arrShips3[indexCell].arrShip3[0][0];
		coord[1] = y1 = playerTake.shipsPlayer.arrShips3[indexCell].arrShip3[0][1];
		coord[3] = x2 = playerTake.shipsPlayer.arrShips3[indexCell].arrShip3[2][0];
		coord[4] = y2 = playerTake.shipsPlayer.arrShips3[indexCell].arrShip3[2][1];

		if (playerTake.shipsPlayer.arrShips3[indexCell].isLive_3 == false && playerTake.cntShip3 >= 0 && x1 != -1)
		{
			if (playerTake.cntShip4 != 0)
			{
				if (x1 == x2)
				{
					if (y1 - 1 >= 0)
						if (playerAtack.ForPrintFieldArray[x1][y1 - 1] != Miss_char)
							return;


					if (y2 + 1 < SizeField)
						if (playerAtack.ForPrintFieldArray[x1][y2 + 1] != Miss_char)
							return;
				}
				if (y1 == y2)
				{
					if (x1 - 1 >= 0)
						if (playerAtack.ForPrintFieldArray[x1 - 1][y1] != Miss_char)
							return;


					if (x2 + 1 < SizeField)
						if (playerAtack.ForPrintFieldArray[x2 + 1][y1] != Miss_char)
							return;
				}
			}

			playerAtack.cntShip3Enemy--;
			playerAtack.shipEnemyDestFlag = true;
			ReservedPlaceAxis_(playerAtack.ForPrintFieldArray, coord, size, Miss_char);
			playerTake.shipsPlayer.arrShips3[indexCell].arrShip3[0][0] = -1;
			playerAtack.IsSearchForFinishingMode = false;//если вокруг не осталось свободного места для атаки то корабль считается добитым и режим добивания отключается
			playerAtack.FirstShotSuccessful_X_Y[1] = -1;
		}
	}
	else if (size == 2)
	{
		coord[0] = x1 = playerTake.shipsPlayer.arrShips2[indexCell].arrShip2[0][0];
		coord[1] = y1 = playerTake.shipsPlayer.arrShips2[indexCell].arrShip2[0][1];
		coord[3] = x2 = playerTake.shipsPlayer.arrShips2[indexCell].arrShip2[1][0];
		coord[4] = y2 = playerTake.shipsPlayer.arrShips2[indexCell].arrShip2[1][1];

		if (playerTake.shipsPlayer.arrShips2[indexCell].isLive_2 == false && playerTake.cntShip2 >= 0 && x1 != -1)
		{
			if (playerTake.cntShip3 != 0 || playerTake.cntShip4 != 0)
			{
				if (x1 == x2)
				{
					if (y1 - 1 >= 0)
						if (playerAtack.ForPrintFieldArray[x1][y1 - 1] != Miss_char)
							return;


					if (y2 + 1 < SizeField)
						if (playerAtack.ForPrintFieldArray[x1][y2 + 1] != Miss_char)
							return;
				}
				if (y1 == y2)
				{
					if (x1 - 1 >= 0)
						if (playerAtack.ForPrintFieldArray[x1 - 1][y1] != Miss_char)
							return;


					if (x2 + 1 < SizeField)
						if (playerAtack.ForPrintFieldArray[x2 + 1][y1] != Miss_char)
							return;
				}
			}
			playerAtack.cntShip2Enemy--;
			playerAtack.shipEnemyDestFlag = true;
			ReservedPlaceAxis_(playerAtack.ForPrintFieldArray, coord, size, Miss_char);
			playerTake.shipsPlayer.arrShips2[indexCell].arrShip2[0][0] = -1;
			playerAtack.IsSearchForFinishingMode = false;//если вокруг не осталось свободного места для атаки то корабль считается добитым и режим добивания отключается
			playerAtack.FirstShotSuccessful_X_Y[1] = -1;

		}
	}
	else if (size == 1)
	{
	coord[0] = x1 = playerTake.shipsPlayer.arrShips1[indexCell].arrShip1[0][0];
	coord[1] = y1 = playerTake.shipsPlayer.arrShips1[indexCell].arrShip1[0][1];
	coord[3] = x2 = playerTake.shipsPlayer.arrShips1[indexCell].arrShip1[0][0];
	coord[4] = y2 = playerTake.shipsPlayer.arrShips1[indexCell].arrShip1[0][1];

		if (playerTake.shipsPlayer.arrShips1[indexCell].isLive_1 == false && playerTake.cntShip1 >= 0 && x1 != -1)
		{
			if (playerTake.cntShip2 != 0 || playerTake.cntShip3 != 0 || playerTake.cntShip4 != 0)
			{
				if (x1 == x2)
				{

					if (y1 - 1 >= 0)
						if (playerAtack.ForPrintFieldArray[x1][y1 - 1] != Miss_char)
							return;


					if (y2 + 1 < SizeField)
						if (playerAtack.ForPrintFieldArray[x1][y2 + 1] != Miss_char)
							return;
				}
				if (y1 == y2)
				{
					if (x1 - 1 >= 0)
						if (playerAtack.ForPrintFieldArray[x1 - 1][y1] != Miss_char)
							return;


					if (x2 + 1 < SizeField)
						if (playerAtack.ForPrintFieldArray[x2 + 1][y1] != Miss_char)
							return;
				}
			}
			playerAtack.cntShip1Enemy--;
			playerAtack.shipEnemyDestFlag = true;
			ReservedPlaceAxis_(playerAtack.ForPrintFieldArray, coord, size, Miss_char);
			playerTake.shipsPlayer.arrShips1[indexCell].arrShip1[0][0] = -1;
			playerAtack.IsSearchForFinishingMode = false;//если вокруг не осталось свободного места для атаки то корабль считается добитым и режим добивания отключается
			playerAtack.FirstShotSuccessful_X_Y[1] = -1;

		}
	}

}