#include "nscomponent.h"
#include "nsobject.h"

NSComponent::~NSComponent()
{ delete item; }

void NSComponent::MoveUp(int s)
{
	top -= s;
}

void NSComponent::Render(char * b, int bw, int bh)
{
	item->Render();
	int w = item->GetWidth(), h = item->GetHeight();
	char * ib = item->GetBuffer();
	for(int i = 0; i < w; ++i)
	{
		for(int j = 0; j < h; ++j)
		{	
			int x = left + i - 1, y = top + j - 1;	
			if(x >= bw || y >= bh || x < 0 || y < 0) continue;
			b[y * (bw + 1) + x] = ib[j * w + i];
		}
	}	
}
