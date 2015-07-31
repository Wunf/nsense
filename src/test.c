#include <stdio.h>
#include <unistd.h>
#include "nsscene.h"
#include "nsrec.h"

int main(int argc, char * argv[])
{
	NSScene * s = new NSScene(10, 10);
	NSRec * r = new NSRec(3, 3);
	s->AddItem(4, 4, r);
	s->Render();
	s->Flush();
	delete s;
	return 0;	
}
