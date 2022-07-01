#include "CoutText.h"
#include "SeaBattle.h"


void CoutEnterCoordForShot()
{
	cout << "Enter coordinate for shot: ";
}
void CoutYouMissed()
{
	cout << "Your previous move: miss.";
}
void CoutYouHit()
{
	cout << "Your previous move: hit!";
}
void CoutEnemyMissed()
{
	cout << "Opponent's previous move: miss.";
}
void CoutEnemyHit()
{
	cout << "Opponent's previous move: hit your ship!";
}
void CoutYouShipDestr()
{
	cout << "You ship destroyed!";
}
void CoutEnemyShipDestr()
{
	cout << "Opponent's ship destroyed!";
}
void CoutAtackOn()
{
	cout << endl << "Atack on: ";
}
void CoutHitPressEnter()
{
	cout << " Hit! << press enter to continue";
}
void CoutMissPressEnter()
{
	cout << " Miss. << press enter to continue";
}

void CoutIsFinsih(PlayerModel& player)
{
	cout << endl;
	cout << "++++++++++++++++++++++++++++" << endl;
	cout << "++++++++++++++++++++++++++++" << endl;
	cout << "End Game. Winner: " << player.NamePlayer << endl;;
}


void CoutEnterCoordInstallShip1()
{
	cout << "Specify the cell to install the ship (format A1): ";
}
void CoutEnterCoordInstallShip2_3_4()
{
	cout << "Specify the cell to install the ship ship (format B1 B2) : ";	
}


void CoutIsPlayAgain()
{
	cout << endl;
	cout << "Play again y/n?" << endl;
}
void CoutErrorRetry()
{
	cout << "error....Retry..." << endl;
}


void IstallShipsText(PlayerModel& player1, int numInstallShip)
{
	cout << endl << "-------------------" << endl;
	cout << "\t\tIntall ship " << numInstallShip;
	cout << endl << "-------------------" << endl;

	cout << "Installed ships size 4 cells - " << player1.cntShip4 << " from - " << 1 << endl;
	cout << "Installed ships size 3 cells - " << player1.cntShip3 << " from - " << 2 << endl;
	cout << "Installed ships size 2 cells - " << player1.cntShip2 << " from - " << 3 << endl;
	cout << "Installed ships size 1 cells - " << player1.cntShip1 << " from - " << 4 << endl;

}
#pragma region GameSettings

void UseStrategyForPcModeText()
{
	cout << "\t\tUse computer attack on tactics (if selected PC player)." << endl << endl;

	cout << "1 - Use tactic" << endl;
	cout << "2 - Random atack" << endl;
	cout << "Select: ";
}

void UseAutoInstallShipsModeText()
{
	cout << "\t\tUse auto install ships mode." << endl << endl;

	cout << "1 - Use auto install" << endl;
	cout << "2 - Manual install" << endl;
	cout << "Select: ";
}

void CoutChoosePlayer()
{
	
	cout << "\t\tChoose type " << endl;

	cout << "1 - User" << endl;
	cout << "2 - PC" << endl;
	cout << "Select: ";
}
void CoutPlayer_1()
{
	cout << "\t\tPlayer_first" << endl;	
}
void CoutPlayer_2()
{
	cout << "\t\tPlayer_second" << endl;
}


#pragma endregion

#pragma region Game start and end

#pragma endregion

void GameStartText()
{
	cout << "\t\tGame sea battle ship" << endl << endl;

	cout << "\t\tStart settintgs" << endl << endl << endl;

}
void GameStartPressEnter()
{
	cout << " " << endl;

	cout << "\t\tPlease enter key for start game!" << endl << endl << endl;
	//cin.get();

	PressEnterContinue();

	cout << " " << endl;

}
void GameEndText(PlayerModel& player1, PlayerModel& player2)
{
	cout << " " << endl;
	string winer = player1.IsFinish == true ? "Player 1" : "Player 2";

	cout << "\t\tGame Over!" << endl << endl << endl;
	cout << "\t\tVictory - " << winer << endl;
	cout << " " << endl;

}

void CoutPressEnterContinue()
{
	cout << "Press enter to continue" << endl;

	cin.ignore();
	cout.clear();


}
void PressEnterContinue()
{

	cin.ignore();
	cout.clear();


}


void CoutAtackPlayer(PlayerModel& playerAtack)
{
	cout << endl << "Atack " << playerAtack.NamePlayer << " << Press Enter to continue.";
}

void CoutCurrentShotAndNextMoveMiss(char y, PlayerModel& playerAtack, PlayerModel& playerTake)
{
	cout << y << playerAtack.LastShoot_X_Y[0] << " - "; CoutMissPressEnter(); cout << " Next move - " << playerTake.NamePlayer;
}

void CoutCurrentShotAndNextMoveHit(char y, PlayerModel& playerAtack)
{
	cout << y << playerAtack.LastShoot_X_Y[0] << " - "; CoutHitPressEnter(); cout << " Next move - " << playerAtack.NamePlayer;
}



void CoutNotCorrectInput()
{
	cout << "Error. Invalid enter....." << endl;
	cout << "------------------" << endl; "------------";
}
void CoutExitingForField()
{
	cout << "Error. Exiting the playing field....." << endl;
	cout << "------------------" << endl; "------------";
}
void CoutNotCorrectlength()
{
	cout << "Error. Invalid length for selected ship....." << endl;
	cout << "------------------" << endl; "------------";
}
void CoutShipAreNearby()
{
	cout << "Error. The ships are nearby....." << endl;
	cout << "------------------" << endl; "------------";
}