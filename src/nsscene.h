#ifndef __NSSCENE_H__
#define __NSSCENE_H__

#include "nsobject.h"
extern "C" {
#include <lua.h>
}

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

private:
	int width, height;
	char * frameBuf;
	void ClearBuf();
};

#endif
