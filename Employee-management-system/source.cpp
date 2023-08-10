#include"head.h"
#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;
void Systemwork::Interface()
{
	cout <<  "********************************************"<< endl;
	cout << "**********  欢迎使用职工管理系统  ***********" << endl;
	cout << "************   0.退出管理程序  **************" << endl;
	cout << "************   1.增加职工信息  **************" << endl;
	cout << "************   2.显示职工信息  **************" << endl;
	cout << "************   3.删除离职职工  **************" << endl;
	cout << "************   4.修改职工信息  **************" << endl;
	cout << "************   5.查找职工信息  **************" << endl;
	cout << "************   6.按照编号排序  **************" << endl;
	cout << "************   7.清空所有文档  **************" << endl;
	cout << "********************************************" << endl;
}


void Systemwork::Employee()   //创建文件操作
{
	fstream File("Employee.txt", ios::app);
	if (!File)
	{
		cout << "error! 文件不存在，职工管理系统无法使用！" << endl;
	}
	
}




//增加职工信息
void Systemwork::Addemployee()    
{
	static int cnt=0;
	string name; int id;
	int b;
	
	
	cout << "请输入它的姓名:" << endl;
	cin >> name;
	cout << "请输入它的编号:" << endl;
	cin >> id;

	cout << "请输入它的职位，1为老板，2为经理，3为员工：" << endl;
	cin >> b;
	switch (b)
	{
	case 1:worker.push_back(new Boss(name,id,"Boss"));
	case 2:worker.push_back(new Manager(name,id,"Manager"));
	case 3:worker.push_back(new Staff(name,id,"Staff"));
	}

	
	fstream File("Employee.txt", ios::in|ios::app); //将员工信息写入文件当中
	if (!File)
	{
		cout << "error 文件未打开" << endl;
	}
	File << name<<" "<<id<<" "<<worker[cnt]->m_post<<" "<<worker[cnt]->m_work<<endl;
	cnt++;
	File.close();

	system("pause");
	system("cls");
}



 //显示职工信息
void Systemwork::Displayemployee() 
{
	int i = 0;
	ifstream inFile("Employee.txt", ios::in|ios::binary);
	char s[100];
	vector<string>v1;
	while (inFile.getline(s,40))//将文件中的信息逐条输出在控制台当中
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


//删除离职职工
void Systemwork::Delayemployee()
{
	char d_name[100];
	char d_id[4];

	cout << "输入你想要删除的员工姓名:" << endl;
	cin >> d_name;
	cout << "输入你想要删除的员工编号:" << endl;
	cin >> d_id;

	for (int i = 0; i < size(worker);i++)//删除在vector容器中指定的员工
	{
		if (worker[i]->m_name == d_name && (char*)worker[i]->m_id == d_id)
		{
			worker.erase(worker.begin() + i);
			break;
		}
	}

	//在文件中删除指定员工
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
	
	system("del test.txt");//删除中间文件

	system("pause");
	system("cls");
}







// 修改员工信息
void Systemwork::Modifyemployee()
{
	char line[100];
	char M_name[10];
	char M_id[4];
	cout << "请输入您想要修改的员工姓名：" << endl;
	cin >> M_name;
	cout << "请输入您想要修改的员工编号：" << endl;
	cin >> M_id;
	int b;
	string name;
	int id;
	int ans = 0;

	for (int i = 0; i < worker.size(); i++)
	{
		if (worker[i]->m_name == M_name && (char*)worker[i]->m_id == M_id)
		{
			cout << "请输入它的姓名:" << endl;
			cin >> name;
			cout << "请输入它的编号:" << endl;
			cin >> id;

			cout << "请输入它的职位，1为老板，2为经理，3为员工：" << endl;
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
				cout << "无效的职位输入！" << endl;
				break;
			}
			ans = i;
		}
	}

	if (ans == worker.size() - 1 || worker.empty())
	{
		cout << "请输入它的姓名:" << endl;
		cin >> name;
		cout << "请输入它的编号:" << endl;
		cin >> id;

		cout << "请输入它的职位，1为老板，2为经理，3为员工：" << endl;
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
			cout << "无效的职位输入！" << endl;
			break;
		}
		ans = worker.size() - 1;
	}

	// 在文件中找到指定员工并修改其信息
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
	cout << "修改成功！" << endl;
	system("pause");
	system("cls");
}


//查找指定员工
void Systemwork::Findemployee()
{
	char* F_name = new char[4];
	char* F_id = new char[4];
	cout << "请输入您想要查找的员工姓名:" << endl;
	cin >> F_name;
	cout << "请输入您想要查找的员工编号:" << endl;
	cin >> F_id;

	char line[40];

	//在vector容器内查找
	for (int i = 0; i < size(worker); i++)
	{
		if (worker[i]->m_name == F_name && (char*)worker[i]->m_id == F_id)
		{
			cout << "您查找到的信息如下：" << endl;
			worker[i]->Display();
		}
	}


	int a=0;
	//在文本文件中查找
	ifstream File("Employee.txt", ios::in);
	while(!File.eof())
	{
		File.getline(line, 40);
		if (strstr(line, F_name) != NULL && strstr(line, F_id) != NULL)
		{
			a = 1;//增添一个变量，判断是否查找到用户
			cout << line << endl;
			break;
		}
	}
	if (a == 1)
	{
		cout << "查找成功！" << endl;
	}
	else
	{
		cout << "没有查找到指定用户，用户不存在！" << endl;
	}

	File.close();
	
	system("pause");
	system("cls");

}


void Systemwork::Sort()
{
	
	cout << "现在开始通过编号对员工进行排序" << endl;
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