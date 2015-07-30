#include "nsscene.h"
#include "nsitem.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

NSScene::NSScene(int w, int h) : width(w), height(h)
{ 
	frameBuf = new char[(w + 1) * h + 1];
	ClearBuf();
}

void NSScene::ClearBuf()
{
	memset(frameBuf, ' ', (width + 1) * height);
	for(int i = 0; i < height; ++i) SetBuffer(width, i, '\n'); 
	frameBuf[(width + 1) * height + 1] = '\0';
}

void NSScene::Flush()
{
	system("clear");
	printf("%s", frameBuf);	
	fflush(stdout);
}

void NSScene::AddItem(NSItem * item)
{
	items.push_back(item);
	item->SetScene(this);
}

void NSScene::Render()
{
	ClearBuf();
	for(std::vector<NSItem*>::iterator iter = items.begin(); iter != items.end(); ++iter)
	{
		(*iter)->Render();
	}
}
