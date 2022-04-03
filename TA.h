#pragma once
#include"person.h"
#include"student.h"
#include"teacher.h"
class TA : public student, public teacher
{
	
public:
	TA();
	TA(string , string , string , string , string , string  ,string);//�вι��캯��
	~TA()
	{

	}//����������
	virtual int menu_print(string, string);
	virtual void print();//���������������Ϣ
	friend ostream& operator<<(ostream&, TA&);//������������
	friend istream& operator>>(istream&, TA&);//�������������
	TA &operator=(const TA &per);
	void f_scan(FILE*);
};
TA::TA() {};
TA::TA(string na, string num, string s, string de, string pa, string cno, string prin) :student(na, num, s, de, pa,cno), teacher(na, num, s, de, pa, prin)//�вι��캯��
{

}
int TA::menu_print(string num, string pass) {
	int option_TA;
	if (number == num && password == pass) {
		cout << "\n\t\t\t\t\t  ----------------���̽���----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.¼��ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.��ѯѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.�޸�ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------4.ͳ��ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------5.ɾ��ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------6.��ѯ���˳ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------7.ͳ�Ƹ��˳ɼ�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------8.�������˵�----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              ��ѡ�����(1-8)              \t\t\t\t\t\n" << endl;
		cin >> option_TA;
		return option_TA;
	}
};
void TA::print()//���������������Ϣ
{
	student::print();
	cout << "ְ��:" << principalship << endl;
}
ostream& operator<<(ostream&output, TA&a) {
	output << "����:" << a.name << "   " << "ѧ�Ż򹤺�:" << a.number << "   " << "�Ա�:" << a.sex << "  " << "רҵ:" << a.department << "  " << "���" << a.classNO <<" "<<"ְ��"<<a.principalship<< endl;
	return output;
}
istream& operator>>(istream&input, TA&a) {
	cout << "����������:"; input >> a.name;
	cout << "������ѧ�Ż򹤺�:"; input >> a.number;
	cout << "�������Ա�male/female��:"; input >> a.sex;
	cout << "������רҵ:"; input >> a.department;
	cout << "����������:"; input >> a.password;
	cout << "��������:"; input >> a.classNO;
	cout << "������ְ��:"; input >> a.principalship;
	return input;
}
void TA::f_scan(FILE* pFile) {
	char fname[256]; fscanf(pFile, "%s", fname); name = fname;
	char fnumber[256]; fscanf(pFile, "%s", fnumber); number = fnumber;
	char fsex[256]; fscanf(pFile, "%s", fsex); sex = fsex;
	char fdepartment[256]; fscanf(pFile, "%s", fdepartment); department = fdepartment;
	char fpassword[256]; fscanf(pFile, "%s", fpassword); password = fpassword;
	char fprincipalship[256]; fscanf(pFile, "%s", fprincipalship); principalship = fprincipalship;
	char fclassNO[256]; fscanf(pFile, "%s", fclassNO); classNO = fclassNO;
};
TA &TA::operator =(const TA &per) //��ֵ���������
{
	name = per.name;
	number = per.number;
	sex = per.sex;
	department = per.department;
	password = per.password;
	principalship = per.principalship;
	classNO = per.classNO;
	return *this;   //ʵ�ֿ�������ֵ
}
#pragma once
