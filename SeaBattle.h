#pragma once
#include "CoutText.h"
#include "PlayerModel.h"
#include "GetGameSettings.h"
#include "System.h"
#include <string>
using namespace std;


enum class CharCellTypeEnum
{
	None,
	Miss_ = '*', // *
	Hit_ = 'X', // x
	ReservedPlace_ = '.', // /
	FreePlace_ = 196, // .
	Ship_ = 254,

};

char static const Miss_char = (char)CharCellTypeEnum::Miss_;
char static const Hit_char = (char)CharCellTypeEnum::Hit_;
char static const FreePlace_char = (char)CharCellTypeEnum::FreePlace_;
char static const ReservedPlace_char = (char)CharCellTypeEnum::ReservedPlace_;
char static const Ship_char = (char)CharCellTypeEnum::Ship_;

 

//���� ��� �������������� �����  ������ ������� ��� ������ ReservedPlace
void ReservedPlaceAxis_(array <array<char, SizeField>, SizeField>& arrayP, array<int, 6>& coord, int size, char charCell);

//������� �� �����������
void ShotFor_X_Y(PlayerModel& player, int x, int y);

/// ���� ��������� ��� �������� ��� ���������� ��������
void RequestInputOfCoordinates(PlayerModel& player, int cntCoord, void (*func)());

//�������� � ����������� ���������
bool  ManualCoordAndCheck(PlayerModel& player, array<int, 6>& coord, int cntCoordin);
//�������� �� �� ��� ����� ��� ������� � ���� ����� ��� ���������
bool NotNearCheck(PlayerModel& player, array<int, 6>& coord);
//����������� ����� ������ ������� ��� ���������� ���������� ��������� � ����� �����������
void ReservedPlace( array <array<char, SizeField>, SizeField>& arrayP, array<int, 6>& coord, int x, int y, string axis, char charCell);
//�������� ������ �� ��������� �����
bool IsCellFreePlaceCheck(PlayerModel& player, int x, int y);
//�������� �� ����� �� ������� �������
bool IsInsideAnArrayCheck(int nextX, int nextY);


//������� ������ �� �������(���������� ������� ���������)
void ClearDispPrint();
//����� ���������� � ���� �� �����
void OutputOnDisplay(PlayerModel& playerAtack, PlayerModel& playerTake);
//����� �������� ���������� �������� � �������������� ���� ��� ��� ��� �������
void ScreenPrintDebug(PlayerModel& player);


//���� � ���������� ����
int inputInt(int m, int n, void (*func)());
//���� � ���������� ������
void inputString(array <int, 6>& coord, void (*func)());
string inputString(void (*func)());
