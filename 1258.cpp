#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 0x0fffffff
int N;
int mat[102][102];
int prim()
{
	int start=1;
	int nearest[102];
	bool visited[102]={false};
	int i,j;
	for(i=1;i<=N;i++)
		nearest[i]=mat[start][i];
	int min=INF;
	int pos;
	int min_cost=0;
	visited[start]=true;
	nearest[start]=0;
	for(i=1;i<N;i++) {
		min=INF;
		for(j=1;j<=N;j++) {
			if(!visited[j]&&nearest[j]<min) {
				min=nearest[j];
				pos=j;
			}
		}
		visited[pos]=true;
		min_cost+=min;
		for(j=1;j<=N;j++)
			if(nearest[j]>mat[pos][j])
				nearest[j]=mat[pos][j];
	}
	return min_cost;
}
int main()
{
	while(scanf("%d",&N)!=EOF) {
		int i,j;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				scanf("%d",&mat[i][j]);
		printf("%d\n",prim());
	}
	return 0;
}	
