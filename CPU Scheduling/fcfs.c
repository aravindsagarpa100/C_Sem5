#include<stdio.h>
#include<time.h>

void main()
{
int a[20],i,j,n,x[20];
float avgwt,avgtt,sum=0,sum2=0,wt=0,avgwt2,avgtt2;
srand(time(0));
n=(rand()%5)+2;
printf("No. of processes:%d\n",n);
for(i=0;i<n;i++)
{
	a[i]=(rand()%8)+1;
	sum+=a[i];
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
