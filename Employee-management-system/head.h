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
	void Interface();   //������
	void Exit();  //�˳�ϵͳ
	void Addemployee(); //1.����ְ����Ϣ
	void Displayemployee();  //2.��ʾ����Ա����Ϣ
	void Delayemployee();  //3.ɾ����ְԱ����Ϣ
	void Modifyemployee();//4.�޸�ְ����Ϣ
	void Findemployee();   //5.����Ա����Ϣ
	void Sort();    //6.����ְ����Ž�������
	void Empty();   //7.��������ĵ�

	void Employee();  //�����ļ�
private:
	vector<Worker*> worker;
};