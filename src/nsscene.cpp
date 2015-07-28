#include "nsscene.h"
#include "nsitem.h"
#include <stdio.h>
#include <memory.h>

NSScene::NSScene(int w, int h) : width(w), height(h)
{ 
	frameBuf = new char[(w + 1) * h + 1];
	memset(frameBuf, ' ', (w + 1) * h);
	for(int i = 0; i < height; ++i) SetBuffer(w, i, '\n'); 
	frameBuf[(w + 1) * h + 1] = '\0';
}

void NSScene::Flush()
{
	printf("%s", frameBuf);	
}

void NSScene::AddItem(NSItem * item)
{
	items.push_back(item);
	item->SetScene(this);
}

void NSScene::Render()
{
	for(std::vector<NSItem*>::iterator iter = items.begin(); iter != items.end(); ++iter)
	{
		(*iter)->Render();
	}
}
