#pragma once
#pragma once
#include"person.h"
using namespace std;
class grade
{
private:
	string course_name;
	
public:
	string gra;
	string course_id;
	string teacher_number;
	string student_number;
	grade(); //�޲ι��캯��
	void input(string);
	void revise(string, string);
	bool remove(string, string);
	grade(string, string , string , string,string );//�вι��캯��
	~grade() { } //��������
	virtual void print();//��������
	grade &operator=(const grade &peo);//���ظ�ֵ�����
	friend ostream& operator<<(ostream&, grade&);//������������
	friend istream& operator>>(istream&, grade&);//�������������
	bool query(string,string);
	void f_scan(FILE*);
};
void grade::print()//��ʾ���ݺ���
{
	cout << "�γ̺�:" << course_id << "   " << "�γ���:" << course_name << "   " << "�ο���ʦ����:" << teacher_number << "  "  <<"ѧ��ѧ��" <<student_number<<" "<< "�ɼ�:" << gra << endl;
}
grade::grade()//�޲ι��캯��
{
}
void grade::input(string tnum) {
	cout << "������γ̺�:"; cin >> course_id;
	cout << "������γ���:"; cin >> course_name;
	teacher_number=tnum;
	cout << "������ѧ��ѧ��:"; cin >> student_number;
	cout << "������ɼ�:"; cin >> gra;
}
void grade::revise(string snum,string cid) {
	if (student_number == snum && course_id == cid) {
		cout << "������γ���:"; cin >> course_name;
		cout << "������ѧ��ѧ��:"; cin >> student_number;
		cout << "������ɼ�:"; cin >> gra;
	}
}
bool grade::remove(string snum, string cid) {
	if (student_number == snum && course_id == cid) {
		return true;
	}
	else
	{
		return false;
	}
}
grade::grade(string cid,string cname,string tnum,string snum,string gr)//�вι��캯��
{
	course_id = cid;
	course_name = cname;
	teacher_number = tnum;
	student_number = snum;
	gra = gr;
}
grade &grade::operator =(const grade &peo) //��ֵ���������
{
	course_id= peo.course_id;
	course_name= peo.course_name;
	teacher_number = peo.teacher_number;
	student_number = peo.student_number;
	gra = peo.gra;
	return *this;   //ʵ�ֿ�������ֵ
}
ostream& operator<<(ostream&output, grade&a) {
	output << "�γ̺�:" << a.course_id << "   " << "�γ���:" << a.course_name << "   " << "�ον�ʦ:" << a.teacher_number << "  " <<"ѧ��ѧ��" << a.student_number << " " << "�ɼ�:" << a.gra  << endl;
	return output;
}
istream& operator>>(istream&input, grade&a) {
	cout << "������γ̺�:"; input >> a.course_id;
	cout << "������γ���:"; input >> a.course_name;
	cout << "�������ον�ʦ����:"; input >> a.teacher_number;
	cout << "������ѧ��ѧ��:"; input >> a.student_number;
	cout << "������ɼ�:"; input >> a.gra;
	return input;
}
bool grade::query(string snum,string cid) {
	if (student_number==snum&&course_id==cid)
	{
		print();
		return true;
	}
	else
	{
		return false;
	}
}
void grade::f_scan(FILE* pFile) {
	char fcourse_name[256]; fscanf(pFile, "%s", fcourse_name); course_name = fcourse_name;
	char fcourse_id[256]; fscanf(pFile, "%s", fcourse_id); course_id = fcourse_id;
	char fstudent_number[256]; fscanf(pFile, "%s", fstudent_number); student_number = fstudent_number;
	char fteacher_number[256]; fscanf(pFile, "%s", fteacher_number); teacher_number = fteacher_number;
	char fgra[256]; fscanf(pFile, "%s", fgra); gra = fgra;
};