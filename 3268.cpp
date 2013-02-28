#include <stdio.h>
#include <stdlib.h>
#define INF 0x0fffffff
int M,N,X;
int mat[1005][1005];
int nearest_array[1005];
int final[1005];
void dijkstra()
{
	bool visited[1002]={false};
	int min=-1*INF;
	int pos;
	int i,j;
	for(i=1;i<=N;i++)
		nearest_array[i]=mat[X][i];
	visited[X]=true;
	nearest_array[X]=0;
	for(i=1;i<N;i++) {
		min=INF;
		pos=0;
		for(j=1;j<=N;j++) {
			if(!visited[j]&&nearest_array[j]<min) {
				min=nearest_array[j];
				pos=j;
			}
		}
		visited[pos]=true;
		for(j=1;j<=N;j++) {
			if(!visited[j]&&nearest_array[j]>min+mat[pos][j])
				nearest_array[j]=min+mat[pos][j];
		}
	}
}

void init()
{
	int i,j;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			mat[i][j]=INF;
}
void roate()
{
	int i,j,temp;
	for(i=1;i<=N;i++)
		for(j=1;j<i;j++) {
			temp=mat[i][j];
			mat[i][j]=mat[j][i];
			mat[j][i]=temp;
		}
}
void check_mat()
{
	int i,j;
	for(i=1;i<=N;i++) {
		printf("\n");
		for(j=1;j<=N;j++)
			printf("%10d ",mat[i][j]);
	}
}
int main()
{
	while(scanf("%d%d%d",&N,&M,&X)!=EOF) {
		int i,j,a,b,temp;
		init();
		for(i=1;i<=M;i++) {
			scanf("%d%d%d",&a,&b,&temp);
			mat[a][b]=temp;
		}
		/*check_mat();*/
		dijkstra();
		for(i=1;i<=N;i++)
			final[i]=nearest_array[i];
		roate();
		dijkstra();
		int max_time=0;
		for(i=1;i<=N;i++) 
			if(max_time<final[i]+nearest_array[i])
				max_time=final[i]+nearest_array[i];
		printf("%d\n",max_time);
	}
	return 0;
}
