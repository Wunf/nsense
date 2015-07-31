#ifndef __NSREC_H__
#define __NSREC_H__

#include "nsitem.h"

class NSRec : public NSItem
{
public:
	NSRec(int w, int h) : NSItem(w, h) {}
	virtual ~NSRec(){}
	virtual void Render();
};

#endif
