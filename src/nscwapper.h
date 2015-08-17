#ifndef __NSCWAPPER_H__
#define __NSCWAPPER_H__
extern "C" {
#include <lua.h>
}

extern "C" void nsmakescenecwapper(const char * n, int w, int h);
extern "C" void nsmakereccwapper(const char * n, int w, int h);
extern "C" void nsputcwapper(const char * n, int l, int t);
extern "C" void nsaddscriptcwapper(lua_State * L, const char * n, const char * s);
extern "C" void nsruncwapper(lua_State * L, const char * n);
extern "C" void nsmoveupcwapper(const char * n, int s);

#endif
