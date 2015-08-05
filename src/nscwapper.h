#ifndef __NSCWAPPER_H__
#define __NSCWAPPER_H__

extern "C" void nsmakescenecwapper(int w, int h);
extern "C" void nsmakereccwapper(int w, int h);
extern "C" void nsadd2scenecwapper(int n, int l, int t);
extern "C" void nsaddscriptcwapper(const char * s);
extern "C" void nsruncwapper(void);

#endif
