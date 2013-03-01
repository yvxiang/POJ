#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int numbers[10002];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF) {
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&numbers[i]);
		sort(numbers,numbers+n);
		printf("%d\n",numbers[n/2]);
	}
	return 0;
}
