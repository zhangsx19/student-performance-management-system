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
	string name;//����
	string sex;//�Ա�(male,female)
	string department;//����Ժϵ
	string password;//����

public:
	string number;//ѧ�ţ��򹤺ţ�
	person(); //�޲ι��캯��
	person(string, string, string, string,string);//�вι��캯��
	~person() { } //��������
	virtual void print() = 0;
	virtual int menu_print(string, string) = 0;
	bool verify(string, string);
	person &operator=(const person &per);//���ظ�ֵ�����
	friend ostream& operator<<(ostream&, person&);//������������
	friend istream& operator>>(istream&, person&);//�������������
};
person::person() {};
void person::print()//��ʾ���ݺ���
{
	cout << "����:" << name << "   " << "���:" << number << "   " << "�Ա�:" << sex << "  " << "רҵ:" << department << "  " << endl;
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
//�вι��캯������ʼ������
{
	name = na;
	number = num;
	sex = s;
	department = de;
	password = pa;
}
person &person::operator =(const person &per) //��ֵ���������
{
	name = per.name;
	number=per.number;
	sex = per.sex;
	department = per.department;
	password = per.password;
	return *this;   //ʵ�ֿ�������ֵ
}
ostream& operator<<(ostream&output, person&per) {
	output << "����:" << per.name << "   " << "ѧ�Ż򹤺�:" << per.number << "   " << "�Ա�:" << per.sex << "  " << "רҵ:" << per.department << "  " << endl;
	return output;
}
istream& operator>>(istream&input, person&per) {
	cout << "����������:"; input >> per.name;
	cout << "������ѧ�Ż򹤺�:"; input >> per.number;
	cout << "�������Ա�male/female��:"; input >> per.sex;
	cout << "������רҵ:"; input >> per.department;
	cout << "����������:"; input >> per.password;
	return input;
}
