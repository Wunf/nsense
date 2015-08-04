#include <vector>
#include <unistd.h>
#include "nscwapper.h"
#include "nsscene.h"
#include "nsitem.h"
#include "nsrec.h"

static std::vector<NSScene*> scenes;
static NSItem * curItem;

void nsmakescenecpp(int w, int h)
{
	NSScene * s = new NSScene(w, h);
	scenes.push_back(s);
}

void nsmakereccpp(int w, int h)
{
	NSRec * r = new NSRec(w, h);
	curItem = r;
}

void nsadd2scenecpp(int n, int l, int t)
{
	if(n > scenes.size()) return;
	scenes[n - 1]->AddItem(l, t, curItem);
}

void nsruncpp(void)
{
	int n = 0;
	NSScene * s = scenes[n];
	while(true)	
	{
		if(s)
		{
			s->Render();
			s->Flush();
			sleep(0.5);
		}
		else
		{
			s = scenes[++n];
		}
	}
	for(int i = 0; i < scenes.size(); ++i)
	{
		delete scenes[i];
	}
	scenes.clear();
}
