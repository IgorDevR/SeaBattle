#pragma once
#include <string>
#include <iostream>
#include <string>


using namespace std;
class GetGameSettings
{
public:
	GetGameSettings();

	//����� ������������(�������)?
	bool IsThisPlayerUser;
	// ������������ ������� ��� ������(������ ���� �����  ���������, ���� ��� �� ����� ������)?
	bool IsUseStrategyForPcMode;
	// ������������ ������������� ��� ��� ��� ������?
	bool IsUseAutoInstallShipsMode;	

private:

	/// <summary>
	/// ����� ����. 1 ����� � ����. 2 ���� � ����
	/// </summary>
	/// <returns>�������� ����� 1 ����� � ����. 2 ���� � ����</returns>
	void SelectGameRegimeMode();	
	/// <summary>
	////��� ���� ��
	/// </summary>
	/// <returns>1 ��������. 2 �� ��������� </returns>
	void UseStrategyForPcMode();
	/// <summary>
	/// ��� ��������� ��������
	/// </summary>
	/// <returns>1 ����. 2 ������</returns>
	void UseAutoInstallShipsMode();
	////��������, ��� ������
	//void GetNamePlayer(string numUser);
};
