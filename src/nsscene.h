#ifndef __NSSCENE_H__
#define __NSSCENE_H__

#include "nsobject.h"
#include <vector>
extern "C" {
#include <lua.h>
}

class NSItem;
class NSComponent;

class NSScene : public NSObject
{
public:
	NSScene(const char * n, int w, int h);
	virtual ~NSScene();
	inline int Width() { return width; }
	inline int Height() { return height; }
	virtual void AddObject(NSObject * item, int l, int t);
	virtual void AddScript(lua_State * L, const char * s);
	void Flush();
	void Render();

private:
	int width, height;
	char * frameBuf;
	std::vector<NSComponent*> components;
	void ClearBuf();
};

#endif
