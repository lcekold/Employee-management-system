#pragma once
#include"Work.h"
#include<iostream>
using namespace std;
class Manager :public Worker
{
public:
	void Display();

	Manager();
	Manager(string name,int id,string post)
		:Worker(name,id,post){
		m_work = "调节生产";
	}
};
