#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define INF 0x0fffffff
int mat[2002][2002];
int N;
typedef struct Code {
	char str[10];
}Code;
Code codes[2002];
int calc(char *str1,char *str2)
{
	char *p=str1,*q=str2;
	int count=0;
	while(*p&&*q) {
		if((*p)!=(*q))
			count++;
		p++;
		q++;
	}
	return count;
}
int prim()
{
	int start=0;
	bool visited[2002]={false};
	int nearest[2002];
	int min_cost=0;
	int min=INF;
	int pos;
	int i,j;
	for(i=0;i<N;i++)
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
		min_cost+=min;
		visited[pos]=true;
		for(j=0;j<N;j++)
			if(!visited[j]&&nearest[j]>mat[pos][j])
				nearest[j]=mat[pos][j];
	}
	return min_cost;
}
int main()
{
	while(scanf("%d",&N)!=EOF) {
		if(N==0)
			return 0;
		int i,j;
		for(i=0;i<N;i++) {
			scanf("%s",codes[i].str);
		}
		for(i=0;i<N;i++)
			for(j=0;j<=i;j++)
				if(i==j)
					mat[i][j]=INF;
				else mat[j][i]=mat[i][j]=calc(codes[i].str,codes[j].str);
		printf("The highest possible quality is 1/%d.\n",prim());
	}
	return 0;
}	
