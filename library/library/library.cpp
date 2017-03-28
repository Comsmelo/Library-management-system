// library.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*ͼ����Ϣ����ģ�� && ͼ�鹺��ģ�� */
/*ͼ����ࣺ���������գ����ģ�ͯ�飬���ܣ���־���Ƽ�������...*/
/*�����磺�����ʵ��ѧ�����磬�廪��ѧ�����磬��е��ҵ������...*/
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
#include<fstream> 
using namespace std;

typedef struct Book_Info
{
	string ID;//ͼ�������  XX(ͼ�����ͣ�XXX(������)XXX(�����������)XXX(ͼ����ˮ��) 
	string Name;//ͼ������ 
	string Publish;//���������� 
	string Author;//�������� 
	string Type;//ͼ������ 
	int State;//�Ƿ�ɽ��ĵ�״̬ ,1Ϊ�ɽ��� 
	int Appointment_Num;//ͼ��ԤԼ���� 
	string Last_Borrow;//��������� 
	string Intro;
	int Reservations;
}Book_Info;

typedef struct Book
{
	vector<Book_Info> Info;
	int Book_Num;
	string ISBN;//�鼮ID��ȥ����λ��ˮ�� 
}Book;

const int maxn = 20;
map<string, int> BookType;//ͼ������ӳ��
map<string, int> BookPublish;//ͼ�������ӳ�� 
map<string, int> PublishBookNum;//���������ͼ��
vector<Book> All_Book;

void Init_Map()
{
	string Type[100] = { "����","����","����","ͯ��","����","��־","�Ƽ�","����" };
	string Publish[500] = { "�����ʵ��ѧ������","�廪��ѧ������","��е��ҵ������" };
	for (int i = 0; Type[i] != ""; i++)
	{
		BookType[Type[i]] = i;
	}
	for (int i = 0; Publish[i] != ""; i++)
	{
		BookPublish[Publish[i]] = i;
	}
	for (int i = 0; i < All_Book.size(); i++)
	{
		PublishBookNum[All_Book[i].Info[1].Publish]++;
	}
}

class Book_Management
{
private:
	vector<Book_Info> Data;
public:
	Book_Management();
	void Book_Init();
	string Code_Form(string Type, string Publish, string Name);//�鼮�������� 
	void Book_Purchase();//ͼ�鹺�� 
	void Book_Remove(Book Old_Book);//ͼ������ 
	void FindBookById(string ID);//��ID����ͼ�� 
	void FindBookByName(string Name);//��ͼ�����ֲ���ͼ�� 
	void FindBookByType(string Type);//��ͼ�����Ͳ��� 
	void FindBookByAuthor(string Author);//���������Ʋ��� 
};

Book_Management::Book_Management()
{

}

Book_Management::~Book_Management()
{

}

void Book_Management::Book_Init()
{
	string information;
	string ISBN, lastISBN;
	Book book;
	Book::iterator it;
	Book_Info book_info;
	ifstream OpenFile("Book_Info.txt", ios::in);//�����ݿ��ļ�
	while (OpenFile.getline(information))
	{
		stringstream ss(information);
		ss >> book_info.ID;
		ss >> book_info.Name;
		ss >> book_info.Author;
		ss >> book_info.Publish;
		ss >> book_info.Intro;
		ss >> book_info.State;
		ss >> book_info.Last_Borrow;
		ss >> book_info.Reservations;
		for (int i = 0; i<8; i++)
			ISBN[i] = book_info.ID[i];
		if (ISBN == lastISBN)
		{
			it = All_Book.end();
			it->Book_Num++;
			it->Info.push_back(book_info);
		}
		else
		{
			book.ISBN = ISBN;
			book.Info.push_back(book_info);
			book.Book_Num++;
			All_Book.push_back(book);
		}
		lastISBN = ISBN;
		ss.clear();
	}
	printf("ͼ����Ϣ��ʼ�����\n");
}

void Book_Management::Book_Purchase()
{
	string Name, Publish, Author, Type, Intro;
	string ISBN;
	string judge;
	int NBook;
	Book book;
	Book_Info book_info;
	cout << "�����ͼ���Ƿ��п�棨YES/NO��";
	cin >> judge;
	if (judge == "YES")
	{
		int num;
		cout << "������ͼ���ISBN:";
			cin >> ISBN;
		for (int i = 0; i<All_Book.size(); i++)
		{
			if (All_Book[i].ISBN == ISBN)
			{
				cout << "�����빺��ͼ����Ŀ:";
				cin >> NBook;
				All_Book[i].Book_Num += NBook;
				break;
			}
		}
	}
	else
	{
		string id;
		cout << "����������ͼ������ƣ�";
		cin >> book_info.Name;
		cout << "�������ͼ��ĳ��������ƣ�";
		cin >> book_info.Publish;
		cout << "�������ͼ�������";
		cin >> book_info.Type;
		cout << "�������ͼ��ļ��";
		cin >> book_info.Intro;
		cout << "�����빺��ͼ����Ŀ:";
		cin >> book.Book_Num;
		/*********************************************************************/
		ISBN = Code_Form(Type, Publish, Name);
		book.ISBN = ISBN;
		book.Info.push_back(book_info);
		All_Book.push_back(book);
		/**********************************************************************************************************
		*************************************************************************************************************
		**************************************************************************************************************/
	}
	printf("����ͼ����Ϣ¼��ɹ�\n");
}

string Book_Management::Code_Form(string Type, string Publish, string Name)//Name������ˮ�������λ
{
	string ID;
	char* something;
	int num;//����ͼ�����Ŀ
	/*********************************ͼ�����Ͳ��ֱ��**********************/
	if (BookType.find(Type) != BookType.end())
	{
		if (BookType[Type] < 10)
		{
			itoa(BookType[Type], something, 10);
			ID += "0" + *something;
		}
		else
		{
			ID += *itoa(BookType[Type], something, 10);
		}
	}
	else
	{
		int num = BookType.size();
		BookType[Type] = num;
		if (BookType[Type] < 10)
		{
			itoa(BookType[Type], something, 10);
			ID += "0" + *something;
		}
		else
		{
			ID += *itoa(BookType[Type], something, 10);
		}
	}
	//********************�����粿�ֱ��*********************************/
	if (BookPublish.find(Publish) != BookPublish.end())
	{
		if (BookPublish[Publish] < 10)
		{
			itoa(BookPublish[Publish], something, 10);
			ID += "00" + *something;
		}
		else if (BookPublish[Publish] >= 10 && BookPublish[Publish]<100)
		{
			ID += "0" + *itoa(BookPublish[Publish], something, 10);
		}
		else
		{
			ID += *itoa(BookPublish[Publish], something, 10);
		}
		PublishBookNum[Publish]++;
	}
	else
	{
		int num1 = BookPublish.size();
		BookPublish[Publish] = num1;
		PublishBookNum[Publish] = 1;
		if (BookPublish[Publish] < 10)
		{
			itoa(BookPublish[Publish], something, 10);
			ID += "00" + *something;
		}
		else if (BookPublish[Publish] >= 10 && BookPublish[Publish]<100)
		{
				ID += "0" + *itoa(BookPublish[Publish], something, 10);
		}
		else
		{
			ID += *itoa(BookPublish[Publish], something, 10);
		}
	}
	/******************************������ͼ����Ŀ���ֱ��*****************************/
	if (PublishBookNum[Publish] < 10)
	{
		itoa(PublishBookNum[Publish], something, 10);
		ID += "00" + *something;
	}
	else if (PublishBookNum[Publish] >= 0 && PublishBookNum[Publish] < 100)
	{
		itoa(PublishBookNum[Publish], something, 10);
		ID += "0" + *something;
	}
	else
	{
		ID += *something;
	}
	return ID;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

