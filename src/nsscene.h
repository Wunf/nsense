#ifndef __NSSCENE_H__
#define __NSSCENE_H__

#include "nsobject.h"
#include <vector>

class NSItem;

class NSScene : public NSObject
{
public:
	NSScene(){}
	NSScene(int w, int h);
	virtual ~NSScene() { delete[] frameBuf; }
	inline int Width() { return width; }
	inline int Height() { return height; }
	void AddItem(NSItem * item);
	void Flush();
	void Render();
	int SetBuffer(int x, int y, char c) 
	{
		if(x > width || y >= height) return -1;
		frameBuf[(width + 1) * y + x] = c;
		return 0;
	}

private:
	int width, height;
	char * frameBuf;
	std::vector<NSItem*> items;
	void ClearBuf();
};

#endif
