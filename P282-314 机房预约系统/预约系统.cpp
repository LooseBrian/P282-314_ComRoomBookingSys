#include<iostream>
#include<fstream>
#include<string>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
using namespace std;

//进入学生子菜单界面
void studentMenu(Identity* &student)
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();

		//将父类指针转为子类指针,调用子类里的 其他接口
		Student* stu = (Student*)student; 

		int select = 0;

		cin >> select; //接受用户选择

		if (select == 1) //申请预约
		{

			stu->applyOrder();

		}
		else if (select == 2)//查看自身预约
		{

			stu->showMyOrder();


		}
		else if (select == 3) //查看所有人预约
		{

			stu->showAllOrder();

		}
		else if (select == 4) //取消预约
		{

			stu->cancelOrder();

		}
		else
		{
			//注销
			delete student; //销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;

		}

	}




}


//进入管理员子菜单界面
void managerMenu(Identity* &manager)
{
	
	while (true)
	{
		//调用管理用子菜单
		manager->operMenu();

		//将父类指针转为子类指针,调用子类里的 其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户选择
		cin >> select;

		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;

			man->addPerson();


		}
		else if (select == 2) //查看账号
		{

			//cout << "查看账号" << endl;

			man->showPerson();

		}
		else if (select == 3) //查看机房
		{

			//cout << "查看机房" << endl;
			man->showComputer();

		}
		else if (select == 4) //清空预约
		{

			//cout << "清空预约" << endl;
			man->cleanFile();

		}
		else
		{
			//注销
			delete manager; //销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;

		}
	}

}



//登录功能 //形参1 操作文件名  形参2 操作身份类型
void Login(string fileName, int type)
{
	//父类指针 用于指向子类对象 (不知道谁登录利用多态)
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;

	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1) //学生身份
	{

		cout << "请输入你的学号: " << endl;
		cin >> id;


	}
	else if (type == 2) //老师身份
	{
		cout << "请输入您的职工号: " << endl;
		cin >> id;

	}

	cout << "请输入用户名: " << endl;
	cin >> name;

	cout << "请输入密码: " << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId; //从文件中读取的id号
		string fName; //从文件中获取的姓名
		string fPwd; //从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{

			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);

				//进入学生身份的子菜单
				studentMenu(person);
				return;


			}


		}


	}
	else if (type == 2)
	{

		//老师身份验证
		int fId; //从文件中获取的id号
		string fName; //从文件中获取的姓名
		string fPwd; //从文件中获取的密码

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{

				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				//进入老师子菜单

				return;
			}

		}


	}
	else if (type == 3)
	{

		//管理员身份验证
		string fName; //从文件中获取姓名
		string fPwd; //从文件中获取的密码

		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{

				cout << "管理员登录验证成功" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//进入管理员子菜单界面
				managerMenu(person);
				return;

			}

		}


	}

	cout << "验证登录失败!" << endl;


	system("pause");
	system("cls");

	return;

}


int main()
{
	int select = 0; //用于接收用户的选择

	while (true)
	{
		cout << "======================  欢迎来到陈果制作的客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接收用户选择

		switch (select) //根据用户的选择实现不同接口
		{

		case 1: //学生身份
			Login(STUDENT_FILE, 1);
			break;

		case 2: //老师身份
			Login(TEACHER_FILE, 2);
			break;

		case 3: //管理员身份
			Login(ADMIN_FILE, 3);
			break; 

		case 0: //退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;

			break;

		default:
			cout << "输入有误,请重新选择!" << endl;
			system("pause");
			system("cls");

			break;

		}


	}

	
	system("pause");
	return 0;

 }