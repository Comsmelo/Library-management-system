/*ͼ����Ϣ����ģ�� && ͼ�鹺��ģ�� */ 
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn = 20;

typedef struct Book_Info
{
	string ID;//ͼ������� 
	string Name;//ͼ������ 
	string Publish;//���������� 
	string Auther;//�������� 
	string Type;//ͼ������ 
	int State;//�Ƿ�ɽ��ĵ�״̬ 
	int Appointment_Num;//ͼ��ԤԼ���� 
	string Last_Borrow;//��λ������ 
 }Book_Info;
 
typedef struct Book
{
	vector<Book> Info;
	int Book_Num;
}Book;
 
class Book_Management
{
	private:
		vector<Book_Info> Data;
	public:
		Book_Management();
		void Book_Init(); 
		void Book_Purchase(Book New_Book);//ͼ�鹺�� 
		void Book_Remove(Book Old_Book);//ͼ������ 
		void FindBookById(string ID);//��ID����ͼ�� 
		void FindBookByName(string Name);//��ͼ�����ֲ���ͼ�� 
		void FindBookByType(string Type);//��ͼ�����Ͳ��� 
		void FindBookByAuthor(string Author);//���������Ʋ��� 
};

