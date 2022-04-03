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

	}//��������
	virtual void print();//�����Ϣ
	virtual int menu_print(string,string);
	friend ostream& operator<<(ostream&, administrator&);//������������
	friend istream& operator>>(istream&, administrator&);//�������������
	administrator &operator=(const administrator &per);
	int add();
	int search();
	int revise();
	int remove();
};
administrator::administrator() {};
administrator::administrator(string na, string num, string s, string de, string pa) :person(na, num, s, de, pa) {

}
void administrator::print()//���������������Ϣ
{
	person::print();
}
int administrator::add() {
	cout << "�Ƿ�ʹ���ļ�����ӣ�1.�ǣ�2.��" << endl;
	int file_option;
	int identity = 0;
	cin >> file_option;
	if (file_option==1)
	{
		cout << "�������ļ���" << endl;
		cin >> filename;
		cout << "��ѡ����ӵ��û����(1.��ʦ��2.ѧ����3.����;4.���ع���Ա����" << endl;
		cin >> identity;
		return -identity;
	}
	else if(file_option==2)
	{
		cout << "��ѡ����ӵ��û����(1.��ʦ��2.ѧ����3.����;4.���ع���Ա����" << endl;
		cin >> identity;
		return identity;
	}
	else
	{
		cout << "�������,����������" << endl;
		return 5;
	}
	
};
int administrator::search() {
	cout << "��ѡ���ѯ���û����(1.��ʦ��2.ѧ����3.���̣�4.���ع���Ա����" << endl;
	int identity;
	cin >> identity;
	return identity;
	
	
};
int administrator::remove() {
	cout << "��ѡ��ɾ�����û����(1.��ʦ��2.ѧ����3.���̣�4.���ع���Ա����" << endl;
	int identity;
	cin >> identity;
	return identity;
};
int administrator::revise() {
	cout << "��ѡ���޸ĵ��û����(1.��ʦ��2.ѧ����3.���̣�4.���ع���Ա����" << endl;
	int identity;
	cin >> identity;
	return identity;
};
int administrator::menu_print(string num, string pass) {
	int option_administrator;
	if (number==num&&password==pass) {
		cout << "\n\t\t\t\t\t  ----------------��¼�ɹ�----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t  ----------------����Ա����----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.����û�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.ɾ���û�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.��ѯ�û�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------4.�޸��û�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------5.�������˵�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              ��ѡ�����(1-5)              \t\t\t\t\t\n" << endl;
		cin >> option_administrator;
		return option_administrator;
	}
	else
	{
		if (number!=num)
		{
			cout << "\n\t\t\t\t\t  ----------------���Ŵ���----------------  \t\t\t\t\t\n" << endl;
		}
		if (password!=pass)
		{
			cout << "\n\t\t\t\t\t  ----------------�������----------------  \t\t\t\t\t\n" << endl;
		}
		return 5;
	}
};
ostream& operator<<(ostream&output, administrator&ad) {
	output << "����:" << ad.name << "   " << "ѧ�Ż򹤺�:" << ad.number << "   " << "�Ա�:" << ad.sex << "  " << "רҵ:" << ad.department << "  " << endl;
	return output;
}
istream& operator>>(istream&input, administrator&ad) {
	cout << "����������:"; input >> ad.name;
	cout << "����������:"; input >> ad.name;
	cout << "������ѧ�Ż򹤺�:"; input >> ad.number;
	cout << "�������Ա�male/female��:"; input >> ad.sex;
	cout << "������רҵ:"; input >> ad.department;
	cout << "����������:"; input >> ad.password;
	return input;
}
administrator &administrator::operator =(const administrator &per) //��ֵ���������
{
	name = per.name;
	number = per.number;
	sex = per.sex;
	department = per.department;
	password = per.password;
	return *this;   //ʵ�ֿ�������ֵ
}