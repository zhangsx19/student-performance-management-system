#pragma once
#include"person.h"
class student :virtual public person
{
protected:
	string classNO;//学生班号
public:
	student();
	student(string, string, string, string, string,string);//有参构造函数
	~student()
	{

	}//虚析构函数
	virtual void print();//内联函数，输出信息
	virtual int menu_print(string,string);
	friend ostream& operator<<(ostream&, student&);//重载输出运算符
	friend istream& operator>>(istream&, student&);//重载输入运算符
	student &operator=(const student &per);
	void f_scan(FILE*);
};
student::student() {};

student::student(string na, string num, string s, string de, string pa,string cno):person(na, num, s, de, pa)//有参构造函数
{
	classNO = cno;
}
void student::print()//内联函数，输出信息
{
	person::print();
	cout << "班号:" << classNO << endl;
}
ostream& operator<<(ostream&output, student&a) {
	output << "姓名:" << a.name << "   " << "学号或工号:" << a.number << "   " << "性别:" << a.sex << "  " << "专业:" << a.department << "  " << "班号"<<a.classNO<<endl;
	return output;
}
int student::menu_print(string num,string pass) {
	int option_student;
	if (number == num && password == pass) {
		cout << "\n\t\t\t\t\t  ----------------学生界面----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.查询个人成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.统计个人成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.返回主菜单----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              请选择序号(1-3)              \t\t\t\t\t\n" << endl;
		cin >> option_student;
		return option_student;
	}
};
istream& operator>>(istream&input, student&a) {
	cout << "请输入姓名:"; input >> a.name;
	cout << "请输入学号或工号:"; input >> a.number;
	cout << "请输入性别（male/female）:"; input >> a.sex;
	cout << "请输入专业:"; input >> a.department;
	cout << "请输入密码:"; input >> a.password;
	cout << "请输入班号:"; input >> a.classNO;
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
student &student::operator =(const student &per) //赋值运算符重载
{
	name = per.name;
	number = per.number;
	sex = per.sex;
	department = per.department;
	password = per.password;
	classNO = per.classNO;
	return *this;   //实现可连续赋值
}