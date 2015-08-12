#ifndef __NSREC_H__
#define __NSREC_H__

#include "nsitem.h"

class NSRec : public NSItem
{
public:
	NSRec(const char * n, int w, int h) : NSItem(n, w, h) {}
	virtual ~NSRec(){}
	virtual void Render();
};

#endif
