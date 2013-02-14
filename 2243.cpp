#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
using namespace std;
char pos_start[3],pos_end[3];
bool visited[20][20]={false};
int dis[20][20]={0};
typedef struct Node {
	int x,y;
}Node;
Node nodes[8]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
void init()
{
	memset(visited,false,sizeof(visited));
	int i,j;
	for(i=0;i<20;i++) 
		for(j=0;j<20;j++)
			dis[i][j]=0;
}
bool check(int x,int y)
{
	if(!(1<=x&&x<=8&&0<=y&&y<=7))	return false;
	return true;
}
int bfs(int s_x,int s_y,int e_x,int e_y)
{
	queue<int> Q;
	Q.push(s_x);
	Q.push(s_y);
	dis[s_x][s_y]=0;
	while(!Q.empty()) {
		int x=Q.front();
		Q.pop();
		int y=Q.front();
		Q.pop();
		if(x==e_x&&y==e_y)	return dis[x][y];
		visited[x][y]=true;
		int i;
		for(i=0;i<8;i++) {
			if(check(x+nodes[i].x,y+nodes[i].y)&&!visited[x+nodes[i].x][y+nodes[i].y]) {
				Q.push(x+nodes[i].x);
				Q.push(y+nodes[i].y);
				dis[x+nodes[i].x][y+nodes[i].y]=dis[x][y]+1;
			}
		}
	}		
}

int main()
{
	while(scanf("%s%s",pos_start,pos_end)!=EOF) {
		int start_x=pos_start[1]-'0';
		int start_y=pos_start[0]-'a';
		int end_x=pos_end[1]-'0';
		int end_y=pos_end[0]-'a';
		int moves=bfs(start_x,start_y,end_x,end_y);
		init();
		printf("To get from %s to %s takes %d knight moves.\n",pos_start,pos_end,moves);
	}
	return 0;
}
