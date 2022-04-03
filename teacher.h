#pragma once
#include"person.h"
class teacher : virtual public person
{
protected:
	string principalship;
public:
	teacher();
	teacher(string, string, string, string, string, string);//�вι��캯��
	~teacher()
	{

	}//����������
	virtual void print();//���������������Ϣ
	virtual int menu_print(string,string);
	friend ostream& operator<<(ostream&, teacher&);//������������
	friend istream& operator>>(istream&, teacher&);//�������������
	teacher &operator=(const teacher &per);
	void f_scan(FILE*);
};
teacher::teacher() {};
teacher::teacher(string na, string num, string s, string de, string pa, string prin) :person(na, num, s, de, pa)//�вι��캯��
{
	principalship=prin;
}
void teacher::print()//���������������Ϣ
{
	person::print();
	cout << "ְ��:" << principalship << endl;
}
int teacher::menu_print(string num, string pass) {
	int option_teacher;
	if (number == num && password == pass) {
		cout << "\n\t\t\t\t\t  ----------------��ʦ����----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.¼��ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.��ѯѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.�޸�ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------4.ͳ��ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------5.ɾ��ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------6.�������˵�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              ��ѡ�����(1-6)              \t\t\t\t\t\n" << endl;
		cin >> option_teacher;
		return option_teacher;
	}
};
ostream& operator<<(ostream&output, teacher&a) {
	output << "����:" << a.name << "   " << "ѧ�Ż򹤺�:" << a.number << "   " << "�Ա�:" << a.sex << "  " << "רҵ:" << a.department << "ְ��" << a.principalship << endl;
	return output;
}
istream& operator>>(istream&input, teacher&a) {
	cout << "����������:"; input >> a.name;
	cout << "������ѧ�Ż򹤺�:"; input >> a.number;
	cout << "�������Ա�male/female��:"; input >> a.sex;
	cout << "������רҵ:"; input >> a.department;
	cout << "����������:"; input >> a.password;
	cout << "������ְ��:"; input >> a.principalship;
	return input;
}
void teacher::f_scan(FILE* pFile) {
	char fname[256]; fscanf(pFile, "%s", fname); name = fname;
	char fnumber[256]; fscanf(pFile, "%s", fnumber); number = fnumber;
	char fsex[256]; fscanf(pFile, "%s", fsex); sex = fsex;
	char fdepartment[256]; fscanf(pFile, "%s", fdepartment); department = fdepartment;
	char fpassword[256]; fscanf(pFile, "%s", fpassword); password = fpassword;
	char fprincipalship[256]; fscanf(pFile, "%s", fprincipalship); principalship = fprincipalship;
};
teacher &teacher::operator =(const teacher &per) //��ֵ���������
{
	name = per.name;
	number = per.number;
	sex = per.sex;
	department = per.department;
	password = per.password;
	principalship = per.principalship;
	return *this;   //ʵ�ֿ�������ֵ
}