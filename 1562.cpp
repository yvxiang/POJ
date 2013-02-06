#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int m,n;
char map[102][102];
void find(int *x,int *y)
{
	int i,j;
	for(i=1;i<=m;i++) 
		for(j=1;j<=n;j++)
			if(map[i][j]=='@') {
				*x=i;
				*y=j;
				return;
			}
}
bool check(int x,int y)
{
	if(1<=x&&x<=m&&1<=y&&y<=n)	return true;
	return false;
}
void dfs(int x,int y)
{
	if(!check(x,y))	return;
	if(map[x][y]!='@')	return;
	map[x][y]='*';
	dfs(x-1,y-1);
	dfs(x,y-1);
	dfs(x+1,y-1);
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x-1,y+1);
	dfs(x,y+1);
	dfs(x+1,y+1);
}
int main()
{
	while(scanf("%d%d",&m,&n)!=EOF) {
		if(m==n&&m==0)	return 0;
		int i,j;
		char ch;
		while(ch=getchar()!='\n')	;	
		for(i=1;i<=m;i++) {
			for(j=1;j<=n;j++) {
				scanf("%c",&map[i][j]);
			}
			while(ch=getchar()!='\n')	;
		}
		int x=-1,y=-1;
		find(&x,&y);
		int total_field=0;
		while(check(x,y)) {
			total_field++;
			dfs(x,y);
			x=y=-1;
			find(&x,&y);
		}
		printf("%d\n",total_field);
	}
	return 0;
}
