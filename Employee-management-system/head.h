#pragma once
#include"staff.h"
#include"Boss.h"
#include"Manager.h"
#include"Manager.h"
#include"Work.h"
#include<vector>
class Systemwork
{
public:
	void Interface();   //主界面
	void Exit();  //退出系统
	void Addemployee(); //1.增加职工信息
	void Displayemployee();  //2.显示所有员工信息
	void Delayemployee();  //3.删除离职员工信息
	void Modifyemployee();//4.修改职工信息
	void Findemployee();   //5.查找员工信息
	void Sort();    //6.按照职工编号进行排序
	void Empty();   //7.清空所有文档

	void Employee();  //创建文件
private:
	vector<Worker*> worker;
};