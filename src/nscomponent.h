#ifndef __NSCOMPONENT_H__
#define __NSCOMPONENT_H__

extern "C" {
#include <lua.h>
}
class NSScene;
class NSObject;

class NSComponent
{
public:
	NSComponent(NSObject * o, int l, int t) : item(o), left(l), top(t) {}
	~NSComponent();
	void MoveUp(int s);
	void AddScript(const char * s);
	void Render(char * b, int bw, int bh);
	void Update(lua_State * L);

private:
	NSObject * item;
	int left, top;	
};

#endif
