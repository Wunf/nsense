#include "nsscene.h"
#include "nsitem.h"
#include "nscomponent.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
extern "C"{
#include <lua.h>
#include <lauxlib.h>
}


NSScene::NSScene(const char * n, int w, int h) : NSObject(n), width(w), height(h)
{ 
	frameBuf = new char[(w + 1) * h + 1];
	ClearBuf();
}

NSScene::~NSScene()
{
	delete[] frameBuf;
	for(int i = 0; i < components.size(); ++i)
	{
		delete components[i];
	}
	components.clear();
}

void NSScene::ClearBuf()
{
	memset(frameBuf, '*', (width + 1) * height);
	for(int i = 0; i < height; ++i) frameBuf[i * (width + 1) + width] = '\n';
	frameBuf[(width + 1) * height] = '\0';
}

void NSScene::Flush()
{
	system("clear");
	printf("%s", frameBuf);	
	fflush(stdout);
}

void NSScene::Render()
{
	ClearBuf();
	for(std::vector<NSComponent*>::iterator iter = components.begin(); iter != components.end(); ++iter)
	{
		(*iter)->Render(frameBuf, width, height);
	}
}

