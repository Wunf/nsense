extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

void nsmakescenecpp(int w, int h);
void nsmakereccpp(int w, int h);
void nsadd2scenecpp(int n, int l, int t);
void nsruncpp(void);

static int nsmakescene(lua_State * L)
{
	int w = luaL_checkinteger(L, 1), h = luaL_checkinteger(L, 2);
	nsmakescenecpp(w, h);
	return 0;
}

static int nsmakerec(lua_State * L)
{
	int w = luaL_checkinteger(L, 1), h = luaL_checkinteger(L, 1);
	nsmakereccpp(w, h);
	return 0;
}

static int nsadd2scene(lua_State * L)
{
	int n = luaL_checkinteger(L, 1), l = luaL_checkinteger(L, 1), t = luaL_checkinteger(L, 1);
	nsadd2scenecpp(n, l, t);
	return 0;
}

static int nsrun(lua_State * L)
{
	nsruncpp();
}

int luaopen_nsense(lua_State * L)
{
	luaL_checkversion(L);
	luaL_Reg l[] = {
		{ "run", nsrun },	
		{ "makescene", nsmakescene },	
		{ "makerec", nsmakerec },	
		{ "add2scene", nsadd2scene },	
		{ NULL, NULL }	
	};
	luaL_newlib(L, l);
	return 1;
}
}
