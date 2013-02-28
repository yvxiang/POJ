#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mat[10][10];
int available_numbers[10]={0};
bool flag=false;
void find_pos(int *x,int *y)
{
	int i,j;
	for(i=1;i<=9;i++)
		for(j=1;j<=9;j++)
			if(mat[i][j]==0) {
				*x=i;
				*y=j;
				return ;
			}
}
bool check_row_and_cloumn(int row,int cloumn,int num)
{
	int i;
	for(i=1;i<=9;i++)
		if(mat[row][i]==num)
			return false;
	for(i=1;i<=9;i++)
		if(mat[i][cloumn]==num)
			return false;
	return true;
}
bool check_subsquare(int x,int y,int num)
{
	int up_x=((x-1)/3)*3+1;
	int up_y=((y-1)/3)*3+1;
	int i,j;
	for(i=up_x;i<=up_x+2;i++)
		for(j=up_y;j<=up_y+2;j++)
			if(mat[i][j]==num)
				return false;
	return true;
}
void dfs(int x,int y,int count)
{
	if(flag)	return ;
	if(count==0) {
		flag=true;
		int i,j;
		for(i=1;i<=9;i++)
			for(j=1;j<=9;j++) {
				printf("%d",mat[i][j]);
				if(j==9)
					printf("\n");
			}
		return;
	}
	int i;
	for(i=1;i<=9;i++)
		if(available_numbers[i]!=0) {
			if(check_row_and_cloumn(x,y,i)&&check_subsquare(x,y,i)) {
				mat[x][y]=i;
				available_numbers[i]--;
				int a,b;
				find_pos(&a,&b);
				dfs(a,b,count-1);
				mat[x][y]=0;
				available_numbers[i]++;
			}
		}
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--) {
		int i,j,x,y;
		flag=false;
		int count=0;
		for(i=1;i<=9;i++)
			available_numbers[i]=9;
		char ch;
		for(i=1;i<=9;i++) {
			for(j=1;j<=9;j++) {
				scanf("%c",&ch);
				mat[i][j]=ch-'0';
				if(mat[i][j]==0) {
					count++;
					x=i;
					y=j;
				}
				available_numbers[mat[i][j]]--;
			}
			getchar();
		}
		dfs(x,y,count);
	}	
	return 0;
}
