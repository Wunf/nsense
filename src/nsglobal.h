#ifndef __NSGLOBAL__H__
#define __NSGLOBAL__H__

#include <vector>
#include "nsobject.h"
#include "nscomponent.h"

using namespace std;

class NSGlobal
{
public:
	NSGlobal(){ }
	void AddObject(NSObject * o) { objects.push_back(o); }
	NSObject* FindObjectByName(const char * n); 
	NSComponent* FindComponentByName(const char * n); 
	const char * curobjname;

private:
	vector<NSObject*> objects;
	vector<NSComponent*> components;
};

#endif
