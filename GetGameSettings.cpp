#include "GetGameSettings.h"
#include "SeaBattle.h"



GetGameSettings::GetGameSettings()
{		
	 SelectGameRegimeMode();
}
void GetGameSettings:: SelectGameRegimeMode()
{	
	int selectUser = inputInt(1, 2, CoutChoosePlayer);

	IsThisPlayerUser = selectUser == 1 ? true : false;

	if (!IsThisPlayerUser)
	{
		UseStrategyForPcMode();
	}
	UseAutoInstallShipsMode();	
}

void GetGameSettings::UseStrategyForPcMode()
{
	int selectUser = inputInt(1, 2, UseStrategyForPcModeText);
	IsUseStrategyForPcMode = selectUser == 1 ? true : false;
	
}
void GetGameSettings::UseAutoInstallShipsMode()
{
	int selectUser = inputInt(1, 2, UseAutoInstallShipsModeText);
	IsUseAutoInstallShipsMode = selectUser == 1 ? true : false;
}

