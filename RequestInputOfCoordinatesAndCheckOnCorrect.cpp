#include "SeaBattle.h"

//������ ��������� ��������� � ������ ��������� �������� �������������
void TransferOfCoordinates(PlayerModel& player, array <int, 6>& coord);



void RequestInputOfCoordinates(PlayerModel& player, int cntCoord, void (*func)())
{
	cout << endl;
	array <int, 6> coordTmp;
	while (true)
	{

		inputString(coordTmp, func);

		if (ManualCoordAndCheck(player, coordTmp, cntCoord))
		{
			break;
		}
	}
	TransferOfCoordinates(player, coordTmp);
}


void TransferOfCoordinates(PlayerModel& player, array <int, 6>& coordTmp)
{
	//������ ��� ��� ��������
	player.CoordinatesEnteredByUser[0] = coordTmp[0];
	player.CoordinatesEnteredByUser[1] = coordTmp[1];
	//���� 5 �� ��� ��������� ��������
	player.CoordinatesEnteredByUser[2] = coordTmp[2];
	player.CoordinatesEnteredByUser[3] = coordTmp[3];
	player.CoordinatesEnteredByUser[4] = coordTmp[4];
}