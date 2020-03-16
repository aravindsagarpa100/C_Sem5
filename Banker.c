#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

void main() 
{ 
int n,m,c[15][15],i,y,a[15][15],j,b[15],h,k,l,max[15][15],t=0,x[15],q[20],temp; 

srand(time(0));
n=(rand()%5)+2;
printf("No. of processes: %d\n",n);  
m=(rand()%5)+2; 
printf("No. of Resources: %d\n",m);

for(i=0;i<n;i++)
{ 
    for(j=0;j<m;j++)
    {
		a[i][j]=rand()%4;	
    }
}

printf("Alloc is:\n");
for(i=0;i<n;i++)
{ 
    for(j=0;j<m;j++)
    {
    	printf("%d  ",a[i][j]);	
    }
    printf("\n");
}

for(i=0;i<n;i++)
{ 
    for(j=0;j<m;j++)
    {
    	max[i][j]=(rand()%9)+4;	
    }
}
  
printf("Max is:\n");
for(i=0;i<n;i++)
{ 
    for(j=0;j<m;j++)
    {
    	printf("%d  ",max[i][j]);	
    }
    printf("\n");
}

for(i=0;i<m;i++)
{
	b[i]=(rand()%10)+3;
	x[i]=-1;	
} 

printf("Avail is:\n");
for(i=0;i<m;i++)
{
    printf("%d  ",b[i]);
} 	

for(j=0;j<m;j++)
{
 	q[j]=rand()%2;	
} 

temp=rand()%5;
while(temp>n-1)
{
	temp=(rand()%5)+1;
}
printf("\nRequest done for P%d is:\n",temp);
for(j=0;j<m;j++)
{
    printf("%d  ",q[j]);	
} 

for(i=0;i<n;i++)
{ 
    for(j=0;j<m;j++) 
    {
		c[i][j]=max[i][j]-a[i][j]; 
    }
}

printf("\nNeed is:\n");
for(i=0;i<n;i++)
{ 
    for(j=0;j<m;j++)
    {
    	printf("%d  ",c[i][j]);	
    }
    printf("\n");
}


for(j=0;j<m;j++)
{
    if(c[temp][j]<q[j])
	{
		printf("\nDeadlock"); 		
		goto s;		
	}
	else
	{
		c[temp][j]=c[temp][j]-q[j];	
	}


	if(b[j]<q[j])
	{
		printf("\nDeadlock"); 		
		goto s;		
	}
	else
	{
		b[j]-=q[j];	
	}	
} 



for(k=0;k<n;k++)
{
	for(i=0;i<n;i++)
	{
		y=0;
  		for(h=0;h<t+1;h++)
    	{
 			if(x[h]==i)
 			{
 				goto p;
			}
   		}
		for(j=0;j<m;j++)
		{ 
        	if(c[i][j]<=b[j])
			{ 
            	y++;
            } 
		}
       	if(y==m)
        {
            for(h=0;h<m;h++)	
            {
            	b[h]+=a[i][h];
			}
			x[t]=i;
			t+=1;
		}
		p:
		printf(" ");  
	}
}

if(t<n)
{
	printf("\nDeadlock\n");
}
else
{
	printf("\nSafe sequence is :"); 
	for(i=0;i<t;i++) 
    {
		printf("P%d  ",x[i]+1);  
	}
} 
s:
printf("\n"); 

}






