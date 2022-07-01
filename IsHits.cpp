#include "SeaBattle.h"


ShipsEnum operator+(ShipsEnum& m, int num)
{
	ShipsEnum old = m;
	m = static_cast<ShipsEnum>(static_cast<int>(m) + num);
	return m;
}

bool CheckHit(PlayerModel& player)
{
	auto shipsEn = ShipsEnum::ship1_1;
	
	int X = player.LastShoot_X_Y[0];
	int Y = player.LastShoot_X_Y[1];
	char whatInThatCell = player.EnemyFieldArray[X][Y];

	bool hit = false;
	for (int i = 0; i < 10; i++)
	{		
		hit = whatInThatCell == (char)shipsEn;
		if (hit)
		{
			break;
		}
		operator+(shipsEn, 1);
	}

	
	
	if (hit)
	{	
		player.LastShotSuccessfulCoordArr = {X,Y};
		player.IsSearchForFinishingMode = true;
		player.IsLastShotSuccessful = true;

		if (player.FirstShotSuccessful_X_Y[1] == -1)
		{
			player.FirstShotSuccessful_X_Y[0] = X;
			player.FirstShotSuccessful_X_Y[1] = Y;
		}

		//CheckDestoierShip(player);
		return true;
	}
	else
	{		

		player.IsLastShotSuccessful = false;
		return false;

	}

}




