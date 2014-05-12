
#ifndef _CMS_CMSUI_H_ 
#define _CMS_CMSUI_H_ 

#include "CMS.h"

class CMSUI {

private:
	;

protected:
	CMS cms;
	virtual void Reveal ( ) = 0;
	virtual void Insert ( ) = 0;
	virtual void Update ( ) = 0;
	virtual void Delete ( ) = 0;

public:
	CMSUI ( );
	virtual ~CMSUI ( );

};

#endif // _CMS_CMSUI_H_ 
