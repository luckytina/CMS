
#ifndef _CMS_PERSON_H_ 
#define _CMS_PERSON_H_ 

#include <string> 

using std::string; 

class Person {
private: 
	string name; 
	string tel; 
	string pc; 
	string email; 
public: 
	Person() { }
	Person(const string name, const string tel, const string pc, const string email); 
	~Person() { };

	const string GetName() const { return name; }
	const string GetTel() const { return tel; }
	const string GetPC() const { return pc; }
	const string GetEmail() const { return email; }

	void SetName(const string name) { this->name = name; }
	void SetTel(const string tel) { this->tel = tel; }
	void SetPC(const string pc) { this->pc = pc; }
	void SetEmail(const string email) { this->email = email; }

};

#endif // _CMS_PERSON_H_ 
