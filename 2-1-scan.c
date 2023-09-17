#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	FILE*fp; 
	fp=fopen("2-1.txt","r+") ;
	int a[50],b[50],k[50],c,n,i,j,t,num,con;
	bool pr;
	bool fr=true;
	int time=0;
	char ele[9];
	fscanf(fp,"%s%d",&ele,&c);
	con=i=1;
	while(fscanf(fp,"%d%d%d",&a[i],&b[i],&k[i])!=EOF)
		i++;
	t=n=i-1;
	num=0;
	for(i=c;i<=10;i+=con){
		pr=false;
		if(i==c&&fr){
			pr=true;
			fr=false; 
		}
		for(j=1;j<=n;j++){
			if(a[j]==0&&b[j]==i){
				b[j]=-1;
				num--;
				t--;
				pr=true;
			}
			if(a[j]==i&&num<4&&k[j]<=time){
				num++;
				a[j]=0;
				pr=true;
			}
		}	
		if(pr) fprintf(fp,"\n%d %d %d\n",i,time,num);	
		if(t==0) break;
		if(i==10) 	con=-1;
		if(i==1) con=1;
		time++;
	}
//	printf("%d",time);
	//printf("%d 0 0\n",c);
	//printf("%d %d %d\n",a,abs(a-c),1);
	//printf("%d %d %d\n",b,abs(a-c)+abs(a-b),0);
	return 0;
}
