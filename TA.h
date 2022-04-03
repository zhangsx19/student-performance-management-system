#pragma once
#include"person.h"
#include"student.h"
#include"teacher.h"
class TA : public student, public teacher
{
	
public:
	TA();
	TA(string , string , string , string , string , string  ,string);//有参构造函数
	~TA()
	{

	}//虚析构函数
	virtual int menu_print(string, string);
	virtual void print();//内联函数，输出信息
	friend ostream& operator<<(ostream&, TA&);//重载输出运算符
	friend istream& operator>>(istream&, TA&);//重载输入运算符
	TA &operator=(const TA &per);
	void f_scan(FILE*);
};
TA::TA() {};
TA::TA(string na, string num, string s, string de, string pa, string cno, string prin) :student(na, num, s, de, pa,cno), teacher(na, num, s, de, pa, prin)//有参构造函数
{

}
int TA::menu_print(string num, string pass) {
	int option_TA;
	if (number == num && password == pass) {
		cout << "\n\t\t\t\t\t  ----------------助教界面----------------  \t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------1.录入学生成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------2.查询学生成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------3.修改学生成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------4.统计学生成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------5.删除学生成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------6.查询个人成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------7.统计个人成绩----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t----------------8.返回主菜单----------------\t\t\t\t\t\n" << endl;
		cout << "\n\t\t\t\t\t              请选择序号(1-8)              \t\t\t\t\t\n" << endl;
		cin >> option_TA;
		return option_TA;
	}
};
void TA::print()//内联函数，输出信息
{
	student::print();
	cout << "职务:" << principalship << endl;
}
ostream& operator<<(ostream&output, TA&a) {
	output << "姓名:" << a.name << "   " << "学号或工号:" << a.number << "   " << "性别:" << a.sex << "  " << "专业:" << a.department << "  " << "班号" << a.classNO <<" "<<"职务："<<a.principalship<< endl;
	return output;
}
istream& operator>>(istream&input, TA&a) {
	cout << "请输入姓名:"; input >> a.name;
	cout << "请输入学号或工号:"; input >> a.number;
	cout << "请输入性别（male/female）:"; input >> a.sex;
	cout << "请输入专业:"; input >> a.department;
	cout << "请输入密码:"; input >> a.password;
	cout << "请输入班号:"; input >> a.classNO;
	cout << "请输入职务:"; input >> a.principalship;
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
TA &TA::operator =(const TA &per) //赋值运算符重载
{
	name = per.name;
	number = per.number;
	sex = per.sex;
	department = per.department;
	password = per.password;
	principalship = per.principalship;
	classNO = per.classNO;
	return *this;   //实现可连续赋值
}
#pragma once
