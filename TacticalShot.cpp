#include "SeaBattle.h" 

//смещение осей
void AxisShift(int& atackX, int& atackY,int & stepX, int& stepY);
// смена тактики после завершения полного прохода по полю
void TacticalIteratorShotChange(PlayerModel& player, int& atackX, int& atackY, int &stepY);
//после основных проходов по полю, выполняется поиск оставшихся клеток для атаки
void BruteForceCellsToAttack(PlayerModel& player);
//Атака по стратегии. Перезаписываем последние успешные координаты атаки
void AttackByStrategy(PlayerModel& player, int stepX, int stepY);


void TacticalShot(PlayerModel& player)
{
	int X, Y, stepX, stepY, lastShotOnStrategy_X, lastShotOnStrategy_Y, attackX, attackY;

	 X = 0; Y = 0;
	 //rows		//columns	
	 stepX = 1; stepY = 3;
	 
	 attackX = player.LastShotOnStrategy_X_Y[0];
	 attackY = player.LastShotOnStrategy_X_Y[1];
	
	while (!player.IsFinish)
	{		
		lastShotOnStrategy_X = player.LastShotOnStrategy_X_Y[0];
		lastShotOnStrategy_Y = player.LastShotOnStrategy_X_Y[1];
	
		
		if (attackY + stepY >= SizeField)
			AxisShift(attackX, attackY, stepX, stepY);

		else
			attackY += stepY;

		if (lastShotOnStrategy_X >= SizeField || attackX >= SizeField)
			TacticalIteratorShotChange(player, attackX, attackY, stepY);

		if (player.TacticalIterator == 3)
		{
			BruteForceCellsToAttack(player);
			return;
		}

		if (!IsCellFreePlaceCheck(player, attackX, attackY))
		{
			continue;
		}
		AttackByStrategy(player, attackX, attackY);
		return;
		
	}

}

void AxisShift(int & attackX, int & attackY, int& stepX, int & stepY)
{	
	attackX = attackX + stepX;
	attackY = stepY - (10 - attackY);
}

bool IsCellFreePlaceCheck(PlayerModel& player, int x, int y)
{
	if (!IsInsideAnArrayCheck(x, y))
		return false;

	char valueCell = player.ForPrintFieldArray[x][y];
	char whatSearch = FreePlace_char;

	if (whatSearch != valueCell)
		return false;

	return true;
}



void AttackByStrategy(PlayerModel& player, int atackX, int atackY)
{
	ShotFor_X_Y(player, atackX, atackY);
	player.LastShotOnStrategy_X_Y[0] = player.LastShoot_X_Y[0];
	player.LastShotOnStrategy_X_Y[1] = player.LastShoot_X_Y[1];	
}


void TacticalIteratorShotChange(PlayerModel& player, int& atackX, int &atackY, int& stepY)
{		
	
	if (player.TacticalIterator == 2)//третий обход
	{
		player.LastShotOnStrategy_X_Y[0] = 0;
		player.LastShotOnStrategy_X_Y[1] = -3;
		atackX = 0;
		atackY = player.LastShotOnStrategy_X_Y[1] + stepY;
		player.TacticalIterator++;
		return;
	}
	 if (player.TacticalIterator == 1)//второй обход
	{		
		player.LastShotOnStrategy_X_Y[0] = 0;
		player.LastShotOnStrategy_X_Y[1] = -2;
		atackX = 0;
		atackY = player.LastShotOnStrategy_X_Y[1] + stepY;
		player.TacticalIterator++;
		return;
	}	
}

void BruteForceCellsToAttack(PlayerModel& player)
{
	for (int x = 0; x < SizeField; x++)
	{
		for (int y = 0; y < SizeField; y++)
		{
			if (player.ForPrintFieldArray[x][y] == FreePlace_char)
			{
				AttackByStrategy(player, x, y);
				return;
			}
		}		
	}
	
}
