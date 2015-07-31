#ifndef __NSCOMPONENT_H__
#define __NSCOMPONENT_H__

extern "C" {
#include <lua.h>
}

class NSScene;
class NSItem;

class NSComponent
{
public:
	NSComponent(NSItem * i, int l, int t) : item(i), left(l), top(t), L(NULL) {}
	~NSComponent();
	void MoveUp(int s);
	void DoScript(const char * f);
	void SetScene(NSScene * s) { scene = s; }
	void Render(char * b, int bw, int bh);

private:
	NSItem * item;
	int left, top;	
	lua_State * L;
	NSScene * scene;
	int InitScript();
};

int mvup(lua_State * L);

#endif
