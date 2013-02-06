#include <stdio.h>
#include <algorithm>
using namespace std;
long long numbers[10002];
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF) {
		int i;
		for(i=0;i<N;i++) 
			scanf("%lld",&numbers[i]);
		sort(numbers,numbers+N);
		int j;
		long long sum=0;
		for(i=0;i<N;i++) {
			for(j=i+1;j<N;j++) {
				sum+=numbers[j]-numbers[i];
			}
		}
		printf("%lld\n",sum*2);
	}
	return 0;
}
		
