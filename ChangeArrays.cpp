#include "SeaBattle.h"
#include <array>
void EnemyFieldExchangeFillingArray(PlayerModel& playerUser, PlayerModel& playerPC)
{
	for (int i = 0; i < SizeField; i++)
	{
		for (int j = 0; j < SizeField; j++)
		{
			playerUser.EnemyFieldArray[i][j] = playerPC.PlayerFieldArray[i][j];
			playerPC.EnemyFieldArray[i][j] = playerUser.PlayerFieldArray[i][j];

		}
	}
}

void ChangeArrayAfterShot(PlayerModel& playerAtack, PlayerModel& playerTake, bool isHit)
{

	int X = playerAtack.LastShoot_X_Y[0];
	int Y = playerAtack.LastShoot_X_Y[1];

	if (isHit)
	{
		playerAtack.ForPrintFieldArray[X][Y] = Hit_char;
		playerTake.PlayerFieldArray[X][Y] = Hit_char;
	}
	else
	{
		playerAtack.ForPrintFieldArray[X][Y] = Miss_char;
		playerTake.PlayerFieldArray[X][Y] = Miss_char;

	}
}