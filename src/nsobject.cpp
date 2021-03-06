#include "nsobject.h"
#include "nsglobal.h"
#include "nscomponent.h"
#include <stdlib.h>

extern NSGlobal global;

void NSObject::AddScript(lua_State * L, const char * s){
	global.curobjname = name;
	script = s;
	if(luaL_loadfile(L, s) || lua_pcall(L, 0, 0, 0))
	{
		printf("%s\n", lua_tostring(L, -1));
		exit(0);
	}
	lua_getglobal(L, name);	
	if(!lua_istable(L, -1))
		exit(0);
	lua_getfield(L, -1, "Init");
	if(lua_pcall(L, 0, 0, 0) != LUA_OK)
	{
		printf("%s\n", lua_tostring(L, -1));
		exit(0);
	}
}

void NSObject::AddObject(NSObject * o, int l, int t)
{
	NSComponent * c = new NSComponent(o, l, t);
	global.AddComponent(c);
	components.push_back(c);
}

void NSObject::Update(lua_State * L)
{
	if(script)
	{
		global.curobjname = name;
		lua_getglobal(L, name);	
		if(!lua_istable(L, -1))
			exit(0);
		lua_getfield(L, -1, "Update");
		if(lua_pcall(L, 0, 0, 0) != LUA_OK)
		{
			printf("%s\n", lua_tostring(L, -1));
			exit(0);
		}
	}

	for(std::vector<NSComponent*>::iterator iter = components.begin(); iter != components.end(); ++iter)
	{
		(*iter)->Update(L);
	}	
}
