#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	FILE*fp; 
	fp=fopen("2-1.txt","r+") ;
	int a[50],b[50],k[50],c,n,i,j,t,num,con,p;
	bool pr,trans;
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
		trans=true;
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
		if(con==1){
			for(p=i;p<=c;p++){
				if((a[p]>i||b[p]>i)&&k[p]<=time) trans=false;
			}
			if(trans) con=-1;
		}
		if(con==-1){
			for(p=i;p>=1;p--){
				if((a[p]<i||b[p]<i)&&k[p]<=time) trans=false;
			}
			if(trans) con=1;
		}
		time++;
	}
	return 0;
}
