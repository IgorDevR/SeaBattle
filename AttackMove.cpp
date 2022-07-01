#include "SeaBattle.h"

//атака в режиме добивания
void AttackForFinishingMode(PlayerModel& player);
//атака с запросом координат у пользователя
void ShotAtCoord_Y_X(PlayerModel& player);
//Атака по тактике. проход по полям с шагом 3, при достижении границ тактика меняется в методе TacticalStratPCAttack
void TacticalShot(PlayerModel& player);
//случайный выстрел
void RandomShot(PlayerModel& player);


void AttackMove(PlayerModel& player)
{	

	if (player.IsThisPlayerUser)//исли игрок человек
	{		
		ShotAtCoord_Y_X(player);
		return;

	}
	else if (player.IsSearchForFinishingMode)//режим добивания, активирется полсе успешного попадания по тактике
	{		
		AttackForFinishingMode(player);
		return;
	}	
	else if(!player.IsPlaysWithStrategy)//рандом атака
	{
		RandomShot(player);
		return;
	}
	else if (player.IsPlaysWithStrategy && !player.IsSearchForFinishingMode)//не рандом атака , или корабль добит возобновляем движение по тактике(не в режиме добивания)
	{		
		TacticalShot(player);
		return;

	}
	return;

}





