
#ifndef _CMS_PERSON_H_
#define _CMS_PERSON_H_

#include <string> 

using namespace std;

class Person {

private:
	;

protected:
	string name; // 姓名
	string gender; // 性别
	string remark; // 备注

public:
	Person ( );
	virtual ~Person ( );

	virtual const int Set (const string& flag, const string& value) = 0; 
	virtual const string& Get (const string& flag) const; 
};

#endif // _CMS_PERSON_H_
