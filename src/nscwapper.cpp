#include <vector>
#include <unistd.h>
#include "nscwapper.h"
#include "nsscene.h"
#include "nsitem.h"
#include "nsrec.h"
#include "nsglobal.h"

extern NSGlobal global;

void nsmakescenecwapper(const char * n, int w, int h)
{
	NSScene * s = new NSScene(n, w, h);
	global.AddObject(s);
}

void nsmakereccwapper(const char * n, int w, int h)
{
	NSRec * r = new NSRec(n, w, h);
	global.AddObject(r);
}

void nsputcwapper(const char * n, int l, int t)
{
	NSObject * o = global.FindObjectByName(n);
	NSObject * p = global.FindObjectByName(global.curobjname);
	p->AddObject(o, l, t);
}

void nsaddscriptcwapper(lua_State * L, const char * n, const char * s)
{
	NSObject * o = global.FindObjectByName(n);
	o->AddScript(L, s);
}

void nsruncwapper(lua_State * L, const char * n)
{
	NSScene * s = dynamic_cast<NSScene*>(global.FindObjectByName(n));
	while(true)	
	{
		if(s)
		{
			s->Render();
			s->Flush();
			s->Update(L);
			sleep(2);
		}
	}
}
