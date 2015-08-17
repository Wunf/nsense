#ifndef __NSCOMPONENT_H__
#define __NSCOMPONENT_H__

extern "C" {
#include <lua.h>
}
class NSObject;

class NSComponent
{
public:
	NSComponent(NSObject * o, int l, int t);
	~NSComponent();
	void Moveup(int s);
	void AddScript(const char * s);
	void Render(char * b, int bw, int bh);
	void Update(lua_State * L);
	const char * Name() {return name;}

private:
	NSObject * item;
	const char * name;
	int left, top;	
};

#endif
