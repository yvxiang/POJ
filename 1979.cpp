#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int W,H;
char map[22][22];
int count=0;
bool check(int x,int y)
{
	if(!(1<=x&&x<=H&&1<=y&&y<=W))	return false;
	return true;
}
void dfs(int x,int y)
{
	if(!check(x,y))	return ;
	if(map[x][y]=='.'||map[x][y]=='@') {
		count++;
		map[x][y]='#';
		dfs(x,y-1);
		dfs(x-1,y);
		dfs(x,y+1);
		dfs(x+1,y);
	}
}
int main()
{
	while(scanf("%d%d",&W,&H)!=EOF) {
		if(W==H&&W==0)	return 0;
		int i,j,start_x,start_y;
		for(i=1;i<=H;i++) { 
			getchar();
			for(j=1;j<=W;j++) {
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@') {
					start_x=i;
					start_y=j;
				}
			}
		}
		count=0;
		dfs(start_x,start_y);
		printf("%d\n",count);
	}
}	
