#include "nsactor.h"
#include "nscomponent.h"
#include <string.h>

namespace NS
{
	void Actor::AddComponent(const char * type)
	{
		if(!strcmp(type, "Translate"))
		{
			TranslateCom * newtc = new TranslateCom(0, 0);	
			typemap["Translate"].push_back(coms.size());	
			coms.push_back(newtc);
		}
	}
}
