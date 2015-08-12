#ifndef __NSOBJECT_H__
#define __NSOBJECT_H__

extern "C" {
#include <lua.h>
}

class NSObject
{
public:
	NSObject(const char * n) : name(n){}
	virtual ~NSObject(){}
	virtual const char * Name(){ return name; }
	virtual void AddScript(){}
	virtual void AddObject(NSObject * o, int l, int t) {}
	virtual void Render(){}
	virtual int GetWidth(){}
	virtual int GetHeight(){}
	virtual char * GetBuffer(){}
	virtual void AddScript(lua_State * L, const char * s){}
protected:
	const char * name;
};

#endif
