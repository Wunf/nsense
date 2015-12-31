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
	void Movedown(int s);
	void Position(int &l, int &t);
	void AddScript(const char * s);
	void Render(char * b, int bw, int bh);
	void Update(lua_State * L);
	const char * Name() {return name;}

private:
	NSObject * item;
	const char * name;
	int left, top;	
};

namespace NS
{
	class Component
	{
	public:
		Component() {}
		virtual ~Component() {}
	};

	class ScriptCom : public Component
	{
	public:
		ScriptCom() {}
		virtual ~ScriptCom() {}
		void AddScript(const char * script) {}
	};

}

#endif
