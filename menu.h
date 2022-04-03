#pragma once
#include"person.h"
using namespace std;
class menu :public person
{
protected:
	int option_regist;
	int option_administrator;
	int option_teacher;
	int option_student;
public:
	menu(); //无参构造函数
	~menu() { } //析构函数
	int menu_regist();//内联函数
	int menu_administrator();
	int menu_teacher();
	int menu_student();
};
int menu::menu_regist()//显示主菜单
{
	cout << "\n\t\t\t\t\t  ----------------欢迎使用学生成绩管理系统----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t  ----------------请选择身份----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------1.系统管理员----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------2.教师----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------3.学生----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------其他:退出系统----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t              请选择序号(1-3)              \t\t\t\t\t\n" << endl;
	cin >> option_regist;
	return option_regist;
}

int menu::menu_administrator() {
	cout << "\n\t\t\t\t\t  ----------------登录成功----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t  ----------------账号错误----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t  ----------------密码错误----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t  ----------------管理员界面----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------1.添加用户----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------2.删除用户----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------3.查询用户----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------4.修改用户----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------5.返回主菜单----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------其他:退出系统----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t              请选择序号(1-5)              \t\t\t\t\t\n" << endl;
	cin >> option_administrator;
	return option_administrator;
}
int menu::menu_teacher() {
	cout << "\n\t\t\t\t\t  ----------------教师界面----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------1.录入学生成绩----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------2.查询学生成绩----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------3.修改学生成绩----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------4.统计学生成绩----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------5.删除学生成绩----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------6.返回主菜单----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------其他:退出系统----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t              请选择序号(1-6)              \t\t\t\t\t\n" << endl;
	cin >> option_teacher;
	return option_teacher;
}
int menu::menu_student() {
	cout << "\n\t\t\t\t\t  ----------------学生界面----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------1.查询个人信息----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------2.查询成绩----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------3.返回主菜单----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------其他:退出系统----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t              请选择序号(1-3)              \t\t\t\t\t\n" << endl;
	cin >> option_student;
	return option_student;
}
