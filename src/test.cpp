#include <iostream>
#include "nsactor.h"
#include "nscomponent.h"

using namespace std;
using namespace NS;

int main(int argc, char * argv[])
{
	Actor actor;
	actor.AddComponent("Translate", "t1");
	actor.AddComponent("Shape", "s1");
	ShapeCom * sc = dynamic_cast<ShapeCom*>(actor.FindComponentByName("s1"));
	const char * strs[1];
	strs[0] = "--------------";
	sc->FromStrings(strs, 1);
	return 0;
}
