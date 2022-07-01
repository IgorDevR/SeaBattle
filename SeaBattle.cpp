#include "SeaBattle.h"

//координция файлов игры, процесс игры
void GamePlay(PlayerModel& playerUser, PlayerModel& playerPc);
//заполнить массивы
void FillingFields(PlayerModel& player);
//вопрос: сыграть снова?
bool IsPlayAgain();
//ручная установка
void ManualInstall(PlayerModel& player);
//авто установка  рандом
void AutoInstall(PlayerModel& player);
// обмен полями. при печати не выводится, но используется для сравнения попаданий
void EnemyFieldExchangeFillingArray(PlayerModel& playerUser, PlayerModel& playerPC);
//начальное меню
void GameStartText();
//надпись  нажмите ввод
void GameStartPressEnter();
//кто ходит первым
bool WhoIsFirst(PlayerModel& player1, PlayerModel& player2);

int main()
{	
	System system;
	system.Init();

	bool play = true;

	while (play)
	{
		GameStartText();

		CoutPlayer_1();
		GetGameSettings gs1;
		CoutPlayer_2();
		GetGameSettings gs2;

		PlayerModel player1(gs1.IsUseAutoInstallShipsMode, gs1.IsUseStrategyForPcMode, gs1.IsThisPlayerUser, false);
		cout << "_____________________________" << endl;
		PlayerModel player2(gs2.IsUseAutoInstallShipsMode, gs2.IsUseStrategyForPcMode, gs2.IsThisPlayerUser, false);
		cout << "_____________________________" << endl;		

		FillingFields(player1);
		FillingFields(player2);
		
		EnemyFieldExchangeFillingArray(player1, player2);

		player1.IsMoveFirst = WhoIsFirst(player1, player2);
		player2.IsMoveFirst = !player1.IsMoveFirst;
		GameStartPressEnter();
		GamePlay(player1, player2);

		play = IsPlayAgain();
	}

}

void FillingFields(PlayerModel &player)
{	
	if (player.AutoInstallShipsMode)
	{		
		
		AutoInstall(player);
	}
	else
	{
		ManualInstall(player);
	}
}
bool IsPlayAgain()
{			
		string isPlayAgain = inputString(CoutIsPlayAgain);

		return isPlayAgain[0] == 'y' ? true : false;	

}

bool WhoIsFirst(PlayerModel& player1, PlayerModel& player2)
{
	cout << " " << endl << "---------------" << endl;

	srand(time(NULL));
	int user1 = rand() % 10 + 1;
	int user2 = rand() % 10 + 1;

	cout << "Die is cast........" << player1.NamePlayer << " points " << user1 << "/10" << endl;
	cout << "Die is cast........" << player2.NamePlayer << " points " << user2 << "/10" << endl;
	cout << " " << endl;

	if (user1 > user2)
		cout << "First move " << player1.NamePlayer << endl;

	else
		cout << "First move " << player2.NamePlayer << endl;

	cout << " " << endl << "---------------" << endl;

	if (user1 == user2)
	{
		cout << "The amount is equal. Re-throw....." << endl;
		//WhoIsFirst(player1, player2);
	}

	return user1 > user2 ? true : false;
}




