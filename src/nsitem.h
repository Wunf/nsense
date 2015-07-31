#ifndef __NSITEM_H__
#define __NSITEM_H__

#include "nsobject.h"

class NSItem : public NSObject
{
public:
	NSItem(int w, int h) : width(w), height(h) { buffer = new char[width * height]; }
	virtual ~NSItem(){}
	virtual void Render(){}
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	char* GetBuffer() { return buffer; }

protected:
	int width, height;
	char * buffer;
	inline void SetBuffer(int x, int y, char c)
	{
		buffer[y * width + x] = c;
	}
};

#endif
