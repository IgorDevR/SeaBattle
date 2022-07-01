#include "SeaBattle.h"

//����� � ������ ���������
void AttackForFinishingMode(PlayerModel& player);
//����� � �������� ��������� � ������������
void ShotAtCoord_Y_X(PlayerModel& player);
//����� �� �������. ������ �� ����� � ����� 3, ��� ���������� ������ ������� �������� � ������ TacticalStratPCAttack
void TacticalShot(PlayerModel& player);
//��������� �������
void RandomShot(PlayerModel& player);


void AttackMove(PlayerModel& player)
{	

	if (player.IsThisPlayerUser)//���� ����� �������
	{		
		ShotAtCoord_Y_X(player);
		return;

	}
	else if (player.IsSearchForFinishingMode)//����� ���������, ����������� ����� ��������� ��������� �� �������
	{		
		AttackForFinishingMode(player);
		return;
	}	
	else if(!player.IsPlaysWithStrategy)//������ �����
	{
		RandomShot(player);
		return;
	}
	else if (player.IsPlaysWithStrategy && !player.IsSearchForFinishingMode)//�� ������ ����� , ��� ������� ����� ������������ �������� �� �������(�� � ������ ���������)
	{		
		TacticalShot(player);
		return;

	}
	return;

}





