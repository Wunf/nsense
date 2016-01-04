#include "nscomponent.h"
#include "nsobject.h"
#include <iostream>
using namespace std;

NSComponent::NSComponent(NSObject * o, int l, int t) : item(o), left(l), top(t), name(o->Name()) {}

NSComponent::~NSComponent()
{ delete item; }

void NSComponent::Moveup(int s)
{
	top -= s;
}

void NSComponent::Movedown(int s)
{
	top += s;
}

void NSComponent::Position(int &l, int &t)
{
	t = top; 
	l = left;
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

void NSComponent::Update(lua_State * L)
{
	item->Update(L);	
}

namespace NS
{
	ShapeCom::ShapeCom(const char * n) : Component(n) {}

	void ShapeCom::FromStrings(const char ** shape, size_t ln)
	{
		for(unsigned int i = 0; i < ln; ++i)		
		{
			shapeStr += string(shape[i]);	
		}
		cout << shapeStr << endl;
	}
}
