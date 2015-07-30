#include "nsitem.h"
#include "nsscene.h"
extern "C" {
#include <lauxlib.h>
}

NSItem * curItem;

int NSItem::InitScript()
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

void NSItem::DoScript(const char * f)
{
	if(!L) InitScript();	
	curItem = this;
	luaL_dofile(L, f);
}

void NSItem::MoveUp(int s)
{
	top -= s;
}

int mvup(lua_State * L)
{
	int s = lua_tonumber(L, -1);
	curItem->MoveUp(s);
}

