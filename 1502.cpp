#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x0fffffff
int n;
int mat[102][102]={0};
void init() 
{
	int i,j;
	for(i=0;i<=100;i++)
		for(j=0;j<=100;j++)
			mat[i][j]=INF;
}
void input_from_string(char *str,int row)
{
	char *p=str;
	int pos=0;
	int cur_num=0;
	while(*p) {
		if((*p)!='x'&&(*p)!=' ') {
			cur_num=cur_num*10+(*p)-'0';
			p++;
		} else if((*p)==' '||(*p)=='x') {
			if(cur_num==0)
				mat[pos][row]=mat[row][pos]=INF;
			else {
				mat[pos][row]=mat[row][pos]=cur_num;
				cur_num=0;
			}
			if(*p=='x')	p++;
			p++;
			pos++;
		}
	}
	if(cur_num==0)
		mat[pos][row]=mat[row][pos]=INF;
	else mat[pos][row]=mat[row][pos]=cur_num;
}
int dijkstra()
{
	int i,j;
	int strart_pos=0;
	int nearest[102];
	bool visited[102]={false};
	for(i=0;i<n;i++) {
		nearest[i]=mat[0][i];
		visited[i]=false;
	}
	int near=INF;
	nearest[0]=0;
	int pos=0;
	for(i=0;i<n;i++) {
		near=INF;
		for(j=0;j<n;j++) {
			if(!visited[j]&&nearest[j]<near) {
				near=nearest[j];
				pos=j;
			}
		}
		visited[pos]=true;
		for(j=0;j<n;j++) {
			if(!visited[j]&&nearest[j]>near+mat[j][pos])
				nearest[j]=near+mat[j][pos];
		}
	}
	near=-10000000;
	for(i=1;i<n;i++)
		if(nearest[i]>near)
			near=nearest[i];
	return near;
//		printf("%d\n",nearest[i]);
}
void out_mat()
{
	int i,j;
	for(i=0;i<n;i++) {
		putchar('\n');
		for(j=0;j<=i;j++)
			printf("%d ",mat[i][j]);
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF) {
		int i,j;
		char str[1000];
		init();
		getchar();
		for(i=1;i<n;i++) {
			gets(str);
			input_from_string(str,i);
		}
//		out_mat();
		/*dijkstra();*/
		printf("%d\n",dijkstra());
	}
	return 0;
}
