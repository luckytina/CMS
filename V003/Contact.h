
#ifndef _CMS_CONTACT_H_ 
#define _CMS_CONTACT_H_ 

#include "Person.h"

#include <string> 

using namespace std;

class Contact : public Person {

private:
	;

protected:
	string tel;
	string group;
	string email;

public:
	Contact ( );
	~Contact ( );

	const int Set (string& flag, string& value); 
	const string& Get (const string& flag) const; 

};

#endif // _CMS_CONTACT_H_ 
