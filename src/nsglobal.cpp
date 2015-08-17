#include "nsglobal.h"
#include <string.h>

NSGlobal global;

NSObject* NSGlobal::FindObjectByName(const char * n) 
{
	for(vector<NSObject*>::iterator iter = objects.begin(); iter != objects.end(); ++iter)
	{
		const char * curname = (*iter)->Name();
		if(!curname) continue;
		if(!strcmp(curname, n)) return (*iter);
	}	
}

NSComponent* NSGlobal::FindComponentByName(const char * n) 
{
	for(vector<NSComponent*>::iterator iter = components.begin(); iter != components.end(); ++iter)
	{
		const char * curname = (*iter)->Name();
		if(!curname) continue;
		if(!strcmp(curname, n)) return (*iter);
	}	
}
