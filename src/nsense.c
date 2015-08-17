extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

void nsmakescenecwapper(const char * n, int w, int h);
void nsmakereccwapper(const char * n, int w, int h);
void nsputcwapper(const char * n, int l, int t);
void nsaddscriptcwapper(lua_State * L, const char * n, const char * s);
void nsruncwapper(lua_State * L, const char * n);
void nsmoveupcwapper(const char * n, int s);
void nsmovedowncwapper(const char * n, int s);
void nspositioncwapper(const char * n, int &l, int &t);

static int nsmakescene(lua_State * L)
{
	const char * n = luaL_checkstring(L, 1);
	int w = luaL_checkinteger(L, 2), h = luaL_checkinteger(L, 3);
	nsmakescenecwapper(n, w, h);
	return 0;
}

static int nsmakerec(lua_State * L)
{
	const char * n = luaL_checkstring(L, 1);	
	int w = luaL_checkinteger(L, 2), h = luaL_checkinteger(L, 3);
	nsmakereccwapper(n, w, h);
	return 0;
}

static int nsput(lua_State * L)
{
	const char * n = luaL_checkstring(L, 1);
	int l = luaL_checkinteger(L, 2), t = luaL_checkinteger(L, 3);
	nsputcwapper(n, l, t);
	return 0;
}

static int nsaddscript(lua_State * L)
{
	const char * n = luaL_checkstring(L, 1);	
	const char * s = luaL_checkstring(L, 2);	
	nsaddscriptcwapper(L, n, s);
	return 0;
}

static int nsrun(lua_State * L)
{
	const char * n = luaL_checkstring(L, 1);	
	nsruncwapper(L, n);
}

static int nsmoveup(lua_State * L)
{
	const char * n = luaL_checkstring(L, 1);	
	int s = luaL_checkinteger(L, 2);
	nsmoveupcwapper(n, s);
}

static int nsmovedown(lua_State * L)
{
	const char * n = luaL_checkstring(L, 1);	
	int s = luaL_checkinteger(L, 2);
	nsmovedowncwapper(n, s);
}

static int nsposition(lua_State * L)
{
	const char * n = luaL_checkstring(L, 1);	
	int l = 0, t = 0;
	nspositioncwapper(n, l, t);
	lua_pushinteger(L, l);
	lua_pushinteger(L, t);
	return 2;
}


int luaopen_nsense(lua_State * L)
{
	luaL_checkversion(L);
	luaL_Reg l[] = {
		{ "run", nsrun },	
		{ "makescene", nsmakescene },	
		{ "makerec", nsmakerec },	
		{ "put", nsput },	
		{ "addscript", nsaddscript },	
		{ "moveup", nsmoveup },	
		{ "movedown", nsmovedown },	
		{ "position", nsposition },	
		{ NULL, NULL }	
	};
	luaL_newlib(L, l);
	return 1;
}
}
