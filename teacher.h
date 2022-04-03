#pragma once
#include"person.h"
class teacher : virtual public person
{
protected:
	string principalship;
public:
	teacher();
	teacher(string, string, string, string, string, string);//有参构造函数
	~teacher()
	{

	}//虚析构函数
	virtual void print();//内联函数，输出信息
	virtual int menu_print(string,string);
	friend ostream& operator<<(ostream&, teacher&);//重载输出运算符
	friend istream& operator>>(istream&, teacher&);//重载输入运算符
	teacher &operator=(const teacher &per);
	void f_scan(FILE*);
};
teacher::teacher() {};
teacher::teacher(string na, string num, string s, string de, string pa, string prin) :person(na, num, s, de, pa)//有参构造函数
{
	principalship=prin;
}
void teacher::print()//内联函数，输出信息
{
	person::print();
	cout << "职务:" << principalship << endl;
}
int teacher::menu_print(string num, string pass) {
	int option_teacher;
	if (number == num && password == pass) {
		cout << "\n\t\t\t\t\t  ----------------教师界面----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.录入学生成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.查询学生成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.修改学生成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------4.统计学生成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------5.删除学生成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------6.返回主菜单----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              请选择序号(1-6)              \t\t\t\t\t\n" << endl;
		cin >> option_teacher;
		return option_teacher;
	}
};
ostream& operator<<(ostream&output, teacher&a) {
	output << "姓名:" << a.name << "   " << "学号或工号:" << a.number << "   " << "性别:" << a.sex << "  " << "专业:" << a.department << "职务" << a.principalship << endl;
	return output;
}
istream& operator>>(istream&input, teacher&a) {
	cout << "请输入姓名:"; input >> a.name;
	cout << "请输入学号或工号:"; input >> a.number;
	cout << "请输入性别（male/female）:"; input >> a.sex;
	cout << "请输入专业:"; input >> a.department;
	cout << "请输入密码:"; input >> a.password;
	cout << "请输入职务:"; input >> a.principalship;
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
teacher &teacher::operator =(const teacher &per) //赋值运算符重载
{
	name = per.name;
	number = per.number;
	sex = per.sex;
	department = per.department;
	password = per.password;
	principalship = per.principalship;
	return *this;   //实现可连续赋值
}