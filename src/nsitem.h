#ifndef __NSITEM_H__
#define __NSITEM_H__

#include "nsobject.h"

class NSScene;

class NSItem : public NSObject
{
public:
	NSItem(){}
	virtual ~NSItem(){}
	void SetScene(NSScene * s) { scene = s; }
	virtual void Render(){}

protected:
	NSScene * scene;
};

#endif
