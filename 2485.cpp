#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 0x0fffffff
int N,T;
int mat[502][502];
int prim()
{
	int start=0;
	bool visited[502]={false};
	int nearest[502];
	int max_len=-1;
	int min,pos;
	int i,j;
	for(i=0;i<=N;i++)
		nearest[i]=mat[start][i];
	visited[start]=true;
	nearest[start]=0;
	for(i=1;i<N;i++) {
		min=INF;
		for(j=0;j<N;j++) {
			if(!visited[j]&&nearest[j]<min) {
				min=nearest[j];
				pos=j;
			}
		}
		visited[pos]=true;
		if(min>max_len)
			max_len=min;
		for(j=0;j<N;j++)
			if(!visited[j]&&nearest[j]>mat[pos][j])
				nearest[j]=mat[pos][j];
	}
	return max_len;
}
		
int main()
{
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		int i,j;
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				scanf("%d",&mat[i][j]);
		printf("%d\n",prim());
	}
	return 0;
}

