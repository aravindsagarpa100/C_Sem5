#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
int a[20],b[20],i,j,n,x[20],t;
float avgwt,avgtt,sum=0,wt=0;
srand(time(0));
n=(rand()%5)+2;
printf("No. of process is:%d \n",n);
for(i=0;i<n;i++)
{
	a[i]=(rand()%8)+1;
	sum+=a[i];
}
for(i=0;i<n;i++)
{
	b[i]=(rand()%8)+1;
}

for(i=0;i<n;i++)
{
	for(j=0;j<n-1;j++)
	{
		if(b[j]>b[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
			t=b[j];
			b[j]=b[j+1];
			b[j+1]=t;
		}
	}
}

x[0]=0;
for(i=1;i<n;i++)
{	
	x[i]=0;
	for(j=0;j<i;j++)
	{
		x[i]+=a[j];	
	}
	wt+=x[i];

}

printf("P B Pr W T\n");
for(i=0;i<n;i++)
{
	printf("%d %d %d %d %d\n",i+1,a[i],b[i],x[i],x[i]+a[i]);
}

avgwt=wt/n;
avgtt=(wt+sum)/n;
printf("Avg waiting time is: %f\n",avgwt);
printf("Avg turnaround time is: %f\n",avgtt);


}
