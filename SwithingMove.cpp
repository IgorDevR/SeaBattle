#include "SeaBattle.h"



void SwithingMove(PlayerModel& playerUser, PlayerModel& playerPc)
{	

	if (playerUser.IsMoveFirst)
	{		
		playerUser.IsMoveFirst = false;
		playerPc.IsMoveFirst = true;
	}
	else
	{		
		playerUser.IsMoveFirst = true;
		playerPc.IsMoveFirst = false;
	}
}