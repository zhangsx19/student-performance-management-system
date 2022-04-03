#include"person.h"
#include"teacher.h"
#include"student.h"
#include"administrator.h"
#include"TA.h"
#include"grade.h"
using namespace std;
teacher tea[100];
student stu[100];
TA ta[100];
grade gra[100];
grade gra_statistic[100];
string num;
string pass;
bool verify_judge = true;
bool exit_judge = false;
bool operate_judge = false;
bool return_judge = false;
bool return_main_judge = false;
int teacher_amount = 0;
int student_amount = 0;
int TA_amount = 0;
int grade_amount = 0;
int statistic_amount = 0;
int option = 0;
string scan_num;
string scan_snum;
string scan_cid;
double sum_up,pass_rate,excellent_rate;
double max, min;
int menu_regist()//显示主菜单
{
	cout << "\n\t\t\t\t\t  ----------------欢迎使用学生成绩管理系统----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t  ----------------请选择身份----------------  \t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------1.系统管理员----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------2.教师----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------3.学生----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------4.助教----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t----------------5:退出系统----------------\t\t\t\t\t\n" << endl;
	cout << "\n\t\t\t\t\t              请选择序号(1-5)              \t\t\t\t\t\n" << endl;
	int option_regist;
	cin >> option_regist;
	if (option_regist==1|| option_regist == 2|| option_regist == 3 || option_regist == 4)
	{
		cout << "请输入账号" << endl;
		cin >> num;
		cout << "请输入密码" << endl;
		cin >> pass;
	}
	return option_regist;
}
int main()
{
	administrator ad("张三","2010011101","male","ee","124567");
	do 
	{
		exit_judge = false;
		switch (menu_regist())
		{
		case 1://管理员功能
			return_judge = false;
			do
			{
				operate_judge = false; return_judge = false;
				switch (ad.menu_print(num, pass))
				{
				case 1://添加用户
					return_judge = false; 
					do
					{
						switch (ad.add())
						{
						case 1://添加教师
							cin >> tea[teacher_amount];
							teacher_amount++;
							break;
						case 2://添加学生
							cin >> stu[student_amount];
							student_amount++;
							break;
						case 3://添加助教
							cin >> ta[TA_amount];
							TA_amount++;
							break;
						case 4:
							return_judge = true;
							break;
						case -1:
							if ((pFile = fopen(filename.c_str(), "r+t")) != NULL) {
								cout << "open file succeed" << endl;
								while (!feof(pFile)) {
									tea[teacher_amount].f_scan(pFile);
									teacher_amount++;
								};
								fclose(pFile);
							}
							else
							{
								cout << "Fail to open file!" << endl;
							}
							break;
						case -2:
							if ((pFile = fopen(filename.c_str(), "r+t")) != NULL) {
								cout << "open file succeed" << endl;
								while (!feof(pFile)) {
									stu[student_amount].f_scan(pFile);
									student_amount++;
								};
								fclose(pFile);
							}
							else
							{
								cout<<"Fail to open file!"<<endl;
							}
							break;
						case -3://添加助教
							if ((pFile = fopen(filename.c_str(), "r+t")) != NULL) {
								cout << "open file succeed" << endl;
								while (!feof(pFile)) {
									ta[TA_amount].f_scan(pFile);
									TA_amount++;
								};
								fclose(pFile);
							}
							else
							{
								cout << "Fail to open file!" << endl;
							}
							break;
						default:
							cout << "输入错误,请重新输入" << endl;
							break;
						};
					} while (return_judge == false);
					break;
				case 2://删除用户
					return_judge = false; 
					do
					{
						switch (ad.remove())
						{
						case 1://删除教师
							cout << "请选择删除用户的学号或工号" << endl;
							cin >> scan_num;
							for (int i = 0; i < teacher_amount; i++)
							{
								if (tea[i].number == scan_num) {
									teacher_amount--;
									for (int j = i; j < teacher_amount; j++)
									{
										tea[j] = tea[j + 1];
									}
									operate_judge = true;
									cout << "删除成功" << endl;
								}
								
							}
							break;
						case 2://删除学生
							cout << "请选择删除用户的学号或工号" << endl;
							cin >> scan_num;
							for (int i = 0; i < teacher_amount; i++)
							{
								if (stu[i].number == scan_num) {
									student_amount--;
									for (int j = i; j < student_amount; j++)
									{
										stu[j] = stu[j + 1];
									}
									operate_judge = true;
									cout << "删除成功" << endl;
								}
							};
							break;
						case 3://删除助教
							cout << "请选择删除用户的学号或工号" << endl;
							cin >> scan_num;
							for (int i = 0; i < teacher_amount; i++)
							{
								if (ta[i].number == scan_num) {
									TA_amount--;
									for (int j = i; j < TA_amount; j++)
									{
										ta[j] = ta[j + 1];
									}
									operate_judge = true;
									cout << "删除成功" << endl;
								}
							};
							break;
						case 4:
							return_judge = true;
							break;
						default:
							cout << "输入错误,请重新输入" << endl;
							break;
						}
						if (operate_judge == false)
						{
							cout << "没有该用户" << endl;
						}
						
					} while (return_judge == false);
					break;
				case 3://查询用户
					do
					{
						
						switch (ad.search())
						{
						case 1://查询教师
							cout << "请选择查询用户的学号或工号" << endl;
							cin >> scan_num;
							for (int i = 0; i < teacher_amount; i++)
							{
								if (tea[i].number == scan_num) {
									cout << tea[i] << endl;
									operate_judge = true;
								}
							}
							break;
						case 2://查询学生
							cout << "请选择查询用户的学号或工号" << endl;
							cin >> scan_num;
							for (int i = 0; i < teacher_amount; i++)
							{
								if (stu[i].number == scan_num) {
									cout << stu[i] << endl;
									operate_judge = true;
								}
								
							};
							break;
						case 3://查询助教
							cout << "请选择查询用户的学号或工号" << endl;
							cin >> scan_num;
							for (int i = 0; i < teacher_amount; i++)
							{
								if (ta[i].number == scan_num) {
									cout << ta[i] << endl;
									operate_judge = true;
								}
								
							};
							break;
						case 4:
							return_judge = true;
							break;
						default:
							cout << "输入错误,请重新输入" << endl;
							break;
						}
						if (operate_judge == false)
						{
							cout << "没有该用户" << endl;
						}
					} while (return_judge == false);
					break;
				case 4://修改用户
					do
					{
						
						switch (ad.revise())
						{
						case 1://修改教师
							cout << "请选择修改用户的学号或工号" << endl;
							cin >> scan_num;
							for (int i = 0; i < teacher_amount; i++)
							{
								if (tea[i].number == scan_num) {
									cin >> tea[i];
									operate_judge = true;
								}
							}
							break;
						case 2://修改学生
							cout << "请选择修改用户的学号或工号" << endl;
							cin >> scan_num;
							for (int i = 0; i < teacher_amount; i++)
							{
								if (stu[i].number == scan_num) {
									cin >> stu[i];
									operate_judge = true;
								}
							};
							break;
						case 3://修改助教
							cout << "请选择修改用户的学号或工号" << endl;
							cin >> scan_num;
							for (int i = 0; i < teacher_amount; i++)
							{
								if (ta[i].number == scan_num) {
									cin >> ta[i];
									operate_judge = true;
								}
							};
							break;
						case 4:
							return_judge = true;
							break;
						default:
							cout << "输入错误,请重新输入" << endl;
							break;
						}
						if (operate_judge == false)
						{
							cout << "没有该用户" << endl;
						}
					} while (return_judge == false);
					break;
				case 5:
					return_main_judge = true;
					break;
				default:
					cout << "输入错误,请重新输入" << endl;
					break;
				}
			} while (return_main_judge==false);
			break;
		case 2://教师功能
			return_main_judge = false;
			verify_judge = false;
			for (int i = 0; i < teacher_amount; i++)
			{
				if (tea[i].verify(num, pass)) {
					cout << "登录成功" << endl;
					verify_judge = true;
					do
					{
						operate_judge = false;
						switch (tea[i].menu_print(num, pass))
						{
						case 1://录入成绩
							return_judge = false; pFile = fopen(filename.c_str(), "r+t"); 
							do
							{
								cout << "请选择1.录入成绩；2.文件流录入；3.返回教师界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									gra[grade_amount].input(tea[i].number);
									grade_amount++;
									break;
								case 2:
									cout << "请输入文件名" << endl;
									cin >> filename;
									if ((pFile = fopen(filename.c_str(), "r+t")) != NULL) {
										cout << "open file succeed" << endl;
										while (!feof(pFile)) {
											gra[grade_amount].f_scan(pFile);
											grade_amount++;
										};
										fclose(pFile);
									}
									else
									{
										cout << "Fail to open file!" << endl;
									}
									break;
								case 3:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 2://查询成绩
							return_judge = false;
							do
							{
								cout << "请选择1.查询成绩；2.返回教师界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cout << "请输入查询学生的学号" << endl;
									cin >> scan_snum;
									cout << "请输入需要查询成绩的课程号" << endl;
									cin >> scan_cid;
									for (int j = 0; j < grade_amount; j++)
									{
										if (gra[j].query(scan_snum, scan_cid))
										{
											operate_judge = true;
										};
									}
									if (operate_judge==false)
									{
										cout << "查询结果不存在" << endl;
									}
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 3://修改成绩
							return_judge = false;
							do
							{
								cout << "请选择1.修改成绩；2.返回教师界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cout << "请输入要修改成绩的学生学号" << endl;
									cin >> scan_snum;
									cout << "请输入要修改成绩的课程号" << endl;
									cin >> scan_cid;
									for (int j = 0; j < grade_amount; j++)
									{
										gra[j].revise(scan_snum, scan_cid);
										operate_judge = true;
									}
									if (operate_judge == false)
									{
										cout << "要修改的结果不存在" << endl;
									}
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 4://统计成绩(某课的最高，最低，平均）
							return_judge = false;
							do
							{
								cout << "请选择1.统计成绩；2.返回教师界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cout << "请输入要统计成绩的课程号" << endl;
									cin >> scan_cid;
									statistic_amount = 0; sum_up = 0; pass_rate = 0; excellent_rate = 0;
									for (int j = 0; j < grade_amount; j++)
									{
										if (gra[j].course_id == scan_cid)
										{
											gra_statistic[statistic_amount] = gra[j];
											sum_up += std::atoi(gra[j].gra.c_str());
											if (gra[j].gra >= "60")
											{
												pass_rate++;
											}
											if (gra[j].gra >= "90")
											{
												excellent_rate++;
											}
											statistic_amount++;
										}
									}
									cout << "该课程平均分为" << ((double)sum_up / (double)statistic_amount) << endl;//平均值
									cout << "该课程及格率为" << ((double)pass_rate /(double) statistic_amount) << endl;//及格率
									cout << "该课程优秀率为" << ((double)excellent_rate /(double) statistic_amount) << endl;//优秀率
									max = std::atoi(gra_statistic[0].gra.c_str()); min = std::atoi(gra_statistic[0].gra.c_str());
									for (int j = 0; j < statistic_amount - 1; j++)
									{
										if (max< std::atoi(gra_statistic[j + 1].gra.c_str())) {
											max = std::atoi(gra_statistic[j + 1].gra.c_str());
										}
										if (min> std::atoi(gra_statistic[j + 1].gra.c_str()))
										{
											min = std::atoi(gra_statistic[j + 1].gra.c_str());
										}
									}
									cout << "该课程最高分为" << max << endl;
									cout << "该课程最低分为" << min << endl;
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 5://删除成绩
							return_judge = false;
							do
							{
								cout << "请选择1.删除成绩；2.返回教师界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cout << "请输入要删除成绩的学生学号" << endl;
									cin >> scan_snum;
									cout << "请输入要删除成绩的课程号" << endl;
									cin >> scan_cid;
									for (int k = 0; k < grade_amount; k++)
									{
										if (gra[k].remove(scan_snum, scan_cid))
										{
											grade_amount--;
											for (int j = k; j < grade_amount; j++)
											{
												gra[j] = gra[j + 1];
											}
											operate_judge = true;
										};
									}
									if (operate_judge == false)
									{
										cout << "要删除的数据不存在" << endl;
									}
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 6:
							return_main_judge = true;
							break;
						default:
							cout << "输入错误,请重新输入" << endl;
							break;
						}
					} while (return_main_judge == false);
				};
			}
			if (verify_judge == false)
			{
				cout << "登录失败" << endl;
				return_main_judge = true;
			};
			break;
		case 3://学生功能
			return_main_judge = false;
			verify_judge = false;
			for (int i = 0; i < 100; i++)
			{
				if (stu[i].verify(num, pass)) {
					cout << "登录成功" << endl;
					verify_judge = true;
					do
					{
						operate_judge = false;
						switch (stu[i].menu_print(num, pass))
						{
						case 1://查询个人成绩
							return_judge = false;
							do
							{
								cout << "请选择1.查询个人成绩；2.返回学生界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cout << "请输入查询的课程号" << endl;
									cin >> scan_cid;
									for (int j = 0; j < grade_amount; j++)
									{
										if (gra[j].query(stu[i].number, scan_cid))
										{
											operate_judge = true;
										};
									}
									if (operate_judge == false)
									{
										cout << "查询结果不存在" << endl;
									}
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 2://统计个人成绩
							return_judge = false;
							do
							{
								cout << "请选择1.统计个人成绩；2.返回学生界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									statistic_amount = 0; sum_up = 0; pass_rate = 0; excellent_rate = 0;
									for (int j = 0; j < grade_amount; j++)
									{
										if (gra[j].student_number == stu[i].number)
										{
											gra_statistic[statistic_amount] = gra[j];
											sum_up += std::atoi(gra[j].gra.c_str());
											if (gra[j].gra >= "60")
											{
												pass_rate++;
											}
											if (gra[j].gra >= "90")
											{
												excellent_rate++;
											}
											statistic_amount++;
										}
									}
									cout << "该生平均分为" << ((double)sum_up / (double)statistic_amount) << endl;//平均值
									cout << "该生及格率为" << ((double)pass_rate /(double) statistic_amount) << endl;//及格率
									cout << "该生优秀率为" << ((double)excellent_rate /(double) statistic_amount) << endl;//优秀率
									max = std::atoi(gra_statistic[0].gra.c_str()); min = std::atoi(gra_statistic[0].gra.c_str());
									for (int j = 0; j< statistic_amount - 1; j++)
									{
										if (max < std::atoi(gra_statistic[j+ 1].gra.c_str())) {
											max = std::atoi(gra_statistic[j + 1].gra.c_str());
										}
										if (min > std::atoi(gra_statistic[j + 1].gra.c_str()))
										{
											min = std::atoi(gra_statistic[j + 1].gra.c_str());
										}
									}
									cout << "该生最高分为" << max << endl;
									cout << "该生最低分为" << min << endl;
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 3:
							return_main_judge = true;
							break;
						default:
							cout << "输入错误,请重新输入" << endl;
							break;
						}
					} while (return_main_judge == false);
				};
			}
			if (verify_judge == false)
			{
				cout << "登录失败" << endl;
				return_main_judge = true;
			};
			break;
		case 4://助教功能
			return_main_judge = false;
			verify_judge = false;
			for (int i = 0; i < 100; i++)
			{
				if (ta[i].verify(num, pass)) {
					cout << "登录成功" << endl;
					verify_judge = true;
					do
					{
						operate_judge = false;
						switch (ta[i].menu_print(num, pass))
						{
						case 1://录入成绩
							return_judge = false;
							do
							{
								cout << "请选择1.录入成绩；2.文件录入成绩；3.返回助教界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cin >> gra[grade_amount];
									grade_amount++;
									break;
								case 2:
									cout << "请输入文件名" << endl;
									cin >> filename;
									if ((pFile = fopen(filename.c_str(), "r+t")) != NULL) {
										cout << "open file succeed" << endl;
										while (!feof(pFile)) {
											gra[grade_amount].f_scan(pFile);
											grade_amount++;
										};
										fclose(pFile);
									}
									else
									{
										cout << "Fail to open file!" << endl;
									}
									break;
								case 3:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 2://查询成绩
							return_judge = false;
							do
							{
								cout << "请选择1.查询成绩；2.返回助教界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cout << "请输入查询学生的学号" << endl;
									cin >> scan_snum;
									cout << "请输入需要查询成绩的课程号" << endl;
									cin >> scan_cid;
									for (int j = 0; j < grade_amount; j++)
									{
										if (gra[j].query(scan_snum, scan_cid))
										{
											operate_judge = true;
										};
									}
									if (operate_judge == false)
									{
										cout << "查询结果不存在" << endl;
									}
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 3://修改成绩
							return_judge = false;
							do
							{
								cout << "请选择1.修改成绩；2.返回助教界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cout << "请输入要修改成绩的学生学号" << endl;
									cin >> scan_snum;
									cout << "请输入要修改成绩的课程号" << endl;
									cin >> scan_cid;
									for (int j = 0; j < grade_amount; j++)
									{
										gra[j].revise(scan_snum, scan_cid);
										operate_judge = true;
									}
									if (operate_judge == false)
									{
										cout << "要修改的结果不存在" << endl;
									}
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 4://统计成绩
							return_judge = false;
							do
							{
								cout << "请选择1.统计成绩；2.返回助教界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cout << "请输入要统计成绩的课程号" << endl;
									cin >> scan_cid;
									statistic_amount = 0; sum_up = 0; pass_rate = 0; excellent_rate = 0;
									for (int j = 0; j < grade_amount; j++)
									{
										if (gra[j].course_id == scan_cid)
										{
											gra_statistic[statistic_amount] = gra[j];
											sum_up += std::atoi(gra[j].gra.c_str());
											if (gra[j].gra >= "60")
											{
												pass_rate++;
											}
											if (gra[j].gra >= "90")
											{
												excellent_rate++;
											}
											statistic_amount++;
										}
									}
									cout << "该课程平均分为" << ((double)sum_up / (double)statistic_amount) << endl;//平均值
									cout << "该课程及格率为" << ((double)pass_rate /(double) statistic_amount) << endl;//及格率
									cout << "该课程优秀率为" << ((double)excellent_rate /(double) statistic_amount) << endl;//优秀率
									max = std::atoi(gra_statistic[0].gra.c_str()); min = std::atoi(gra_statistic[0].gra.c_str());
									for (int j = 0; j < statistic_amount - 1; j++)
									{
										if (max < std::atoi(gra_statistic[j + 1].gra.c_str())) {
											max = std::atoi(gra_statistic[j + 1].gra.c_str());
										}
										if (min > std::atoi(gra_statistic[j + 1].gra.c_str()))
										{
											min = std::atoi(gra_statistic[j + 1].gra.c_str());
										}
									}
									cout << "该课程最高分为" << max << endl;
									cout << "该课程最低分为" << min << endl;
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 5://删除成绩
							return_judge = false;
							do
							{
								cout << "请选择1.删除成绩；2.返回助教界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cout << "请输入要删除成绩的学生学号" << endl;
									cin >> scan_snum;
									cout << "请输入要删除成绩的课程号" << endl;
									cin >> scan_cid;
									for (int k = 0; k< grade_amount; k++)
									{
										if (gra[k].remove(scan_snum, scan_cid))
										{
											grade_amount--;
											for (int j = k; j < grade_amount; j++)
											{
												gra[j] = gra[j + 1];
											}
											operate_judge = true;
										};
									}
									if (operate_judge == false)
									{
										cout << "要删除的数据不存在" << endl;
									}
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 6://查询个人成绩
							return_judge = false;
							do
							{
								cout << "请选择1.查询个人成绩；2.返回助教界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									cout << "请输入查询的课程号" << endl;
									cin >> scan_cid;
									for (int j = 0; j < grade_amount; j++)
									{
										if (gra[j].query(ta[i].number, scan_cid))
										{
											operate_judge = true;
										};
									}
									if (operate_judge == false)
									{
										cout << "查询结果不存在" << endl;
									}
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 7://统计个人成绩
							return_judge = false;
							do
							{
								cout << "请选择1.统计个人成绩；2.返回助教界面" << endl;
								cin >> option;
								switch (option)
								{
								case 1:
									statistic_amount = 0; sum_up = 0; pass_rate = 0; excellent_rate = 0;
									for (int j = 0; j < grade_amount; j++)
									{
										if (gra[j].student_number == ta[i].number)
										{
											gra_statistic[statistic_amount] = gra[j];
											sum_up += std::atoi(gra[j].gra.c_str());
											if (gra[j].gra >= "60")
											{
												pass_rate++;
											}
											if (gra[j].gra >= "90")
											{
												excellent_rate++;
											}
											statistic_amount++;
										}
									}
									cout << "该生平均分为" << ((double)sum_up / (double)statistic_amount) << endl;//平均值
									cout << "该生及格率为" << ((double)pass_rate /(double) statistic_amount) << endl;//及格率
									cout << "该生优秀率为" << ((double)excellent_rate /(double) statistic_amount) << endl;//优秀率
									max = std::atoi(gra_statistic[0].gra.c_str()); min = std::atoi(gra_statistic[0].gra.c_str());
									for (int j = 0; j < statistic_amount - 1; j++)
									{
										if (max < std::atoi(gra_statistic[j + 1].gra.c_str())) {
											max = std::atoi(gra_statistic[j + 1].gra.c_str());
										}
										if (min > std::atoi(gra_statistic[j + 1].gra.c_str()))
										{
											min = std::atoi(gra_statistic[j + 1].gra.c_str());
										}
									}
									cout << "该生最高分为" << max << endl;
									cout << "该生最低分为" << min << endl;
									break;
								case 2:
									return_judge = true;
									break;
								default:
									cout << "输入错误,请重新输入" << endl;
									break;
								}
							} while (return_judge == false);
							break;
						case 8:
							return_main_judge = true;
							break;
						default:
							cout << "输入错误,请重新输入" << endl;
							break;
						}
					} while (return_main_judge == false);
				};
			}
			if (verify_judge == false)
			{
				cout << "登录失败" << endl;
				return_main_judge = true;
			};
			break;
		case 5:
			exit_judge = true;
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			break;
		}
	} while (exit_judge == false);
}

