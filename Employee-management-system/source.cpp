#include"head.h"
#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;
void Systemwork::Interface()
{
	cout <<  "********************************************"<< endl;
	cout << "**********  ��ӭʹ��ְ������ϵͳ  ***********" << endl;
	cout << "************   0.�˳��������  **************" << endl;
	cout << "************   1.����ְ����Ϣ  **************" << endl;
	cout << "************   2.��ʾְ����Ϣ  **************" << endl;
	cout << "************   3.ɾ����ְְ��  **************" << endl;
	cout << "************   4.�޸�ְ����Ϣ  **************" << endl;
	cout << "************   5.����ְ����Ϣ  **************" << endl;
	cout << "************   6.���ձ������  **************" << endl;
	cout << "************   7.��������ĵ�  **************" << endl;
	cout << "********************************************" << endl;
}


void Systemwork::Employee()   //�����ļ�����
{
	fstream File("Employee.txt", ios::app);
	if (!File)
	{
		cout << "error! �ļ������ڣ�ְ������ϵͳ�޷�ʹ�ã�" << endl;
	}
	
}




//����ְ����Ϣ
void Systemwork::Addemployee()    
{
	static int cnt=0;
	string name; int id;
	int b;
	
	
	cout << "��������������:" << endl;
	cin >> name;
	cout << "���������ı��:" << endl;
	cin >> id;

	cout << "����������ְλ��1Ϊ�ϰ壬2Ϊ����3ΪԱ����" << endl;
	cin >> b;
	switch (b)
	{
	case 1:worker.push_back(new Boss(name,id,"Boss"));
	case 2:worker.push_back(new Manager(name,id,"Manager"));
	case 3:worker.push_back(new Staff(name,id,"Staff"));
	}

	
	fstream File("Employee.txt", ios::in|ios::app); //��Ա����Ϣд���ļ�����
	if (!File)
	{
		cout << "error �ļ�δ��" << endl;
	}
	File << name<<" "<<id<<" "<<worker[cnt]->m_post<<" "<<worker[cnt]->m_work<<endl;
	cnt++;
	File.close();

	system("pause");
	system("cls");
}



 //��ʾְ����Ϣ
void Systemwork::Displayemployee() 
{
	int i = 0;
	ifstream inFile("Employee.txt", ios::in|ios::binary);
	char s[100];
	vector<string>v1;
	while (inFile.getline(s,40))//���ļ��е���Ϣ��������ڿ���̨����
	{
		cout << s << endl;

		/*inFile >> s;
		v1.push_back(s);*/
	}
	/*for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i];
		cout << endl;
	}*/
	inFile.close();


	/*while (getline(inFile, *worker))
	{
		
		cout << worker[i]->m_name << " " << worker[i]->m_id << " " << worker[i]->m_post << " " << worker[i]->m_work << endl;

		i++;
	}
	inFile.close();*/

	system("pause");
	system("cls");
}


//ɾ����ְְ��
void Systemwork::Delayemployee()
{
	char d_name[100];
	char d_id[4];

	cout << "��������Ҫɾ����Ա������:" << endl;
	cin >> d_name;
	cout << "��������Ҫɾ����Ա�����:" << endl;
	cin >> d_id;

	for (int i = 0; i < size(worker);i++)//ɾ����vector������ָ����Ա��
	{
		if (worker[i]->m_name == d_name && (char*)worker[i]->m_id == d_id)
		{
			worker.erase(worker.begin() + i);
			break;
		}
	}

	//���ļ���ɾ��ָ��Ա��
	ifstream file("Employee.txt");
	char line[100];
	int count = 0;
	ofstream outfile("test.txt", ios::out | ios::trunc);
	while (!file.eof())
	{
		file.getline(line, 100);
		if (strstr(line, d_name) == NULL && strstr(line,d_id)==NULL)
		{
			outfile << line << endl;
		}
	}
	file.close();
	outfile.close();
	fstream outfile1("Employee.txt", ios::out | ios::trunc);
	fstream file1("test.txt");
	while (!file1.eof())
	{
		file1.getline(line, 100);
		outfile1 << line << endl;
	}
	outfile.seekp(0, ios::end);
	outfile1.close();
	file1.close();
	
	system("del test.txt");//ɾ���м��ļ�

	system("pause");
	system("cls");
}







// �޸�Ա����Ϣ
void Systemwork::Modifyemployee()
{
	char line[100];
	char M_name[10];
	char M_id[4];
	cout << "����������Ҫ�޸ĵ�Ա��������" << endl;
	cin >> M_name;
	cout << "����������Ҫ�޸ĵ�Ա����ţ�" << endl;
	cin >> M_id;
	int b;
	string name;
	int id;
	int ans = 0;

	for (int i = 0; i < worker.size(); i++)
	{
		if (worker[i]->m_name == M_name && (char*)worker[i]->m_id == M_id)
		{
			cout << "��������������:" << endl;
			cin >> name;
			cout << "���������ı��:" << endl;
			cin >> id;

			cout << "����������ְλ��1Ϊ�ϰ壬2Ϊ����3ΪԱ����" << endl;
			cin >> b;
			switch (b)
			{
			case 1:
				worker[i] = new Boss(name, id, "Boss");
				break;
			case 2:
				worker[i] = new Manager(name, id, "Manager");
				break;
			case 3:
				worker[i] = new Staff(name, id, "Staff");
				break;
			default:
				cout << "��Ч��ְλ���룡" << endl;
				break;
			}
			ans = i;
		}
	}

	if (ans == worker.size() - 1 || worker.empty())
	{
		cout << "��������������:" << endl;
		cin >> name;
		cout << "���������ı��:" << endl;
		cin >> id;

		cout << "����������ְλ��1Ϊ�ϰ壬2Ϊ����3ΪԱ����" << endl;
		cin >> b;
		switch (b)
		{
		case 1:
			worker.push_back(new Boss(name, id, "Boss"));
			break;
		case 2:
			worker.push_back(new Manager(name, id, "Manager"));
			break;
		case 3:
			worker.push_back(new Staff(name, id, "Staff"));
			break;
		default:
			cout << "��Ч��ְλ���룡" << endl;
			break;
		}
		ans = worker.size() - 1;
	}

	// ���ļ����ҵ�ָ��Ա�����޸�����Ϣ
	ifstream inFile("Employee.txt", ios::binary | ios::out|ios::in);
	ofstream outFile("test.txt", ios::binary | ios::out);
	while (!inFile.eof())
	{
		inFile.getline(line, 100);
		if (strstr(line, M_name) == NULL && strstr(line,(char*) M_id) == NULL)
		{
			outFile << line<<endl;
		}
		else
		{
			outFile << name << " " << id << " " << worker[ans]->m_post << " " << worker[ans]->m_work << endl;
		}
	}
	outFile.close();
	inFile.close();

	ifstream inFile2("test.txt", ios::binary | ios::out | ios::in);
	ofstream outFile2("Employee.txt", ios::binary | ios::out );
	while (!inFile2.eof())
	{
		inFile2.getline(line, 40);
		outFile2 << line << endl;
	}
	inFile2.close();
	outFile2.close();

	system("del test.txt");
	cout << "�޸ĳɹ���" << endl;
	system("pause");
	system("cls");
}


//����ָ��Ա��
void Systemwork::Findemployee()
{
	char* F_name = new char[4];
	char* F_id = new char[4];
	cout << "����������Ҫ���ҵ�Ա������:" << endl;
	cin >> F_name;
	cout << "����������Ҫ���ҵ�Ա�����:" << endl;
	cin >> F_id;

	char line[40];

	//��vector�����ڲ���
	for (int i = 0; i < size(worker); i++)
	{
		if (worker[i]->m_name == F_name && (char*)worker[i]->m_id == F_id)
		{
			cout << "�����ҵ�����Ϣ���£�" << endl;
			worker[i]->Display();
		}
	}


	int a=0;
	//���ı��ļ��в���
	ifstream File("Employee.txt", ios::in);
	while(!File.eof())
	{
		File.getline(line, 40);
		if (strstr(line, F_name) != NULL && strstr(line, F_id) != NULL)
		{
			a = 1;//����һ���������ж��Ƿ���ҵ��û�
			cout << line << endl;
			break;
		}
	}
	if (a == 1)
	{
		cout << "���ҳɹ���" << endl;
	}
	else
	{
		cout << "û�в��ҵ�ָ���û����û������ڣ�" << endl;
	}

	File.close();
	
	system("pause");
	system("cls");

}


void Systemwork::Sort()
{
	
	cout << "���ڿ�ʼͨ����Ŷ�Ա����������" << endl;
	for (int i = 0; i < size(worker); i++)
	{
		for (int j = 0; j < size(worker) / 2; j++)
		{
			if (worker[j]->m_id < worker[i]->m_id)
			{
				swap(worker[j], worker[i]);
			}
		}
	}


}





void Systemwork::Empty()
{
	ofstream File("Employee.txt", ios::out);
	File.close();
	system("pause");
	system("cls");
}