
#include "cms.h" 

#include <iostream> 
#include <conio.h> 
#include <cctype> 
#include <cstring> 
#include <Windows.h> 

// 构造函数，初始化最大容量，调用系统菜单
CMS::CMS(unsigned max) {
	maxsize = max; 
	Menu();
	return; 
}

// 可有可无的析构函数
CMS::~CMS() {
	maxsize = 0; 
	return; 
}

// *******************************************
// 用户交互层
// *******************************************

// 系统菜单，根据输入调用功能函数
void CMS::Menu() { 

	while (true) {
		system("cls"); 
		cout << "=============================" << endl
			<< "1. Show contacts" << endl
			<< "2. Add a new contact" << endl
			<< "3. Change contact info" << endl
			<< "4. Delete a contact" << endl
			<< "0. Exit" << endl
			<< "=============================" << endl; 

		switch (_getch()) {
		case '0': 
			cout << "Good bye~~" << endl; 
			Sleep(1000); 
			exit(0); 
		case '1': Reveal(); break; 
		case '2': Insert(); break; 
		case '3': Update(); break; 
		case '4': Delete(); break; 
		default: break; // 继续循环直至输入正确
		}
	}

	return; 
}

// 分类显示功能
void CMS::Reveal() {
	cout << "Please select the class to reveal: " << endl
		<< "1. Office" << endl
		<< "2. Personal" << endl
		<< "3. Business" << endl
		<< "0. Back" << endl; 
	int index = -1; 
	while (true) {
		switch (_getch()) {
		case '0':
			return;
		case '1': 
			while ((index = Search("pc", "Office")) != -1) {
				Reveal(index); 
			}
			cout << endl
				<< "End of reveal." << endl
				<< "Press any key to continue. " << endl; 
			_getch(); 
			return; 
		case '2': 
			while ((index = Search("pc", "Personal")) != -1) {
				Reveal(index); 
			}
			cout << endl
				<< "End of reveal." << endl
				<< "Press any key to continue. " << endl;
			_getch();
			return;
		case '3': 
			while ((index = Search("pc", "Business")) != -1) {
				Reveal(index); 
			}
			cout << endl
				<< "End of reveal." << endl
				<< "Press any key to continue. " << endl;
			_getch();
			return;
		default:
			break; 
		}
	}
}

// 新加联系人
void CMS::Insert() {
	string name, tel, pc, email; 
	do {
		cout << "Please enter the person name: ";
		cin >> name;
	} while (ChkInput("name", name) || (Search("name", name) != -1)); 
	do {
		cout << "Please enter the telephone number: "; 
		cin >> tel; 
	} while (ChkInput("tel", tel) || (Search("tel", tel) != -1));
	do {
		cout << "Please enter the personal class: "; 
		cin >> pc; 
	} while (ChkInput("pc", pc)); 
	do {
		cout << "Please enter the email address: "; 
		cin >> email; 
	} while (ChkInput("email", email) || (Search("email", email) != -1));
	Insert(name, tel, pc, email); 
}

// 更新联系人信息
void CMS::Update() {
	string query; 
	cout << "Please select the query dependancy: " << endl
		<< "1. Query by name" << endl
		<< "2. Query by telephone number" << endl
		<< "3. Query by email address" << endl
		<< "0. Back" << endl; 
	while (true) {
		switch (_getch()) {
		case '0': 
			return; 
		case '1': 
			cout << "Please enter the name: "; 
			cin >> query; 
			Update(Search("name", query)); 
			return; 
		case '2':
			cout << "Please enter the telephone number: "; 
			cin >> query; 
			Update(Search("tel", query)); 
			return; 
		case '3':
			cout << "Please enter the email address: "; 
			cin >> query; 
			Update(Search("email", query)); 
			return; 
		default:
			break;
		}
	}
}

// 删除指定联系人
void CMS::Delete() {
	string query; 
	cout << "Please select the query dependancy: " << endl
		<< "1. Query by name" << endl
		<< "2. Query by telephone number" << endl
		<< "3. Query by email address" << endl
		<< "0. Back" << endl;
	while (true) {
		switch (_getch()) {
		case '0':
			return;
		case '1':
			cout << "Please enter the name: ";
			cin >> query;
			Delete(Search("name", query));
			return;
		case '2':
			cout << "Please enter the telephone number: ";
			cin >> query;
			Delete(Search("tel", query));
			return;
		case '3':
			cout << "Please enter the email address: ";
			cin >> query;
			Delete(Search("email", query));
			return;
		default:
			break;
		}
	}
}

// *******************************************
// 调用关系转换层
// *******************************************

// 解析flag并据query进行查询，若未找到返回-1，否则返回下标
int CMS::Search(const string flag, const string query) {
	if (flag == "name") {
		return search_by_name(query); 
	}
	else if (flag == "tel") {
		return search_by_tel(query); 
	}
	else if (flag == "pc") {
		return search_by_pc(query); 
	}
	else if (flag == "email") {
		return search_by_email(query); 
	}
	else {
		cerr << "Unexpected query flag! " << endl
			<< "Press any key to exit..."; 
		_getch(); 
		exit(-1); 
	}
}

// 若数据库未满则插入联系人信息
int CMS::Insert(const string name, const string tel, const string pc, const string email) {
	if (database.size() == maxsize) {
		cout << "Unable to add a new contact. " << endl
			<< "The CMS database is full. " << endl; 
		return -1; 
	}
	else {
		database.push_back(Person(name, tel, pc, email)); 
		return 0; 
	}
}

// 更新指定下标的联系人信息
int CMS::Update(int index) {
	if (index == -1) {
		cout << endl
			<< "Can not find the specified contact! " << endl
			<< "Press any key to continue. " << endl; 
		_getch(); 
		return -1; 
	}
	else {
		string update;
		cout << "Please select the attribution you want to change: " << endl
			<< "1. Name" << endl
			<< "2. Telephone number" << endl
			<< "3. Personal class" << endl
			<< "4. Email address" << endl
			<< "0. Cancel" << endl;
		while (true) {
			switch (_getch()) {
			case '0':
				return 0;
			case '1':
				do {
					cout << "Please enter the new name: ";
					cin >> update;
				} while (ChkInput("name", update) || (Search("name", update) != -1));
				database[index].SetName(update);
				return 0;
			case '2':
				do {
					cout << "Please enter the new telephone number: ";
					cin >> update;
				} while (ChkInput("tel", update) || (Search("tel", update) != -1));
				database[index].SetTel(update);
				return 0;
			case '3':
				do {
					cout << "Please enter the new personal class: ";
					cin >> update;
				} while (ChkInput("pc", update));
				database[index].SetPC(update);
				return 0;
			case '4':
				do {
					cout << "Please enter the new email address: ";
					cin >> update;
				} while (ChkInput("email", update) || (Search("email", update) != -1));
				database[index].SetEmail(update);
				return 0;
			default:
				break;
			}
		}
	}
}

// 删除指定下标联系人
int CMS::Delete(int index) {
	if (index == -1) {
		cout << endl
			<< "Can not find the specified contact! " << endl
			<< "Press any key to continue. " << endl;
		_getch();
		return -1;
	}
	else {
		database.erase(database.begin() + index); 
		return 0; 
	}
}

// 显示指定下标联系人
int CMS::Reveal(int index) {
	if (index == -1) {
		return -1; 
	}
	else {
		Person& p = database[index]; 
		cout << endl 
			<< "No." << index + 1 << endl
			<< "Name: " << p.GetName() << endl
			<< "Telephone number: " << p.GetTel() << endl
			<< "Personal class: " << p.GetPC() << endl
			<< "Email address: " << p.GetEmail() << endl;
		return 0; 
	}
}

// 解析flag并对输入进行检验，检验通过返回0，否则返回错误码
int CMS::ChkInput(const string flag, string& input) {
	if (flag == "name") {
		return check_name(input); 
	}
	else if (flag == "tel") {
		return check_tel(input); 
	}
	else if (flag == "pc") {
		return check_pc(input); 
	}
	else if (flag == "email") {
		return check_email(input); 
	}
	else {
		cerr << "Unexpected input flag! " << endl
			<< "Press any key to exit..."; 
		_getch(); 
		exit(-2); 
	}
}

// *******************************************
// 功能实现层
// *******************************************

// 根据姓名查找
int CMS::search_by_name(const string name) {
	for (unsigned i = 0; i < database.size(); i++) {
		if (cmp_ignore_case(database[i].GetName(), name)) {
			return i; 
		}
	}
	return -1; 
}

// 根据手机号查找
int CMS::search_by_tel(const string tel) {
	for (unsigned i = 0; i < database.size(); i++) {
		if (database[i].GetTel() == tel) {
			return i; 
		}
	}
	return -1; 
}

// 根据类别查找
int CMS::search_by_pc(const string pc) {
	static unsigned i = 0; 
	for (; i < database.size(); i++) {
		if (database[i].GetPC() == pc) {
			return i++; 
		}
	}
	i = 0; 
	return -1; 
}

// 根据邮箱查找
int CMS::search_by_email(const string email) {
	for (unsigned i = 0; i < database.size(); i++) {
		if (cmp_ignore_case(database[i].GetEmail(), email)) {
			return i; 
		}
	}
	return -1; 
}

// 检验姓名
int CMS::check_name(const string name) {
	for (unsigned i = 0; i < name.length(); i++) {
		if (!isalpha(name[i])) {
			return -1; 
		}
	}
	return 0; 
}

// 检验手机号
int CMS::check_tel(const string tel) {
	if (tel.length() != 11) {
		return -1; 
	}
	else if (tel[0] != '1') {
		return -2; 
	}
	else {
		for (unsigned i = 1; i < tel.length(); i++) {
			if (!isdigit(tel[i])) {
				return -3; 
			}
		}
		return 0; 
	}
}

// 检验类别
int CMS::check_pc(string& pc) {
	if (pc == "Office" || pc == "office" || pc == "O" || pc == "o") {
		pc = "Office";
		return 0;
	}
	else if (pc == "Personal" || pc == "personal" || pc == "P" || pc == "p") {
		pc = "Personal";
		return 0;
	}
	else if (pc == "Business" || pc == "business" || pc == "B" || pc == "b") {
		pc = "Business";
		return 0;
	}
	else if (pc == "Null" || pc == "null" || pc == "N" || pc == "n") {
		pc = "Null"; 
		return 0; 
	}
	else {
		return -1; 
	}
}

// 检验邮箱
int CMS::check_email(const string email) {
	int atpos = email.find('@'); 
	if (atpos == string::npos) {
		return -1; 
	}
	else {
		string userid = email.substr(0, atpos); 
		string domain = email.substr(atpos + 1, email.length() - atpos - 1); 
		for each (const char ch in userid) {
			if (!isalnum(ch)) {
				return -2; 
			}
		}
		for each (const char ch in domain) {
			if (!isalnum(ch) && ch != '.') {
				return -3; 
			}
		}
		if (domain.length() < 3 || !isalnum(domain[domain.length() - 1]) || !isalnum(domain[domain.length() - 2])) {
			return -4; 
		}
		else {
			return 0; 
		}
	}
}

// 忽略大小写比较两字符串，若相等返回1，否则返回0
int CMS::cmp_ignore_case(const string& str1, const string& str2) {
	return !_stricmp(str1.c_str(), str2.c_str()); 
}
