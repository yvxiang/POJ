#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
int N,K;
bool visited_flag[100002]={false};
bool check(int x)
{
	if(0<=x&&x<=100000)
		return true;
	return false;
}
void bfs()
{
	queue<int> Q;
	Q.push(N);
	Q.push(0);
	visited_flag[N]=true;
	int cur_pos;
	int cur_deep;
	while(!Q.empty()) {
		cur_pos=Q.front();
		Q.pop();
		cur_deep=Q.front();
		Q.pop();
		if(cur_pos==K) {
			printf("%d\n",cur_deep);
			return ;
		}
		if(check(cur_pos-1)&&!visited_flag[cur_pos-1]) {
			Q.push(cur_pos-1);
			Q.push(cur_deep+1);
			visited_flag[cur_pos-1]=true;
		}
		if(check(cur_pos+1)&&!visited_flag[cur_pos+1]) {
			Q.push(cur_pos+1);
			Q.push(cur_deep+1);
			visited_flag[cur_pos+1]=true;
		}
		if(check(2*cur_pos)&&!visited_flag[cur_pos*2]) {
			Q.push(cur_pos*2);
			Q.push(cur_deep+1);
			visited_flag[cur_pos*2]=true;
		}
	}
}
int main()
{
	while(scanf("%d%d",&N,&K)!=EOF) {
		memset(visited_flag,false,sizeof(visited_flag));
		bfs();
	}
	return 0;
}

