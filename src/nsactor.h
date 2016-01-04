#ifndef __NSACTOR_H__
#define __NSACTOR_H__

#include "nsobject.h"
#include <vector>
#include <map>
#include <string>

namespace NS
{
	class Component;
	using namespace std;

	class Actor : public Object
	{
	public:
		Actor() {}
		virtual ~Actor() {}
		void AddComponent(const char * type);

	protected:
		vector<Component*> coms;	

	private:
		map<string, vector<unsigned int> > typemap;
	};
}

#endif
