#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct book
{
int b[100][5];
int r[100];
}a;

int j=0;

int fun()
{
int z=0; 
char st[11];
  char *ch;
  gets(st);
  puts(st);
  ch = strtok(st, " ");
  while (ch != NULL) {
  a.b[j][z++]=atoi(ch);
  ch = strtok(NULL, " ,");
  }
	
j++;

return 0;
}


void main()
{int i,n,y,k,z,temp,p,q,max,t;
scanf("%d",&t);
for(z=0;z<t;z++){
scanf("%d",&n);
for(i=0;i<n;i++)
{
	a.r[i]=i;
}
for(i=0;i<n;i++)
{
//	fun();
	for(int j=0;j<5;j++)
		scanf("%d",&a.b[i][j]);
}
	
	for(k=0;k<n-1;k++)
	{
	p=0;
	q=0;
	for(y=0;y<5;y++)
	{
	
		if(a.b[k][y] > a.b[k+1][y])
		{
			p++;
		}
		else
		{
			q++;
		}
	}
	if(p>=q)
	{
		temp=a.b[k][y];
		a.b[k][y]=a.b[k+1][y];
		a.b[k+1][y]=temp;
		temp=a.r[k];
		a.r[k]=a.r[k+1];
		a.r[k+1]=temp;
		max=a.r[k+1];
	}
	else
	{
		max=a.r[k+1];
	}
	}

printf("%d",max+1);
}
}
