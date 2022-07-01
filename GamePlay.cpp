#include "SeaBattle.h"

/// <summary>
/// переключает ход между игроками
/// </summary>
/// <returns>обратное от передваемого</returns>
void SwithingMove(PlayerModel& playerUser, PlayerModel& playerPc);
// атакующий ход с выбором по стратегии или нет и проверкой на возможность атаки
void AttackMove(PlayerModel& player);
//проверка на уничтожение и попадание по кораблю? задает цикл методу SearchHitToShip
void CheckDestroyerHitShip(PlayerModel& playerAtack, PlayerModel& playerTake);
//проверка на уничтожение и попадание по кораблю? задает цикл методу isEmenyShipDestr
void CheckDestroyerEnemyShip(PlayerModel& playerAtack, PlayerModel& playerTake);
// проверка на попадание
bool CheckHit(PlayerModel& player);
//изменить массив полей с корабляи противника после выстрела(промах или попал)
void ChangeArrayAfterShot(PlayerModel& playerAtack, PlayerModel& playerTake, bool isHit);
//проверка на конец игры
void IsFinish(PlayerModel& player1, PlayerModel& player2);
//вывод результата после текущего хода
void PrintResultCurrentMove(PlayerModel& playerAttack, PlayerModel& playerTake, bool isHit);



//атака и проврека на попадание
void Atack(PlayerModel& playerAtack, PlayerModel& playerTake);
//
void CheckDestroyerChangeArrayField(PlayerModel& playerAtack, PlayerModel& playerTake, bool isHit);


void GamePlay(PlayerModel& playerFirst, PlayerModel& playerSecond)
{   
	
	bool isHit = false;
	while (!playerSecond.IsFinish && !playerFirst. IsFinish)
	{		
		ClearDispPrint();	

		if (playerFirst.IsMoveFirst)
		{			
			Atack(playerFirst, playerSecond);
			isHit = CheckHit(playerFirst);
			CheckDestroyerChangeArrayField(playerFirst, playerSecond, isHit);
		}
		else if (playerSecond.IsMoveFirst)
		{				
			Atack(playerSecond, playerFirst);
			isHit = CheckHit(playerSecond);
			CheckDestroyerChangeArrayField(playerSecond, playerFirst, isHit);
		}	

		if (!isHit)//если попал еще один ход. если нет то переключаем ход
		{
			SwithingMove(playerFirst, playerSecond);
		}

		IsFinish(playerFirst, playerSecond);
	}
}
void Atack(PlayerModel& playerAtack, PlayerModel& playerTake)
{
	OutputOnDisplay(playerAtack, playerTake);

	CoutAtackPlayer(playerAtack);
	if(!playerAtack.IsThisPlayerUser)
	PressEnterContinue();

	AttackMove(playerAtack);

}

void CheckDestroyerChangeArrayField(PlayerModel& playerAtack, PlayerModel& playerTake, bool isHit)
{
	if (isHit)
	{
		CheckDestroyerHitShip(playerAtack, playerTake);
	}
	ChangeArrayAfterShot(playerAtack, playerTake, isHit);//вносим изменения в массив на промах или попадание
	CheckDestroyerEnemyShip(playerAtack, playerTake);
	PrintResultCurrentMove(playerAtack, playerTake, isHit);
	
}


void IsFinish(PlayerModel& player1, PlayerModel& player2)
{
	bool cntShips_p1 = player1.cntShip1 + player1.cntShip2 + player1.cntShip3 + player1.cntShip4 == 0;
	if (cntShips_p1)
	{
		player1.IsFinish = true;
		CoutIsFinsih(player1);
		
	}
	bool cntShips_p2 = player2.cntShip1 + player2.cntShip2 + player2.cntShip3 + player2.cntShip4 == 0;
	if (cntShips_p2)
	{
		player2.IsFinish = true;
		CoutIsFinsih(player2);
	}
	if (cntShips_p1 || cntShips_p2)
		GameEndText(player1, player2);

}

void PrintResultCurrentMove(PlayerModel & playerAtack, PlayerModel& playerTake, bool isHit)
{
	
	char y = (char)(playerAtack.LastShoot_X_Y[1] + 65);

	if (isHit)
	{
		OutputOnDisplay(playerAtack, playerTake);
		CoutAtackOn();
		CoutCurrentShotAndNextMoveHit(y, playerAtack);
		PressEnterContinue();
	}
	else if(playerAtack.LastShoot_X_Y[1] != - 1)
	{
		OutputOnDisplay(playerAtack, playerTake);
		CoutAtackOn();
		CoutCurrentShotAndNextMoveMiss(y, playerAtack, playerTake);
		PressEnterContinue();
	}


}




