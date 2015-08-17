#ifndef __NSSCENE_H__
#define __NSSCENE_H__

#include "nsobject.h"

class NSItem;

class NSScene : public NSObject
{
public:
	NSScene(const char * n, int w, int h);
	virtual ~NSScene();
	inline int Width() { return width; }
	inline int Height() { return height; }
	void Flush();
	void Render();
	virtual void AddScript(lua_State * L, const char * s);

private:
	int width, height;
	char * frameBuf;
	void ClearBuf();
};

#endif
