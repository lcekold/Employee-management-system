#pragma once
#include <iostream>
#include <string>
using namespace std;
class Worker
{
public:
	virtual void Display() = 0;  //显示工作人员的信息
	Worker();

	Worker(string name, int id, string post)
		:m_name(name),m_id(id),m_post(post){}

public:
	string m_name;
	int m_id;
	string m_post;
	string m_work;
};