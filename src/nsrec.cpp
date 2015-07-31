#include "nsrec.h"
#include "nsscene.h"
#include <memory.h>

void NSRec::Render()
{
	memset(buffer, ' ', width * height);
	for(int i = 1; i < width - 1; ++i)
	{
		SetBuffer(i, 0, '-');
		SetBuffer(i, height - 1, '-');
	}
	for(int i = 1; i < height - 1; ++i)
	{
		SetBuffer(0, i, '|');
		SetBuffer(width - 1, i, '|');
	}
	SetBuffer(0, 0, '-');
	SetBuffer(width - 1, 0, '-');
	SetBuffer(0, height - 1, '-');
	SetBuffer(width - 1, height - 1, '-');
}

