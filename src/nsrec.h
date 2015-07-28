#ifndef __NSREC_H__
#define __NSREC_H__

#include "nsitem.h"

class NSRec : public NSItem
{
public:
	NSRec(){}
	NSRec(int l, int t, int w, int h) : left(l), top(t), width(w), height(h) {}
	~NSRec(){}
	void Render();

private:
	int left, top, width, height;
};

#endif
