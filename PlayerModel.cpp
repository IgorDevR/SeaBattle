#include "PlayerModel.h"
#include <string>

PlayerModel::PlayerModel( bool useAutoInstallShipsMode, bool useStrategyForPcMode, bool isThisPlayerUser_First, bool isFirstMove)
{
	if (ID == 2)
		ID = 0;

	ID++;
	IsThisPlayerUser = isThisPlayerUser_First;
	IsMoveFirst = isFirstMove;
	IsPlaysWithStrategy = useStrategyForPcMode;
	AutoInstallShipsMode = useAutoInstallShipsMode;
	Intial();
}
void PlayerModel::Intial()
{
	NamePlayer = "Player_" + to_string(ID);
	char fillArrChar = 196;

	fill(&PlayerFieldArray[0][0], &PlayerFieldArray[0][0] + 10 * 10, fillArrChar);
	fill(&EnemyFieldArray[0][0], &EnemyFieldArray[0][0] + 10 * 11, fillArrChar);
	fill(&ForPrintFieldArray[0][0], &ForPrintFieldArray[0][0] + 10 * 10, fillArrChar);

	LastShoot_X_Y = { 0,-1 };
	LastShotOnStrategy_X_Y = { 0,-1 };
	FirstShotSuccessful_X_Y = { 0,-1 };
	IsSearchForFinishingMode = false;
	IsLastShotSuccessful = false;
	IsFinish = false;
	TacticalIterator = 1;
	CoordinatesEnteredByUser = { 0,0,0,0,0,0 };

	 shipEnemyDestFlag = false;
	 shipYouDestFlag = false;
	
	 cntShip1 = 0;
	 cntShip2 = 0;
	 cntShip3 = 0;
	 cntShip4 = 0;

	 cntShip1Enemy = 4;
	 cntShip2Enemy = 3;
	 cntShip3Enemy = 2;
	 cntShip4Enemy = 1;
	
}




