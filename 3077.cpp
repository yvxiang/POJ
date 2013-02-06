#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void trans(int *p,int base)
{
	if((*p)<(int)pow(10,base))	return;
	if((*p)==pow(10,base))	return;
	if((*p)>pow(10,base)) {
		int tail=(*p)%(int)pow(10,base);
		if(2*tail>=(int)pow(10,base)) {
			*p=(*p)/(int)pow(10,base)*(int)pow(10,base)+(int)pow(10,base);
		} else *p=(*p)/(int)pow(10,base)*(int)pow(10,base);
		trans(p,base+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--) {
		int number;
		scanf("%d",&number);
		trans(&number,1);
		printf("%d\n",number);
	}
	return 0;
}
