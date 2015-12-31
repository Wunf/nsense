#ifndef __NSACTOR_H__
#define __NSACTOR_H__

#include "nsobject.h"
#include <vector>

namespace NS
{
	class Component;

	class Actor : public Object
	{
	public:
		Actor() {}
		virtual ~Actor() {}

	protected:
		std::vector<Component*> coms;	
	};
}

#endif
