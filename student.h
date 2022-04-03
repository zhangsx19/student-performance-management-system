#pragma once
#include"person.h"
class student :virtual public person
{
protected:
	string classNO;//ѧ�����
public:
	student();
	student(string, string, string, string, string,string);//�вι��캯��
	~student()
	{

	}//����������
	virtual void print();//���������������Ϣ
	virtual int menu_print(string,string);
	friend ostream& operator<<(ostream&, student&);//������������
	friend istream& operator>>(istream&, student&);//�������������
	student &operator=(const student &per);
	void f_scan(FILE*);
};
student::student() {};

student::student(string na, string num, string s, string de, string pa,string cno):person(na, num, s, de, pa)//�вι��캯��
{
	classNO = cno;
}
void student::print()//���������������Ϣ
{
	person::print();
	cout << "���:" << classNO << endl;
}
ostream& operator<<(ostream&output, student&a) {
	output << "����:" << a.name << "   " << "ѧ�Ż򹤺�:" << a.number << "   " << "�Ա�:" << a.sex << "  " << "רҵ:" << a.department << "  " << "���"<<a.classNO<<endl;
	return output;
}
int student::menu_print(string num,string pass) {
	int option_student;
	if (number == num && password == pass) {
		cout << "\n\t\t\t\t\t  ----------------ѧ������----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.��ѯ���˳ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.ͳ�Ƹ��˳ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.�������˵�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              ��ѡ�����(1-3)              \t\t\t\t\t\n" << endl;
		cin >> option_student;
		return option_student;
	}
};
istream& operator>>(istream&input, student&a) {
	cout << "����������:"; input >> a.name;
	cout << "������ѧ�Ż򹤺�:"; input >> a.number;
	cout << "�������Ա�male/female��:"; input >> a.sex;
	cout << "������רҵ:"; input >> a.department;
	cout << "����������:"; input >> a.password;
	cout << "��������:"; input >> a.classNO;
	return input;
}
void student::f_scan(FILE* pFile) {
	char fname[256]; fscanf(pFile, "%s", fname); name = fname;
	char fnumber[256]; fscanf(pFile, "%s", fnumber); number = fnumber;
	char fsex[256]; fscanf(pFile, "%s", fsex); sex = fsex;
	char fdepartment[256]; fscanf(pFile, "%s", fdepartment); department = fdepartment;
	char fpassword[256]; fscanf(pFile, "%s", fpassword); password = fpassword;
	char fclassNO[256]; fscanf(pFile, "%s", fclassNO); classNO = fclassNO;
};
student &student::operator =(const student &per) //��ֵ���������
{
	name = per.name;
	number = per.number;
	sex = per.sex;
	department = per.department;
	password = per.password;
	classNO = per.classNO;
	return *this;   //ʵ�ֿ�������ֵ
}