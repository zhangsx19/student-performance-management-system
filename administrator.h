#pragma once
#include"person.h"
string filename;
FILE* pFile = fopen(filename.c_str(), "r+t");
class administrator :virtual public person
{
public:
	administrator();
	administrator(string, string, string, string, string);
	~administrator()
	{

	}//析构函数
	virtual void print();//输出信息
	virtual int menu_print(string,string);
	friend ostream& operator<<(ostream&, administrator&);//重载输出运算符
	friend istream& operator>>(istream&, administrator&);//重载输入运算符
	administrator &operator=(const administrator &per);
	int add();
	int search();
	int revise();
	int remove();
};
administrator::administrator() {};
administrator::administrator(string na, string num, string s, string de, string pa) :person(na, num, s, de, pa) {

}
void administrator::print()//内联函数，输出信息
{
	person::print();
}
int administrator::add() {
	cout << "是否使用文件流添加（1.是；2.否）" << endl;
	int file_option;
	int identity = 0;
	cin >> file_option;
	if (file_option==1)
	{
		cout << "请输入文件名" << endl;
		cin >> filename;
		cout << "请选择添加的用户身份(1.教师；2.学生；3.助教;4.返回管理员界面" << endl;
		cin >> identity;
		return -identity;
	}
	else if(file_option==2)
	{
		cout << "请选择添加的用户身份(1.教师；2.学生；3.助教;4.返回管理员界面" << endl;
		cin >> identity;
		return identity;
	}
	else
	{
		cout << "输入错误,请重新输入" << endl;
		return 5;
	}
	
};
int administrator::search() {
	cout << "请选择查询的用户身份(1.教师；2.学生；3.助教；4.返回管理员界面" << endl;
	int identity;
	cin >> identity;
	return identity;
	
	
};
int administrator::remove() {
	cout << "请选择删除的用户身份(1.教师；2.学生；3.助教；4.返回管理员界面" << endl;
	int identity;
	cin >> identity;
	return identity;
};
int administrator::revise() {
	cout << "请选择修改的用户身份(1.教师；2.学生；3.助教；4.返回管理员界面" << endl;
	int identity;
	cin >> identity;
	return identity;
};
int administrator::menu_print(string num, string pass) {
	int option_administrator;
	if (number==num&&password==pass) {
		cout << "\n\t\t\t\t\t  ----------------登录成功----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t  ----------------管理员界面----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.添加用户----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.删除用户----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.查询用户----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------4.修改用户----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------5.返回主菜单----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              请选择序号(1-5)              \t\t\t\t\t\n" << endl;
		cin >> option_administrator;
		return option_administrator;
	}
	else
	{
		if (number!=num)
		{
			cout << "\n\t\t\t\t\t  ----------------工号错误----------------  \t\t\t\t\t\n" << endl;
		}
		if (password!=pass)
		{
			cout << "\n\t\t\t\t\t  ----------------密码错误----------------  \t\t\t\t\t\n" << endl;
		}
		return 5;
	}
};
ostream& operator<<(ostream&output, administrator&ad) {
	output << "姓名:" << ad.name << "   " << "学号或工号:" << ad.number << "   " << "性别:" << ad.sex << "  " << "专业:" << ad.department << "  " << endl;
	return output;
}
istream& operator>>(istream&input, administrator&ad) {
	cout << "请输入姓名:"; input >> ad.name;
	cout << "请输入姓名:"; input >> ad.name;
	cout << "请输入学号或工号:"; input >> ad.number;
	cout << "请输入性别（male/female）:"; input >> ad.sex;
	cout << "请输入专业:"; input >> ad.department;
	cout << "请输入密码:"; input >> ad.password;
	return input;
}
administrator &administrator::operator =(const administrator &per) //赋值运算符重载
{
	name = per.name;
	number = per.number;
	sex = per.sex;
	department = per.department;
	password = per.password;
	return *this;   //实现可连续赋值
}