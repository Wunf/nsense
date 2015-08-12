#ifndef __NSITEM_H__
#define __NSITEM_H__

#include "nsobject.h"

class NSItem : public NSObject
{
public:
	NSItem(const char * n, int w, int h) : NSObject(n), width(w), height(h) { buffer = new char[width * height]; }
	virtual ~NSItem(){delete[] buffer;}
	virtual void Render(){}
	virtual int GetWidth() { return width; }
	virtual int GetHeight() { return height; }
	virtual char* GetBuffer() { return buffer; }

protected:
	int width, height;
	char * buffer;
	inline void SetBuffer(int x, int y, char c)
	{
		buffer[y * width + x] = c;
	}
};

#endif
