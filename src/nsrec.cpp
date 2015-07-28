#include "nsrec.h"
#include "nsscene.h"

void NSRec::Render()
{
	for(int i = 1; i < width - 1; ++i)
	{
		scene->SetBuffer(left + i, top, '-');
		scene->SetBuffer(left + i, top + height - 1, '-');
	}
	for(int i = 1; i < height - 1; ++i)
	{
		scene->SetBuffer(left, top + i, '|');
		scene->SetBuffer(left + width - 1, top + i, '|');
	}
	scene->SetBuffer(left, top, '-');
	scene->SetBuffer(left + width - 1, top, '-');
	scene->SetBuffer(left, top + height - 1, '-');
	scene->SetBuffer(left + width - 1, top + height - 1, '-');
}
