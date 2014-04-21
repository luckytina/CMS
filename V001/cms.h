
#ifndef _CMS_CMS_H_ 
#define _CMS_CMS_H_ 

#include "Person.h"

#include <vector> 

using namespace std; 

class CMS {

private: 
	vector<Person> database; 
	size_t maxsize; 

	/*
	���ڲ��������㺯�����ýṹ���
	��һ��Ϊ�û������㣬����ϵͳ�˵��͹��ܲ˵����ɸ����û����������Ӧ����
	�ڶ���Ϊ���ù�ϵת���㣬���û���������н����Ͷ���
	������Ϊ����ʵ�ֲ㣬������һ��ĵ��ã���ɶ��ڴ����ݿ����ز���
	*/

	// ϵͳ�˵�
	void Menu();

	// ���ڲ˵����õĺ���
	void Reveal();
	void Insert();
	void Update();
	void Delete();

	// ���ù�ϵת������
	int Search(const string flag, const string query); 
	int Insert(const string name, const string tel, const string pc, const string email); 
	int Update(int index); 
	int Delete(int index); 
	int Reveal(int index); 
	int ChkInput(const string flag, string& input); 

	// �ײ��������
	int search_by_name(const string name); 
	int search_by_tel(const string tel); 
	int search_by_pc(const string pc); 
	int search_by_email(const string email); 
	int check_name(const string name); 
	int check_tel(const string tel); 
	int check_pc(string& pc);
	int check_email(const string email); 
	int cmp_ignore_case(const string&, const string&); 

protected: 
	; 

public: 
	CMS(unsigned max_cap); 
	~CMS(); 

};

#endif // _CMS_CMS_H_ 
