#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Identity.h"
#include "ComputerRoom.h"
#include "GlobalFile.h"
#include "OrderFile.h"

class Student : public Identity
{
public :

	//Ĭ�Ϲ���
	Student();

	//�вι��� ����: ѧ��,����,����
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;


};