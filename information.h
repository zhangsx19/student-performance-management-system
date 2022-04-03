#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<assert.h>
using namespace std;
class information
{
public:
	virtual void print() = 0;
	virtual int menu_print(string,string) = 0;
	information();
	~information();
	information &operator=(const information &peo);//重载赋值运算符
	friend ostream& operator<<(ostream&, information&);//重载输出运算符
	friend istream& operator>>(istream&, information&);//重载输入运算符
	virtual void add() = 0;
	virtual void search() = 0;
	virtual void revise() = 0;
	virtual void remove() = 0;
};
information::information() {

}
information::~information() {

}
#pragma once
