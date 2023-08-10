#include<iostream>
#include"head.h"
using namespace std;
int main()
{
	Systemwork* work = new Systemwork();
	work->Employee();
	while (1)
	{
		work->Interface();
		int a;
		cin >> a;
		switch (a)
		{
		case 0: return 0; break;   //退出系统
		case 1:work->Addemployee();break;//增加职工信息
		case 2:work->Displayemployee(); break;  //显示所有员工信息
		case 3:work->Delayemployee(); break;//删除离职员工信息
		case 4:work->Modifyemployee(); break; //修改员工信息
		case 5:work->Findemployee(); break; //查找员工信息
		case 6:work->Sort(); break;  //按照职工编号进行排序
		case 7:work->Empty(); break;  //清除所有文档
		}
	}
	
}