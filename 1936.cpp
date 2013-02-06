#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *q,*p,*r;
bool check(char ch,char *dst)
{
	while(*dst) {
		if(*dst==ch) {
			r=dst+1;
			return true;
		}
		dst++;
	}
	return false;
}
int main()
{
	char s[100002],t[100002];
	p=s;
	q=t;
	while(scanf("%s%s",s,t)!=EOF) {
		p=s;
		q=t;
		r=q;
		bool flag=true;
		while(*p) {
			if(!check(*p,q)) {
				printf("No\n");
				flag=false;
				break;
			}
			q=r;
			p++;
		}
		if(flag) {
			printf("Yes\n");
		}
	}
}


