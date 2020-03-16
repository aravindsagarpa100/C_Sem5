#include<stdio.h>
#include<stdlib.h>

struct node
{float data;
struct node *next;
};

struct node *head=NULL;

void insertfirst()
{float value;
struct node *p=(struct node*)malloc(sizeof(struct node*));
printf("Enter value:");
scanf("%f",&value);
p->next=head;
head=p;
p->data=value;
}

void insertlast()
{float value;
struct node *ptr;
ptr=head;
struct node *p=(struct node*)malloc(sizeof(struct node*));
printf("Enter value:");
scanf("%f",&value);
p->data=value;
if(head==NULL)
{	p->next=NULL;
	head=p;
}
else
{	while(ptr->next!=NULL)
		{ptr=ptr->next;}
	p->next=NULL;
	ptr->next=p;
}
}

void insertbetween()
{float value,key;
struct node *ptr;
ptr=head;
struct node *p=(struct node*)malloc(sizeof(struct node*));
printf("Enter key:");
scanf("%f",&key);
printf("Enter value:");
scanf("%f",&value);
p->data=value;
if(head==NULL)
{printf("Linked list is empty\n");}
else
{	while(ptr->next!=NULL && ptr->data!=key)
		{ptr=ptr->next;}
	if(ptr->data==key)
	{	p->next=ptr->next;
		ptr->next=p;
	}
	else
	{printf("Key not found\n");}
}
}

void deletefirst()
{struct node *p;
p=head;
if(head==NULL)
{printf("Linked list is empty\n");}
else
{	head=p->next;
}
free(p);
}

void deletelast()
{struct node *p,*ptr;
ptr=head;
p=NULL;
if(head==NULL)
{printf("Linked list is empty\n");}
else
{	if(ptr->next==NULL)
	{	head=NULL;
		free(ptr);	
	}	
	else
	{	while(ptr->next!=NULL)
		{	p=ptr;
			ptr=ptr->next;
		}
		p->next=NULL;
		free(ptr);
	}
}
}

void deletebetween()
{float key;
struct node *p,*ptr;
ptr=head;
p=NULL;
printf("Enter key:");
scanf("%f",&key);
if(head==NULL)
{printf("Linked list is empty\n");}
else
{	if(ptr->data==key)
	{	head=ptr->next;
		free(ptr);
	}
	else
	{	while(ptr->next!=NULL && ptr->data!=key)
			{	p=ptr;
				ptr=ptr->next;
			}
			if(ptr->data==key)
			{	if(ptr->next==NULL)
				{	p->next=NULL;
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
ptr=head;
if(head==NULL)
{printf("Linked list is empty\n");}
else
{	printf("Linked list is:");
	while(ptr->next!=NULL)
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
printf("********************\n");
}
