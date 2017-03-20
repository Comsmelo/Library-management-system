/*ͼ����Ϣ����ģ�� && ͼ�鹺��ģ�� */ 
/*ͼ����ࣺ���������գ����ģ�ͯ�飬���ܣ���־���Ƽ�������...*/
/*�����磺�����ʵ��ѧ�����磬�廪��ѧ�����磬��е��ҵ������...*/
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn = 20;
map<string, int> BookType;//ͼ������ӳ��
map<string, int> BookPublish;//ͼ�������ӳ�� 

typedef struct Book_Info
{
	string ID;//ͼ�������  XX(ͼ�����ͣ�XXX(������)XXX(�����������)XXX(ͼ����ˮ��) 
	string Name;//ͼ������ 
	string Publish;//���������� 
	string Auther;//�������� 
	string Type;//ͼ������ 
	int State;//�Ƿ�ɽ��ĵ�״̬ ,1Ϊ�ɽ��� 
	int Appointment_Num;//ͼ��ԤԼ���� 
	string Last_Borrow;//��������� 
	string Intro;
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

Book_Management::Book_Init()
{
	 
 } 
 
 Book_Management::Book_Purchase()
 {
 	string Name, Publish, Auther, Type, Intro;
	int NBook; 
 	cout<<"����������ͼ������ƣ�"; 
 	cin>>Name;
 	cout<<"�������ͼ��ĳ��������ƣ�";
 	cin>>Publish;
 	cout<<"�������ͼ�������";
	cin>>Type;
	cout<<"�������ͼ��Ĺ�������" ;
	cin>>NBook;
	cout<<"�������ͼ��ļ��";
	cin>>Intro�� 
  } 
 
 
 
 
 
