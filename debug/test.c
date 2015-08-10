#include <unistd.h>
#include "../src/nscwapper.h"

int main(int argc, char * argv[])
{
	nsmakescenecwapper(10, 15);
	nsmakereccwapper(4, 5);
	nsadd2scenecwapper(1, 3, 4);
	nsruncwapper();
	return 0;
}
