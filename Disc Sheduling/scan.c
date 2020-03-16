#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
int a[20],i,j,x[20],t,f,n,b,d,c=0;
float avg;
srand(time(0));
n=(rand()%13)+5;
printf("N is %d\n",n);

for(i=0;i<n;i++)
{
	a[i]=(rand()%40)+2;
}
b=(rand()%4)+1;
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

printf("\nStarting point is %d\n",b);

x[b]=0;
for(i=b-1;i>-1;i--)
{
	f=a[i]-a[i+1];
	if(f<0)
	{
		f=-1*f;
	}
	x[i]=f+x[i+1];
	c+=x[i];
}


x[b+1]=a[0]-a[b+1];
if(x[b+1]<0)
{
	x[b+1]=-1*x[b+1];
}
x[b+1]+=x[0];
for(i=b+2;i<n;i++)
{
	f=a[i]-a[i-1];
	if(f<0)
	{
		f=-1*f;
	}
	x[i]=f+x[i-1];
	c+=x[i];
}

printf("\nN Tr sktm\n");
for(i=b;i>-1;i--)
{
	printf("%d %d  %d\n",i,a[i],x[i]);
}
for(i=b+1;i<n;i++)
{
	printf("%d %d  %d\n",i,a[i],x[i]);
}

avg=(c+x[b+1])/n;
printf("\nAverage seek time is %f\n",avg);

}
