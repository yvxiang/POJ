#include <stdio.h>
int numbers[500001];
bool flags[500001*10]={false};
int main()
{
	int i;
	numbers[0]=0;
	flags[0]=true;
	numbers[1]=1;
	flags[1]=true;
	for(i=2;i<=500000;i++) {
		if(numbers[i-1]-i>0&&(flags[numbers[i-1]-i]==false)) {
			numbers[i]=numbers[i-1]-i;
			flags[numbers[i]]=true;
		} else {
			numbers[i]=numbers[i-1]+i;
			flags[numbers[i]]=true;
		}
	}
	int k;
	while(scanf("%d",&k)!=EOF) {
		if(k==-1)	return 0;
		printf("%d\n",numbers[k]);
	}
	return 0;
}
	
