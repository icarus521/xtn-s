#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	FILE*fp; 
	fp=fopen("2-2.txt","r+") ;
	int a[50],b[50],k[50],c1,c2,n,i,j,t,num1,num2,con1,con2;
	bool pr1,pr2;
	bool fr=true;
	int time=0;
	char ele1[12],ele2[12];
	fscanf(fp,"%s%d",&ele1,&c1);
	fscanf(fp,"%s%d",&ele2,&c2);
	con1=con2=i=1;
	while(fscanf(fp,"%d%d%d",&a[i],&b[i],&k[i])!=EOF)
		i++;
	t=n=i-1;
	num1=num2=0;
	for(time=0;;time++){
		pr1=pr2=false;
		if(c1==10) 	con1=-1;
		if(c2==10)  con2=-1;
		if(c1==1) con1=1;
		if(c2==1) con2=1;
		if(fr){
			pr1=true;
			pr2=true;
			fr=false; 
		}
		for(j=1;j<=n;j++){
			if(a[j]==-1&&b[j]==c1){
				b[j]=-1;
				num1--;
				t--;
				pr1=true;
			}
			if(a[j]==-2&&b[j]==c2){
				b[j]=-1;
				num2--;
				t--;
				pr2=true;
			}
			
			if(a[j]==c1&&num1<4&&k[j]<=time&&(con1==1&&a[j]<b[j]||con1==-1&&a[j]>b[j])){
				num1++;
				a[j]=-1;
				pr1=true;
			}
			if(a[j]==c2&&num2<4&&k[j]<=time&&(con2==1&&a[j]<b[j]||con2==-1&&a[j]>b[j])){
				num2++;
				a[j]=-2;
				pr2=true;
			}
		}	
		if(pr1) fprintf(fp,"\n%s %d %d %d",ele1,c1,time,num1);	
		if(pr2) fprintf(fp,"\n%s %d %d %d",ele2,c2,time,num2);	
		if(t==0) break;
		c1=c1+con1;
		c2+=con2;

	}
	return 0;
}
