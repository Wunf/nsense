#ifndef __NSSCENE_H__
#define __NSSCENE_H__

#include "nsobject.h"
#include <vector>

class NSItem;
class NSComponent;

class NSScene : public NSObject
{
public:
	NSScene(int w, int h);
	virtual ~NSScene();
	inline int Width() { return width; }
	inline int Height() { return height; }
	void AddItem(int l, int t, NSItem * item);
	void AddScript(const char * s);
	void Flush();
	void Render();
	void DoScript();

private:
	int width, height;
	char * frameBuf;
	std::vector<NSComponent*> components;
	void ClearBuf();
};

#endif
