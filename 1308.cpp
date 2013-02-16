#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <iterator>
using namespace std;
int father[10002];
int degree[10002]={0};
set<int> V;
void init()
{
	int i;
	for(i=0;i<10002;i++) {
		father[i]=i;
		degree[i]=0;
	}
}
bool check_one_father(int *f) 
{
	int i;
	int count=0;
	set<int>::iterator it=V.begin();
	while(it!=V.end()) {
		if(father[*it]==*it) {
			*f=*it;
			count++;
		}
		it++;
	}
	if(count!=1)
		return false;
	return true;
}
bool check_degree(int f)
{
	set<int>::iterator it=V.begin();
	while(it!=V.end()) {
		if(*it==f) {
			it++;
			continue;
		}
		else if(degree[*it]!=1)
			return false;
		it++;
	}
	return true;
}

bool judge()
{
	int fa;
	if(!check_one_father(&fa))
		return false;
	if(degree[fa]!=0)
		return false;
	if(!check_degree(fa))
		return false;
	return true;
}
void join(int fa,int chil)
{
	father[chil]=fa;
}
int find_father(int chil)
{
	if(father[chil]==chil)	return chil;
	return find_father(father[chil]);
}
int main()
{
	int k=1;
	int edge_a,edge_b;
	V.clear();
	init();
	while(scanf("%d%d",&edge_a,&edge_b)!=EOF) {
		if(edge_a==edge_b&&edge_a==-1) 
			return 0;
		if(edge_a==edge_b&&edge_a==0) {
			if(V.empty()) printf("Case %d is a tree.\n",k++);
			else if(judge())
				printf("Case %d is a tree.\n",k++);
			else 
				printf("Case %d is not a tree.\n",k++);
			init();
			V.clear();
		} else {
			int fa=find_father(edge_a);
			join(fa,edge_b);
			degree[edge_b]++;//edge_b的入度加1	
			V.insert(edge_a);
			V.insert(edge_b);
		}
	}
}
