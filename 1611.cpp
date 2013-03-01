#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int father[32002];
void init(int n)
{
	int i;
	for(i=0;i<=n;i++)
		father[i]=i;
}
int find_father(int child)
{
	if(father[child]==child)
		return child;
	father[child]=find_father(father[child]);
	return father[child];
}
void Union(int a,int b)
{
	int f_a=find_father(a);
	int f_b=find_father(b);
	father[f_a]=f_b;
}


int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF) {
		if(n==0&&m==0)
			return 0;
		int i,j,num,a,b;
		init(n);
		for(i=0;i<m;i++) {
			scanf("%d",&num);
			scanf("%d",&a);	
			for(j=1;j<num;j++) {
				scanf("%d",&b);
				Union(a,b);
			}
		}
		int count=0;
		for(i=0;i<n;i++) {
			if(find_father(i)==find_father(0))
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
