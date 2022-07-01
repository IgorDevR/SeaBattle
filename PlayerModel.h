#pragma once
#include <vector>
#include <array>
#include <iostream>
#include "ShipsModel.h"
using namespace std;

#pragma region Field
//������ ���� ������ � �������� �������� (Models.)
int const SizeField = 10;
//�������������� ��������
const array<char, SizeField  > HorizontalBoard_X = { 'A','B','C','D','E','F','G','H','I','J' };
//�������� - �����
const array<char, SizeField  > DotArrayUS = { '.','.','.','.','.','.','.','.','.','.' };
//������������ ��������
const array<char, SizeField  > VertBoard_Y = { '0','1','2','3','4','5','6','7','8','9' };
//����� ������
static int ID = 0;


/// <summary>
///������ ������
/// </summary>
class PlayerModel
{
public:

	//useAutoInstallShipsMode ����������� ? /useStrategyForPcMode �� ���������?/ isThisPlayerUser_First ���� ����� ������������?/ isFirstMove ���� ����� ����� ������?
	PlayerModel(bool useAutoInstallShipsMode, bool useStrategyForPcMode, bool isThisPlayerUser_First, bool isFirstMove);

	//��� ������
	string NamePlayer;

	//���� ����� ������������?  
	bool IsThisPlayerUser;
	///���� � ��������� � ��������� ������
	array<array<char, SizeField >, SizeField> PlayerFieldArray;
	///���� � ��������� � ��������� ����������(������, ����� ��� ����� ��� �� ����� ������������ �������� ����� ��� �����)
	array<array<char, SizeField >, SizeField> EnemyFieldArray;
	///���� � ��������� � ��������� ��� ������ �� �����
	array<array<char, SizeField >, SizeField> ForPrintFieldArray;

	//���������� �������� ������������� ������: 0 - X1, 1 - Y1, 2 - X2, 3 - Y2. X2 � Y2 ������������ ��� ������ ���������    
	array<int, 6>CoordinatesEnteredByUser;
	// ���������� ���������� ��������� ��������
	array<int, 2>  LastShotSuccessfulCoordArr;
	//��������� ������� 
	array<int, 2>  LastShoot_X_Y;
	// ��������� ������� �� ���������    
	array<int, 2> LastShotOnStrategy_X_Y;
	//�������� ������� ��������� �� �������
	array<int, 2>  FirstShotSuccessful_X_Y;
	//������������ ��� ������������ ���������� �������� �������� ���������
	int TacticalIterator;
	//��� ����� ������, � ���������� ��� ���
	bool IsMoveFirst;
	//��������� ��������� �� pc � ������ ������� ��� ��������� ��� ������� �� ��������� 
	bool IsSearchForFinishingMode;
	//������ �� ���������? ���� ��� �� ������.
	bool IsPlaysWithStrategy;
	///��������� ������� ��������
	bool IsLastShotSuccessful;
	//���� ���������
	bool IsFinish;
	//��� ��������� �������� true == �������������
	bool AutoInstallShipsMode;

	//�������� ��������� �� ����������� ������� ����������?
	bool shipEnemyDestFlag;
	//�������� ��������� �� ����������� ������� ������?
	bool shipYouDestFlag;

	ShipsModel shipsPlayer;

	int cntShip1;
	int cntShip2;
	int cntShip3;
	int cntShip4;

	int cntShip1Enemy;
	int cntShip2Enemy;
	int cntShip3Enemy;
	int cntShip4Enemy;


private:
	void Intial();
};


