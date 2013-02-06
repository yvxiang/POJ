#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack>
using namespace std;
int main()
{
	int b;
	char p[1020],m[10];
	while(scanf("%d",&b)!=EOF) {
		if(b==0)	return 0;
		scanf("%s%s",p,m);
		int __m=strtol(m,0,b);
		int res=0;
		int len=strlen(p);
		int i;
		for(i=0;i<len;i++) {
			res=res*b+p[i]-'0';
			res%=__m;
		}
		if(res==0) {
			printf("0\n");
		} else {
			stack<int> S;
			while(res) { 
				S.push(res%b);
				res/=b;
			}
			while(!S.empty()) {
				printf("%d",S.top());
				S.pop();
			}
			putchar('\n');
		}

	}
	return 0;
}
