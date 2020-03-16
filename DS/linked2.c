#include<stdio.h>
#include<stdlib.h>

struct node
{float data;
struct node *next;
};

struct node *last=NULL;

void insertfirst()  
{float value;
struct node *p=(struct node*)malloc(sizeof(struct node*));
printf("Enter value:");
scanf("%f",&value);
p->data=value;
if(last!=NULL)
{p->next=last->next;
last->next=p;}
else
{p->next=p;
last=p;}
}

void insertlast()  
{float value;
struct node *ptr;
ptr=last;
struct node *p=(struct node*)malloc(sizeof(struct node*));
printf("Enter value:");
scanf("%f",&value);
p->data=value;
if(last==NULL)
{	p->next=p;
	last=p;
}
else
{	while(ptr->next!=last->next)
		{ptr=ptr->next;}
	p->next=last->next;
	last->next=p;
	last=p;
}
}

void insertbetween()   
{float value,key;
struct node *ptr,*c;
struct node *p=(struct node*)malloc(sizeof(struct node*));
printf("Enter key:");
scanf("%f",&key);
printf("Enter value:");
scanf("%f",&value);
p->data=value;
if(last==NULL)
{printf("Linked list is empty\n");}
else
{	ptr=last->next;
	c=last->next;
	while(ptr->next!=c && ptr->data!=key)
		{ptr=ptr->next;}
	if(ptr->data==key)
	{	p->next=ptr->next;
		ptr->next=p;
		if(p->next==c)
			{	last=p;
			}
	}
	else
	{printf("Key not found\n");}
}
}

void deletefirst()   
{struct node *p;
if(last==NULL)
{printf("Linked list is empty\n");}
else
{	p=last->next;
	if(last->next!=last)
	{	last->next=p->next;
	}
	else
	{	last=NULL;
	}
	
}
free(p);
}

void deletelast()   
{struct node *p,*ptr,*c;
p=NULL;
if(last==NULL)
{printf("Linked list is empty\n");}
else
{	ptr=last->next;
	c=last->next;
	if(ptr->next==ptr)
	{	last=NULL;
		free(ptr);	
	}	
	else
	{	while(ptr->next!=c)
		{	p=ptr;
			ptr=ptr->next;
		}
		p->next=ptr->next;
		last=p;
		free(ptr);
	}
}
}

void deletebetween() 
{float key;
struct node *p,*ptr,*c;
p=NULL;
printf("Enter key:");
scanf("%f",&key);
if(last==NULL)
{printf("Linked list is empty\n");}
else
{	ptr=last->next;
	c=last->next;
	if(ptr->data==key)
	{	if(ptr->next!=ptr)
		{last->next=ptr->next;}
		else
		{last=NULL;}
		free(ptr);
	}
	else
	{	while(ptr->next!=c && ptr->data!=key)
			{	p=ptr;
				ptr=ptr->next;
			}
			if(ptr->data==key)
			{	if(ptr->next==c)
				{	p->next=ptr->next;
					last=p;
					free(ptr);
				}
				else
				{	p->next=ptr->next;
					free(ptr);
				}
			}
	}
}
}

void traversal()    
{struct node *ptr;
if(last==NULL)
{printf("Linked list is empty\n");}
else
{	ptr=last->next;
	printf("Linked list is:");
	while(ptr->next!=last->next)
	{	printf("%f\n",ptr->data);
		ptr=ptr->next;	
	}
	printf("%f",ptr->data);
}
}

void main()
{
int i;
c:
printf("\nEnter\n1.Insert at first\n2.Insert at last\n3.Insert in between\n4.Delete at first\n5.Delete at last\n6.Delete in between\n7.Traversal\n8.Exit\n");
scanf("%d",&i);
switch(i)
{case 1:insertfirst();break;
case 2:insertlast();break;
case 3:insertbetween();break;
case 4:deletefirst();break;
case 5:deletelast();break;
case 6:deletebetween();break;
case 7:traversal();break;
case 8:goto d;break;
default:printf("Enter only from 1 to 8\n");break;
}
goto c;
d:
printf("\n********************\n");
}
