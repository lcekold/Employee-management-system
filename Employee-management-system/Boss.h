#pragma once
#include"Work.h"
#include<iostream>
using namespace std;

class Boss :public Worker
{
public:
	void Display();

	Boss(string name, int id, string post)
		:Worker(name, id, post) {
		m_work = "管理企业";
	}
};

