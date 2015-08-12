#include "nsscene.h"
#include "nsitem.h"
#include "nscomponent.h"
#include "nsglobal.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
extern "C"{
#include <lua.h>
#include <lauxlib.h>
}

extern NSGlobal global;

NSScene::NSScene(const char * n, int w, int h) : NSObject(n), width(w), height(h)
{ 
	frameBuf = new char[(w + 1) * h + 1];
	ClearBuf();
}

NSScene::~NSScene()
{
	delete[] frameBuf;
	for(int i = 0; i < components.size(); ++i)
	{
		delete components[i];
	}
	components.clear();
}

void NSScene::ClearBuf()
{
	memset(frameBuf, '*', (width + 1) * height);
	for(int i = 0; i < height; ++i) frameBuf[i * (width + 1) + width] = '\n';
	frameBuf[(width + 1) * height] = '\0';
}

void NSScene::Flush()
{
	system("clear");
	printf("%s", frameBuf);	
	fflush(stdout);
}

void NSScene::AddObject(NSObject * o, int l, int t)
{
	NSComponent * c = new NSComponent(o, l, t);
	components.push_back(c);
	components.back()->SetScene(this);
}

void NSScene::AddScript(lua_State * L, const char * s)
{
	global.curobjname = name;
	if(luaL_loadfile(L, s) || lua_pcall(L, 0, 0, 0))
	{
		printf("%s\n", lua_tostring(L, -1));
		exit(0);
		return;
	}
	lua_getglobal(L, name);	
	if(!lua_istable(L, -1))
		return;
	lua_getfield(L, -1, "Init");
	if(lua_pcall(L, 0, 0, 0) != LUA_OK)
		return;
}

void NSScene::Render()
{
	ClearBuf();
	for(std::vector<NSComponent*>::iterator iter = components.begin(); iter != components.end(); ++iter)
	{
		(*iter)->Render(frameBuf, width, height);
	}
}

