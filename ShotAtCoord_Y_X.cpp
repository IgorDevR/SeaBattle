#include "SeaBattle.h"

void ShotFor_X_Y(PlayerModel& player, int x, int y)
{
	player.LastShoot_X_Y[0] = x;
	player.LastShoot_X_Y[1] = y;
}

void ShotAtCoord_Y_X(PlayerModel& player)
{
	int cntCellForAtack = 1;
	RequestInputOfCoordinates(player, cntCellForAtack, CoutEnterCoordForShot);
	

	int X = player.CoordinatesEnteredByUser[0];
	int Y = player.CoordinatesEnteredByUser[1];

	ShotFor_X_Y(player, X, Y);
}

void AttackForFinishingMode(PlayerModel& player)
{
	int baseX = player.FirstShotSuccessful_X_Y[0];
	int baseY = player.FirstShotSuccessful_X_Y[1];


	for (int x = baseX + 1; x < SizeField; x++)
	{
		if (player.ForPrintFieldArray[x][baseY] == Miss_char)
			break;

		if (player.ForPrintFieldArray[x][baseY] == Hit_char)
			continue;

		if (player.ForPrintFieldArray[x][baseY] == FreePlace_char)
			ShotFor_X_Y(player, x, baseY);
		return;
	}


	for (int x = baseX - 1; x >= 0; x--)
	{
		if (player.ForPrintFieldArray[x][baseY] == Miss_char)
			break;

		if (player.ForPrintFieldArray[x][baseY] == Hit_char)
			continue;

		if (player.ForPrintFieldArray[x][baseY] == FreePlace_char)
			ShotFor_X_Y(player, x, baseY);
		return;
	}


	for (int y = baseY + 1; y < SizeField; y++)
	{
		if (player.ForPrintFieldArray[baseX][y] == Miss_char)
			break;

		if (player.ForPrintFieldArray[baseX][y] == Hit_char)
			continue;

		if (player.ForPrintFieldArray[baseX][y] == FreePlace_char)
			ShotFor_X_Y(player, baseX, y);
		return;
	}


	for (int y = baseY - 1; y >= 0; y--)
	{
		if (player.ForPrintFieldArray[baseX][y] == Miss_char)
			break;

		if (player.ForPrintFieldArray[baseX][y] == Hit_char)
			continue;

		if (player.ForPrintFieldArray[baseX][y] == FreePlace_char)
			ShotFor_X_Y(player, baseX, y);
		return;
	}
}

void RandomShot(PlayerModel& player)
{
	srand(time(NULL));
	while (true)
	{
		int Xrand = rand() % 10;
		int Yrand = rand() % 10;

		if (!IsCellFreePlaceCheck(player, Xrand, Yrand))
		{
			continue;
		}

		ShotFor_X_Y(player, Xrand, Yrand);
		break;
	}
}