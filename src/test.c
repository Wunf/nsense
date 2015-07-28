#include <stdio.h>
#include "nsscene.h"
#include "nsrec.h"

int main(int argc, char * argv[])
{
	NSScene * s = new NSScene(10, 10);
	NSRec * r = new NSRec(4, 4, 3, 3);
	s->AddItem(r);
	s->Render();
	s->Flush();
	delete s;
	delete r;
	return 0;	
}
