#ifndef __NSITEM_H__
#define __NSITEM_H__

#include "nsobject.h"

extern "C" {
#include <lua.h>
}

class NSScene;

class NSItem : public NSObject
{
public:
	NSItem() : L(NULL) {}
	NSItem(int l, int t, int w, int h) : left(l), top(t), width(w), height(h), L(NULL) {}
	virtual ~NSItem(){}
	void SetScene(NSScene * s) { scene = s; }
	virtual void Render(){}
	void MoveUp(int s);
	void DoScript(const char * f);

protected:
	NSScene * scene;
	int left, top, width, height;

private:
	lua_State * L;
	int InitScript();
};

int mvup(lua_State * L);

#endif
