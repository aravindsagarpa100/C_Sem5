#include<stdio.h>
#include<string.h>

struct fileorg
{
char dname[20];
char fname[20][20];
int fno;
}d;

void main()
{
int i,c;
char f[20];
d.fno=0;
printf("Enter name of directory:");
scanf("%s",d.dname);
while(1)
{
xy:
printf("Enter operation:\n1.Create\n2.Delete\n3.Search\n4.Print\n5.Exit\n");
scanf("%d",&c);
switch(c)
{
case 1: printf("Enter File name:");
		scanf("%s",d.fname[d.fno]);
		d.fno++;
		break;
case 2: printf("Enter File name:");
		scanf("%s",f);
		for(i=0;i<d.fno;i++)
		{
			if(strcmp(f,d.fname[i])==0)
			{
				strcpy(d.fname[i],d.fname[d.fno-1]);
				break;
			}
		}
		if(i==d.fno)
		{
			printf("File not found\n");
		}
		else
		{
			d.fno--;
		}
		break;
case 3: printf("Enter File name:");
		scanf("%s",f);
		for(i=0;i<d.fno;i++)
		{
			if(strcmp(f,d.fname[i])==0)
			{
				printf("File found\n");
				break;
			}
		}
		if(i==d.fno)
		{
			printf("File not found\n");
		}
		break;
case 4: if(d.fno==0)
		{
			printf("Empty Directory\n");
		}
		else
		{
			printf("The Files are:\n");
			for(i=0;i<d.fno;i++)
			{
				printf("%s\n",d.fname[i]);
			}
		}
		break;
case 5: goto x;
		break;
default:printf("Enter 1-5\n");
		goto xy;
		break;
}

}
x:
printf("\n");

}
