#include "nscomponent.h"
#include "nsscene.h"
#include "nsitem.h"
extern "C" {
#include <lauxlib.h>
}

NSComponent * curCom;

NSComponent::~NSComponent()
{ delete item; }

int NSComponent::InitScript()
{
	L = luaL_newstate(); 
	//luaL_openlibs(L);

	int swidth = scene->Width();
	lua_pushnumber(L, swidth);
	lua_setglobal(L, "scenewid");

	int sheight = scene->Height();
	lua_pushnumber(L, sheight);
	lua_setglobal(L, "scenehgt");
	
	lua_register(L, "Moveup", mvup);
}

void NSComponent::DoScript(const char * f)
{
	if(!L) InitScript();	
	curCom = this;
	luaL_dofile(L, f);
}

void NSComponent::MoveUp(int s)
{
	top -= s;
}

void NSComponent::Render(char * b, int bw, int bh)
{
	item->Render();
	int w = item->GetWidth(), h = item->GetHeight();
	char * ib = item->GetBuffer();
	for(int i = 0; i < w; ++i)
	{
		for(int j = 0; j < h; ++j)
		{	
			int x = left + i, y = top + j;	
			b[y * (bw + 1) + x] = ib[j * w + i];
		}
	}	
}

int mvup(lua_State * L)
{
	int s = lua_tonumber(L, -1);
	curCom->MoveUp(s);
}
