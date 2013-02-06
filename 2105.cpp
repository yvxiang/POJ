#include <stdio.h>
#include <stdlib.h>
int main()
{
	char str[]="1234aBc";
	int res;
	printf("%ld\n",strtol(str,0,13));
	return 0;
}
