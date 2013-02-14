#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;
int c;
int n,p,q;
int start_x,start_y;
int total_count=0;
bool flag=false;
bool visited[30][30]={false};
typedef struct Node {
	int x,y;
}Node;
Node nodes[8]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
typedef struct Father {
	int x,y;
}Father;
Father father[30][30]={{-1,-1}};
void init()
{
	flag=false;
	memset(visited,false,sizeof(visited));
}
bool check(int x,int y)
{
	if(!(0<=x&&x<p&&0<=y&&y<q))	return false;
	return true;
}	
void out_result(int a,int b)
{
	stack<int> S;
	int x=a,y=b;
	printf("Scenario #%d:\n",c);
	S.push(b);
	S.push(a);
	while(!(father[x][y].x==-1&&father[x][y].y==-1)) {
		S.push(father[x][y].y);
		S.push(father[x][y].x);
		int X=father[x][y].x,Y=father[x][y].y;
		x=X;
		y=Y;
	}
	while(!S.empty()) {
		putchar(S.top()+'A');
		S.pop();
		putchar(S.top()+'1');
		S.pop();
	}
	putchar('\n');
	putchar('\n');
}
void dfs(int x,int y,int count) 
{
	if(flag)	return;
	if(count==total_count) {
		out_result(x,y);
		flag=true;
		return ;
	}
	int i;
	for(i=0;i<8;i++) {
		if(check(x+nodes[i].x,y+nodes[i].y)&&!visited[x+nodes[i].x][y+nodes[i].y]) {
			visited[x+nodes[i].x][y+nodes[i].y]=true;
			father[x+nodes[i].x][y+nodes[i].y].x=x;
			father[x+nodes[i].x][y+nodes[i].y].y=y;
			dfs(x+nodes[i].x,y+nodes[i].y,count+1);
			visited[x+nodes[i].x][y+nodes[i].y]=false;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(c=1;c<=n;c++) {
	here:		scanf("%d%d",&q,&p);
		int i,j;
		total_count=p*q;
		for(i=0;i<p;i++) {
			for(j=0;j<q;j++) {
				visited[i][j]=true;
				father[i][j].x=-1;
				father[i][j].y=-1;
				start_x=i;
				start_y=j;
				dfs(start_x,start_y,1);
				if(flag) {
					init();
					c++;
					if(c<=n)
						goto here;
					else return 0;
				}
				init();
			}
		}
		if(!flag) {
			printf("Scenario #%d:\n",c);
			printf("impossible\n");
			putchar('\n');
		}
	}
	return 0;
}
