
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
	类内部采用三层函数调用结构设计
	第一层为用户交互层，包括系统菜单和功能菜单，可根据用户输入调用相应功能
	第二层为调用关系转换层，对用户的输入进行解析和定向
	第三层为功能实现层，接受上一层的调用，完成对内存数据库的相关操作
	*/

	// 系统菜单
	void Menu();

	// 用于菜单调用的函数
	void Reveal();
	void Insert();
	void Update();
	void Delete();

	// 调用关系转换函数
	int Search(const string flag, const string query); 
	int Insert(const string name, const string tel, const string pc, const string email); 
	int Update(int index); 
	int Delete(int index); 
	int Reveal(int index); 
	int ChkInput(const string flag, string& input); 

	// 底层操作函数
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
