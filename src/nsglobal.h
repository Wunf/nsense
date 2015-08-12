#ifndef __NSGLOBAL__H__
#define __NSGLOBAL__H__

#include <vector>
#include "nsobject.h"

using namespace std;

class NSGlobal
{
public:
	NSGlobal(){ }
	void AddObject(NSObject * o) { objects.push_back(o); }
	NSObject* FindObjectByName(const char * n); 
	const char * curobjname;

private:
	vector<NSObject*> objects;
};

#endif
