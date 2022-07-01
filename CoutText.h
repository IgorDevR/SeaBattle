#pragma once
#include <iostream>
#include "PlayerModel.h"

//"Choose type " << "Player1" << endl;
void CoutChoosePlayer();
//"Use computer attack on tactics (if selected PC player)." << endl << endl;
void UseStrategyForPcModeText();
//"Use auto install ships mode." << endl << endl;
void UseAutoInstallShipsModeText();


//"Enter coordinate for shot: "
void CoutEnterCoordForShot();
//"Your previous move: miss."
void CoutYouMissed();
//"Your previous move: hit!";
void CoutYouHit();
//"Opponent's previous move: miss.";
void CoutEnemyMissed();
//"Opponent's previous move: hit your ship!";
void CoutEnemyHit();
//"You ship destroyed!";
void CoutYouShipDestr();
//"Opponent's ship destroyed!";
void CoutEnemyShipDestr();
//"Atack on: ";
void CoutAtackOn();
//" Hit! << press enter to continue";
void CoutHitPressEnter();
//" Miss. << press enter to continue";
void CoutMissPressEnter();
// "End Game. Winner: ";
void CoutIsFinsih(PlayerModel & player);


//"Specify the cell to install the ship (format A1): ";
void CoutEnterCoordInstallShip1();
//"Specify the cell to install the ship ship (format B1 B2) : ";	
void CoutEnterCoordInstallShip2_3_4();


//"Play again y/n?" << endl;
void CoutIsPlayAgain();
//"error....Retry..." << endl;
void CoutErrorRetry();


//"1 - set ship size 1 cell. " << "Available - " << 4 - ship1 << " from - " << 4 << endl;....
void IstallShipsText(PlayerModel& player1, int numInstallShip);
//"Use computer attack on tactics (if selected PC player)." << endl << endl;
void UseStrategyForPcModeText();
//Use auto install ships mode." << endl << endl;
void UseAutoInstallShipsModeText();

//"Game sea battle ship" << endl << endl;
void GameStartText();
//"Please enter key for start game!" << endl << endl << endl;
void GameStartPressEnter();
//"string winer = player1.IsFinish == true ? "Player 1" : "Player 2";
void GameEndText(PlayerModel& player1, PlayerModel& player2); 

//ждет нажатия enter
void PressEnterContinue();


//"Atack " << playerAtack.NamePlayer << " << Press Enter to continue.";
void CoutAtackPlayer(PlayerModel& playerAtack);

//playerAtack.LastShoot_X_Y[0] << " - "; CoutMissPressEnter(); cout << " Next move - " << playerTake.NamePlayer;
void CoutCurrentShotAndNextMoveMiss(char y, PlayerModel& playerAtack, PlayerModel& playerTake);

//playerAtack.LastShoot_X_Y[0] << " - "; CoutHitPressEnter(); cout << " Next move - " << playerAtack.NamePlayer;
void CoutCurrentShotAndNextMoveHit(char y, PlayerModel& playerAtack);

void CoutNotCorrectInput();
void CoutExitingForField();
void CoutNotCorrectlength();
void CoutShipAreNearby();

void CoutPressEnterContinue();

void CoutPlayer_2();
void CoutPlayer_1();




