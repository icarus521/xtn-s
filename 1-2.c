#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	FILE*fp; 
	fp=fopen("1-2.txt","r+") ;
	int a,b,c;
	char d[8];
	fscanf(fp,"%s%d%d%d\n",&d,&c,&a,&b);
	
	fprintf(fp,"\n%d 0 0\n",c);
	fprintf(fp,"%d %d %d\n",a,abs(a-c),1);
	fprintf(fp,"%d %d %d\n",b,abs(a-c)+abs(a-b),0);
	return 0;
}
