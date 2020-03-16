#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
int a[20],b[20],d[20],e[20],i,z,j=1,n,x[20],k,c[20],t,y,m=1,p[20];
float avgwt,avgtt,sum=0,wt=0;
srand(time(0));
n=(rand()%5)+2;
printf("No. of processes:%d \n",n);
for(i=0;i<n;i++)
{
	a[i]=(rand()%8)+1;
	sum+=a[i];
	e[i]=a[i];
}

for(i=0;i<n;i++)
{
	b[i]=0;
	c[i]=0;
	d[i]=0;
}

y=(rand()%5)+1;
printf("Time quandom is:%d \n",y);
x[0]=0;
p[0]=0;
for(t=0;;t++)
{
	z=0;
 	for(i=0;i<n;i++)
 	{
 	 	x[j]=0;	
  		if(a[i]!=0)
 	 	{
			if(a[i]>=y)
			{     
				k=c[i];
				a[i]-=y;
				x[j]=x[j-1]+y;
				b[i]=x[j-1];
				c[i]=x[j];
				d[i]+=(b[i]-k);
			//	p[m]=d[i];
			//	m++;
			}
			else
			{
				k=c[i];
				x[j]=x[j-1]+a[i];
				b[i]=x[j-1];
				c[i]=x[j];
				d[i]+=(b[i]-k);
				a[i]=0;
			//	p[m]=d[i];
			//	m++;
			}	
			j++;
	
 	 	}

 	}
 	for(i=0;i<n;i++)
 	{
  		z+=a[i];
 	}

 	if(z==0)
 	{
		break;
	}

}

printf("P B W T\n");
for(i=0;i<n;i++)
{
	printf("%d %d %d %d\n",i+1,e[i],d[i],d[i]+e[i]);
}

for(i=0;i<n;i++)
{
	wt+=d[i];
}

avgwt=wt/n;
avgtt=(wt+sum)/n;
printf("Avg waiting time is: %f\n",avgwt);
printf("Avg turnaround time is: %f\n",avgtt);


}
