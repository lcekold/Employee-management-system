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
		case 0: return 0; break;   //�˳�ϵͳ
		case 1:work->Addemployee();break;//����ְ����Ϣ
		case 2:work->Displayemployee(); break;  //��ʾ����Ա����Ϣ
		case 3:work->Delayemployee(); break;//ɾ����ְԱ����Ϣ
		case 4:work->Modifyemployee(); break; //�޸�Ա����Ϣ
		case 5:work->Findemployee(); break; //����Ա����Ϣ
		case 6:work->Sort(); break;  //����ְ����Ž�������
		case 7:work->Empty(); break;  //��������ĵ�
		}
	}
	
}