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
	grade(); //无参构造函数
	void input(string);
	void revise(string, string);
	bool remove(string, string);
	grade(string, string , string , string,string );//有参构造函数
	~grade() { } //析构函数
	virtual void print();//内联函数
	grade &operator=(const grade &peo);//重载赋值运算符
	friend ostream& operator<<(ostream&, grade&);//重载输出运算符
	friend istream& operator>>(istream&, grade&);//重载输入运算符
	bool query(string,string);
	void f_scan(FILE*);
};
void grade::print()//显示数据函数
{
	cout << "课程号:" << course_id << "   " << "课程名:" << course_name << "   " << "任课老师工号:" << teacher_number << "  "  <<"学生学号" <<student_number<<" "<< "成绩:" << gra << endl;
}
grade::grade()//无参构造函数
{
}
void grade::input(string tnum) {
	cout << "请输入课程号:"; cin >> course_id;
	cout << "请输入课程名:"; cin >> course_name;
	teacher_number=tnum;
	cout << "请输入学生学号:"; cin >> student_number;
	cout << "请输入成绩:"; cin >> gra;
}
void grade::revise(string snum,string cid) {
	if (student_number == snum && course_id == cid) {
		cout << "请输入课程名:"; cin >> course_name;
		cout << "请输入学生学号:"; cin >> student_number;
		cout << "请输入成绩:"; cin >> gra;
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
grade::grade(string cid,string cname,string tnum,string snum,string gr)//有参构造函数
{
	course_id = cid;
	course_name = cname;
	teacher_number = tnum;
	student_number = snum;
	gra = gr;
}
grade &grade::operator =(const grade &peo) //赋值运算符重载
{
	course_id= peo.course_id;
	course_name= peo.course_name;
	teacher_number = peo.teacher_number;
	student_number = peo.student_number;
	gra = peo.gra;
	return *this;   //实现可连续赋值
}
ostream& operator<<(ostream&output, grade&a) {
	output << "课程号:" << a.course_id << "   " << "课程名:" << a.course_name << "   " << "任课教师:" << a.teacher_number << "  " <<"学生学号" << a.student_number << " " << "成绩:" << a.gra  << endl;
	return output;
}
istream& operator>>(istream&input, grade&a) {
	cout << "请输入课程号:"; input >> a.course_id;
	cout << "请输入课程名:"; input >> a.course_name;
	cout << "请输入任课教师工号:"; input >> a.teacher_number;
	cout << "请输入学生学号:"; input >> a.student_number;
	cout << "请输入成绩:"; input >> a.gra;
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