
#ifndef _CMS_CMS_H_ 
#define _CMS_CMS_H_ 

#include "Contact.h"

#include <vector>

using namespace std; 

class CMS {

private: 
	vector<Contact> database; 
	size_t max_capacity; 

protected: 
	; 

public: 
	CMS (size_t max_capacity); 
	~CMS ( ); 


};

#endif // _CMS_CMS_H_ 
