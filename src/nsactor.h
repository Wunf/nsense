#ifndef __NSACTOR_H__
#define __NSACTOR_H__

#include "nsobject.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

namespace NS
{
	class Component;

	class Actor : public Object
	{
	public:
		Actor() {}
		virtual ~Actor() {}
		void AddComponent(const char * type, const char * name);
		Component * FindComponentByName(const char * name);

	protected:
		vector<Component*> coms;	

	private:
		map<string, unsigned int> namemap;
	};
}

#endif
