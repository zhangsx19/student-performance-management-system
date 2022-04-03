#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<assert.h>
using namespace std;

class person
{
protected:
	string name;//姓名
	string sex;//性别(male,female)
	string department;//所在院系
	string password;//密码

public:
	string number;//学号（或工号）
	person(); //无参构造函数
	person(string, string, string, string,string);//有参构造函数
	~person() { } //析构函数
	virtual void print() = 0;
	virtual int menu_print(string, string) = 0;
	bool verify(string, string);
	person &operator=(const person &per);//重载赋值运算符
	friend ostream& operator<<(ostream&, person&);//重载输出运算符
	friend istream& operator>>(istream&, person&);//重载输入运算符
};
person::person() {};
void person::print()//显示数据函数
{
	cout << "姓名:" << name << "   " << "编号:" << number << "   " << "性别:" << sex << "  " << "专业:" << department << "  " << endl;
}
bool person::verify(string num, string pass) {
	if (number == num && password == pass) {
		return true;
	}
	else
	{
		return false;
	}
}
person::person(string na, string num, string s, string de,string pa)
//有参构造函数：初始化数据
{
	name = na;
	number = num;
	sex = s;
	department = de;
	password = pa;
}
person &person::operator =(const person &per) //赋值运算符重载
{
	name = per.name;
	number=per.number;
	sex = per.sex;
	department = per.department;
	password = per.password;
	return *this;   //实现可连续赋值
}
ostream& operator<<(ostream&output, person&per) {
	output << "姓名:" << per.name << "   " << "学号或工号:" << per.number << "   " << "性别:" << per.sex << "  " << "专业:" << per.department << "  " << endl;
	return output;
}
istream& operator>>(istream&input, person&per) {
	cout << "请输入姓名:"; input >> per.name;
	cout << "请输入学号或工号:"; input >> per.number;
	cout << "请输入性别（male/female）:"; input >> per.sex;
	cout << "请输入专业:"; input >> per.department;
	cout << "请输入密码:"; input >> per.password;
	return input;
}
