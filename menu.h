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
	menu(); //�޲ι��캯��
	~menu() { } //��������
	int menu_regist();//��������
	int menu_administrator();
	int menu_teacher();
	int menu_student();
};
int menu::menu_regist()//��ʾ���˵�
{
	cout << "\n\t\t\t\t\t  ----------------��ӭʹ��ѧ���ɼ�����ϵͳ----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t  ----------------��ѡ�����----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------1.ϵͳ����Ա----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------2.��ʦ----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------3.ѧ��----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------����:�˳�ϵͳ----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t              ��ѡ�����(1-3)              \t\t\t\t\t\n" << endl;
	cin >> option_regist;
	return option_regist;
}

int menu::menu_administrator() {
	cout << "\n\t\t\t\t\t  ----------------��¼�ɹ�----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t  ----------------�˺Ŵ���----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t  ----------------�������----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t  ----------------����Ա����----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------1.����û�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------2.ɾ���û�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------3.��ѯ�û�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------4.�޸��û�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------5.�������˵�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------����:�˳�ϵͳ----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t              ��ѡ�����(1-5)              \t\t\t\t\t\n" << endl;
	cin >> option_administrator;
	return option_administrator;
}
int menu::menu_teacher() {
	cout << "\n\t\t\t\t\t  ----------------��ʦ����----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------1.¼��ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------2.��ѯѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------3.�޸�ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------4.ͳ��ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------5.ɾ��ѧ���ɼ�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------6.�������˵�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------����:�˳�ϵͳ----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t              ��ѡ�����(1-6)              \t\t\t\t\t\n" << endl;
	cin >> option_teacher;
	return option_teacher;
}
int menu::menu_student() {
	cout << "\n\t\t\t\t\t  ----------------ѧ������----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------1.��ѯ������Ϣ----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------2.��ѯ�ɼ�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------3.�������˵�----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------����:�˳�ϵͳ----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t              ��ѡ�����(1-3)              \t\t\t\t\t\n" << endl;
	cin >> option_student;
	return option_student;
}
