extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

void nsmakescenecwapper(int w, int h);
void nsmakereccwapper(int w, int h);
void nsadd2scenecwapper(int n, int l, int t);
void nsaddscriptcwapper(const char * s);
void nsruncwapper(void);

static int nsmakescene(lua_State * L)
{
	int w = luaL_checkinteger(L, 1), h = luaL_checkinteger(L, 2);
	nsmakescenecwapper(w, h);
	return 0;
}

static int nsmakerec(lua_State * L)
{
	int w = luaL_checkinteger(L, 1), h = luaL_checkinteger(L, 2);
	nsmakereccwapper(w, h);
	return 0;
}

static int nsadd2scene(lua_State * L)
{
	int n = luaL_checkinteger(L, 1), l = luaL_checkinteger(L, 2), t = luaL_checkinteger(L, 3);
	nsadd2scenecwapper(n, l, t);
	return 0;
}

static int nsaddscript(lua_State * L)
{
	const char * s = luaL_checkstring(L, 1);	
	nsaddscriptcwapper(s);
	return 0;
}

static int nsrun(lua_State * L)
{
	nsruncwapper();
}

int luaopen_nsense(lua_State * L)
{
	luaL_checkversion(L);
	luaL_Reg l[] = {
		{ "run", nsrun },	
		{ "makescene", nsmakescene },	
		{ "makerec", nsmakerec },	
		{ "add2scene", nsadd2scene },	
		{ "addscript", nsaddscript },	
		{ NULL, NULL }	
	};
	luaL_newlib(L, l);
	return 1;
}
}
