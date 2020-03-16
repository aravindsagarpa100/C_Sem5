#include<stdio.h>
#include<string.h>

struct twolevel
{
char dname[20];
char fname[20][20];
int fno;
}d[20];

void main()
{
int i,c,dno,k;
char f[20],g[20];
dno=0;
while(1)
{
xy:
printf("\nEnter operation:\n1.Create Directory\n2.Create File\n3.Delete\n4.Search\n5.Print\n6.Exit\n");
scanf("%d",&c);
switch(c)
{
case 1: printf("Enter directory name:");
		scanf("%s",d[dno].dname);
		d[dno].fno=0;
		dno++;
		break;
case 2: printf("Enter directory name:");
		scanf("%s",g);
		for(i=0;i<dno;i++)
		{
			if(strcmp(g,d[i].dname)==0)
			{
				printf("Enter file name:");
				scanf("%s",d[i].fname[d[i].fno]);
				d[i].fno++;
				break;
			}
		}
		if(i==dno)
		{
			printf("Directory not found\n");
		}
		break;
case 3: printf("Enter directory name:");
		scanf("%s",g);
		for(i=0;i<dno;i++)
		{
			if(strcmp(g,d[i].dname)==0)
			{
				printf("Enter file name:");
				scanf("%s",f);
				for(k=0;k<d[i].fno;k++)
				{
					if(strcmp(f,d[i].fname[k])==0)
					{
						d[i].fno--;
						strcpy(d[i].fname[k],d[i].fname[d[i].fno]);
						goto z;
					}
				}
				printf("File not found\n");
				goto z;
			}
		}
		printf("Directory not found\n");
		z:
		break;
case 4: printf("Enter directory name:");
		scanf("%s",g);
		for(i=0;i<dno;i++)
		{
			if(strcmp(g,d[i].dname)==0)
			{
				printf("Enter file name:");
				scanf("%s",f);
				for(k=0;k<d[i].fno;k++)
				{
					if(strcmp(f,d[i].fname[k])==0)
					{
						printf("File found\n");
						goto y;
					}
				}
				printf("File not found\n");
				goto y;
			}
		}
		printf("Directory not found\n");
		y:
		break;
case 5: if(dno==0)
		{
			printf("No directory found\n");
		}
		else
		{
			printf("Directory\tFiles\n");
			for(i=0;i<dno;i++)
			{
				printf("\n%s\t",d[i].dname);
				for(k=0;k<d[i].fno;k++)
				{
					printf("\t%s",d[i].fname[k]);
				}
			}
		}
		break;
case 6: goto x;
		break;
default:printf("Enter 1-6\n");
		goto xy;
		break;
}
}
x:
printf("\n");
}
