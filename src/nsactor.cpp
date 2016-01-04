#include "nsactor.h"
#include "nscomponent.h"
#include <string.h>

namespace NS
{
	Component * Newif(const char * type, const char * name);

	void Actor::AddComponent(const char * type, const char * name)
	{
		Component * com = Newif(type, name);	
		if(com)
		{
			namemap[name] = coms.size();	
			coms.push_back(com);
		}
	}

	Component * Actor::FindComponentByName(const char * name)
	{
		return coms[namemap[name]];
	}

	Component * Newif(const char * type, const char * name)
	{
		if(!strcmp(type, "Translate"))
		{
			return new TranslateCom(name);	
		}

		if(!strcmp(type, "Shape"))
		{
			return new ShapeCom(name);	
		}	

		return NULL;
	}
}
