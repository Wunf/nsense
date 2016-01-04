#ifndef __NSCOMPONENT_H__
#define __NSCOMPONENT_H__

extern "C" {
#include <lua.h>
}
#include <string>
#include "nsobject.h"
using namespace std;


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
	class Component : public Object
	{
	public:
		Component(const char * n) : Object(n) {}
		virtual ~Component() {}
	};

	class TranslateCom : public Component
	{
	public:
		TranslateCom(const char * n) : Component(n), x(0), y(0), scaleX(1.0f), scaleY(1.0f) {}
		int x, y;
		float scaleX, scaleY;
	};

	class ShapeCom : public Component
	{
	public:
		ShapeCom(const char * n); 
		void FromStrings(const char ** shape, size_t ln);

	private:
		string shapeStr;
	};

	class ScriptCom : public Component
	{
	public:
		ScriptCom(const char * n) : Component(n) {}
		virtual ~ScriptCom() {}
		void AddScript(const char * script) {}
	};

}

#endif
