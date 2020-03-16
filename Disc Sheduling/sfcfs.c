#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
int a[20],b=0,i,x[20],n,c=0;
float avg;
srand(time(0));
n=(rand()%10)+2;

for(i=0;i<n;i++)
{
	a[i]=(rand()%40)+2;
}

x[0]=0;

for(i=1;i<n;i++)
{
	b=a[i]-a[i-1];
	if(b<0)
	{
		b=-1*b;
	}
	x[i]=b+x[i-1];
	c+=x[i];
}

printf("\nN Tr sktm\n");
for(i=0;i<n;i++)
{
	printf("%d %d  %d\n",i+1,a[i],x[i]);
}

avg=c/n;
printf("\nAverage seek time is %f\n",avg);
}
