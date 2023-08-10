#pragma once
#include"Work.h"
#include<iostream>
using namespace std;

class Staff :public Worker
{
public:
	void Display();

	Staff(string name, int id, string post)
		:Worker(name, id, post) {
		m_work = "进行工作";
	}
};

