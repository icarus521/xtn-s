#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	printf("%d 0 0\n",c);
	printf("%d %d %d\n",a,abs(a-c),1);
	printf("%d %d %d\n",b,abs(a-c)+abs(a-b),0);
	return 0;
}
