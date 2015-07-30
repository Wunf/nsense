#ifndef __NSREC_H__
#define __NSREC_H__

#include "nsitem.h"

class NSRec : public NSItem
{
public:
	NSRec(){}
	NSRec(int l, int t, int w, int h) : NSItem(l, t, w, h) {}
	~NSRec(){}
	void Render();
};

#endif
