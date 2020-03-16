#include<stdio.h>
#include <time.h>
#include <stdlib.h>


void main()
{
int a[20],i,j,n,x[20],t;
float avgwt,avgtt,sum=0,wt=0;
srand(time(0));
n=(rand()%5)+2;
printf("No. of processes:%d \n",n);

for(i=0;i<n;i++)
{
	a[i]=(rand()%9)+3;
	sum+=a[i];
}


for(i=0;i<n;i++)
{
	for(j=0;j<n-1;j++)
	{
		if(a[j]>a[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
}

x[0]=0;
for(i=1;i<n;i++)
{	
	x[i]=a[i]+x[i-1];
	wt+=x[i];
}

printf("P B W T\n");
for(i=0;i<n;i++)
{
	printf("%d %d %d %d\n",i+1,a[i],x[i],x[i]+a[i]);
}

avgwt=wt/n;
avgtt=(wt+sum)/n;
printf("Avg waiting time is: %f\n",avgwt);
printf("Avg turnaround time is: %f\n",avgtt);

}
