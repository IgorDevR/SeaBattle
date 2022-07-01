#pragma once
#include <string>
#include <iostream>
#include <string>


using namespace std;
class GetGameSettings
{
public:
	GetGameSettings();

	//игрок пользователь(человек)?
	bool IsThisPlayerUser;
	// использовать тактику для игрока(только если игрок  компьютер, если нет то атака рандом)?
	bool IsUseStrategyForPcMode;
	// использовать автоустановку или нет для игрока?
	bool IsUseAutoInstallShipsMode;	

private:

	/// <summary>
	/// режим игры. 1 игрок и комп. 2 комп и комп
	/// </summary>
	/// <returns>выбраный режим 1 игрок и комп. 2 комп и комп</returns>
	void SelectGameRegimeMode();	
	/// <summary>
	////тип игры пк
	/// </summary>
	/// <returns>1 случайно. 2 по стратегии </returns>
	void UseStrategyForPcMode();
	/// <summary>
	/// тип установки кораблей
	/// </summary>
	/// <returns>1 авто. 2 ручное</returns>
	void UseAutoInstallShipsMode();
	////получить, имя игрока
	//void GetNamePlayer(string numUser);
};
