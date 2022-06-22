#include<iostream>
#include<fstream>
#include<string>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
using namespace std;

//����ѧ���Ӳ˵�����
void studentMenu(Identity* &student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		//������ָ��תΪ����ָ��,����������� �����ӿ�
		Student* stu = (Student*)student; 

		int select = 0;

		cin >> select; //�����û�ѡ��

		if (select == 1) //����ԤԼ
		{

			stu->applyOrder();

		}
		else if (select == 2)//�鿴����ԤԼ
		{

			stu->showMyOrder();


		}
		else if (select == 3) //�鿴������ԤԼ
		{

			stu->showAllOrder();

		}
		else if (select == 4) //ȡ��ԤԼ
		{

			stu->cancelOrder();

		}
		else
		{
			//ע��
			delete student; //���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		}

	}




}


//�������Ա�Ӳ˵�����
void managerMenu(Identity* &manager)
{
	
	while (true)
	{
		//���ù������Ӳ˵�
		manager->operMenu();

		//������ָ��תΪ����ָ��,����������� �����ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;

			man->addPerson();


		}
		else if (select == 2) //�鿴�˺�
		{

			//cout << "�鿴�˺�" << endl;

			man->showPerson();

		}
		else if (select == 3) //�鿴����
		{

			//cout << "�鿴����" << endl;
			man->showComputer();

		}
		else if (select == 4) //���ԤԼ
		{

			//cout << "���ԤԼ" << endl;
			man->cleanFile();

		}
		else
		{
			//ע��
			delete manager; //���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		}
	}

}



//��¼���� //�β�1 �����ļ���  �β�2 �����������
void Login(string fileName, int type)
{
	//����ָ�� ����ָ��������� (��֪��˭��¼���ö�̬)
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;

	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1) //ѧ�����
	{

		cout << "���������ѧ��: " << endl;
		cin >> id;


	}
	else if (type == 2) //��ʦ���
	{
		cout << "����������ְ����: " << endl;
		cin >> id;

	}

	cout << "�������û���: " << endl;
	cin >> name;

	cout << "����������: " << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId; //���ļ��ж�ȡ��id��
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{

			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);

				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;


			}


		}


	}
	else if (type == 2)
	{

		//��ʦ�����֤
		int fId; //���ļ��л�ȡ��id��
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ������

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{

				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				//������ʦ�Ӳ˵�

				return;
			}

		}


	}
	else if (type == 3)
	{

		//����Ա�����֤
		string fName; //���ļ��л�ȡ����
		string fPwd; //���ļ��л�ȡ������

		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{

				cout << "����Ա��¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//�������Ա�Ӳ˵�����
				managerMenu(person);
				return;

			}

		}


	}

	cout << "��֤��¼ʧ��!" << endl;


	system("pause");
	system("cls");

	return;

}


int main()
{
	int select = 0; //���ڽ����û���ѡ��

	while (true)
	{
		cout << "======================  ��ӭ�����¹������Ŀͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select; //�����û�ѡ��

		switch (select) //�����û���ѡ��ʵ�ֲ�ͬ�ӿ�
		{

		case 1: //ѧ�����
			Login(STUDENT_FILE, 1);
			break;

		case 2: //��ʦ���
			Login(TEACHER_FILE, 2);
			break;

		case 3: //����Ա���
			Login(ADMIN_FILE, 3);
			break; 

		case 0: //�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;

			break;

		default:
			cout << "��������,������ѡ��!" << endl;
			system("pause");
			system("cls");

			break;

		}


	}

	
	system("pause");
	return 0;

 }