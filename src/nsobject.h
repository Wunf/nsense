#ifndef __NSOBJECT_H__
#define __NSOBJECT_H__

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}
#include <vector>
#include <string>
using namespace std;

class NSComponent;

class NSObject
{
public:
	NSObject(const char * n) : name(n), script(NULL) {}
	virtual ~NSObject(){}
	virtual const char * Name(){ return name; }
	virtual void AddScript(){}
	virtual void AddObject(NSObject * o, int l, int t); 
	virtual void Render(){}
	virtual int GetWidth(){}
	virtual int GetHeight(){}
	virtual char * GetBuffer(){}
	virtual void AddScript(lua_State * L, const char * s);
	virtual void Update(lua_State * L);

protected:
	std::vector<NSComponent*> components;
	const char * name;
	const char * script;
};

namespace NS
{
	class Object
	{
	public:
		Object() {}
		Object(const char * n) : name(n) {}
		virtual ~Object() {}
		const char * Name(){ return name.c_str(); }

	private:
		string name;
	};
}

#endif
