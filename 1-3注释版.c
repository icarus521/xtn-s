#include<stdio.h>
#include<stdbool.h>
int main(){
	int a[50],b[50],c,n,i,j,t,num,con;
	bool pr;
	bool fr=true;
	int time=0;
	char ele[9];
	scanf("%d",&n);//输入等候人数 
	scanf("%s%d",&ele,&c);
	con=1;
	//while(scanf("%d%d",&a[i],&b[i])!=EOF)
		//i++;
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	
	t=n;//总人数 
	num=0;
	for(i=c;i<=10;i+=con){//con为1或-1决定电梯上下 
		pr=false;
		if(fr){//判断是否为电梯第一次运行 
			pr=true;//用于判断此层是否输出 
			fr=false; 
		}
		for(j=1;j<=n;j++){
			if(a[j]==0&&b[j]==i){
				a[j]=-1;//标记下梯 
				num--;//指代电梯中的人数 
				t--;//指代剩余未到达指定楼层人数 
				pr=true;
			}
			if(a[j]==i&&num<4){
				num++;
				a[j]=0;//标记上梯 
				pr=true;
			}
		}	
		if(pr) printf("%d %d %d\n",i,time,num);	
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
