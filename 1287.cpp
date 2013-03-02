#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int P,R;
typedef struct Route {
	int u,v,w;
}Route;
Route routes[2052];
int father[52];
int rank[52];
void init()
{
	int i;
	for(i=1;i<=P;i++) {
		father[i]=i;
		rank[i]=0;
	}
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
	if(a==b)
		return ;
	if(rank[a]>rank[b]) {
		father[b]=a;
		rank[a]++;
	}
	else {
		father[a]=b;
		rank[b]++;
	}
		
}
bool cmp(Route a,Route b)
{
	if(a.w!=b.w)
		return a.w<b.w;
	return a.u<b.u;
}
int main()
{
	while(scanf("%d",&P)!=EOF) {
		if(P==0)
			return 0;
		scanf("%d",&R);
		int i,j;
		init();
		for(i=0;i<R;i++)
			scanf("%d%d%d",&routes[i].u,&routes[i].v,&routes[i].w);
		sort(routes,routes+R,cmp);
		int sum=0;
		for(i=0;i<R;i++) {
			int fa=find_father(routes[i].u);
			int fb=find_father(routes[i].v);
			if(fa!=fb) {
				sum+=routes[i].w;
				Union(fa,fb);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
