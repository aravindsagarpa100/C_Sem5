#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
 int number;
 char type;
 char name[20];
 struct node *children[10];
 struct node *parent;
 int numberchild;
};
void main()
{
 int i, j, k, flag = 0;
 char cmd[20], command[6], par[10];
 struct node *pwd;
 struct node *root = (struct node *)malloc(sizeof(struct node));
 root->number=0;
 root->type='d';
 strcpy(root->name,"root");
 for (i=0;i<10;i++)
 {
  root->children[i]=NULL;
 }
 root->numberchild=0;
 printf("pwd====root\n");
 pwd=root;
 printf("> ");
 gets(cmd);
 i=0;
 while(cmd[i]!=' ' && cmd[i]!='\0')
 {
  command[i]=cmd[i];
  i++;
 }

 i++;
 j=0;
 while(cmd[i]!='\0')
 {
  par[j]=cmd[i];
  i++;
  j++;
 }
 par[j]='\0';
 while(strcmp(cmd,"exit")!=0)
 {
  if(strcmp(cmd,"ls")==0)
  {
   i=0;
   while(pwd->children[i]!=NULL)
   {
    printf("%s",pwd->children[i]->name);
    i++;
   }
  }
  else if (strcmp(command, "rm") == 0)
    {
    if (pwd->numberchild == 0)
    {
    printf("No such file or directory!!!\n");
    }

    i = 0;
    while (pwd->children[i] != NULL)
    {
    if (strcmp(pwd->children[i]->name, par) == 0)
    {
    for (j = i; j < 9; j++)
    {
     pwd->children[j] = pwd->children[j + 1];
    }
    flag = 1;
    pwd->numberchild--;
    break;
   }

   i++;
   }
   if (flag == 0)
   {
    printf("no such file or directory!!!\n");
   }
  }
  else if(strcmp(command,"cd")==0)
  {
   if(strcmp(par,"..")==0 && pwd->parent!=NULL)
   {
    pwd=pwd->parent;
    printf("pwd==%s",pwd->name);
   }
   else
   {
    i=0;
    while(pwd->children[i]!=NULL)
    {
     if(strcmp(pwd->children[i]->name,par)==0 && pwd->children[i]->type=='d')
     {
      pwd=pwd->children[i];
      printf("pwd==%s",pwd->name);
     }
     i++;
    }
   }
  }
  else if(strcmp(command,"touch")==0)
  {
   struct node *newd = (struct node *)malloc(sizeof(struct node));
   newd->number=(pwd->numberchild)+1;
   newd->type='f';
   strcpy(newd->name,par);
   for(i=0;i<10;i++)
   {
    newd->children[i]=NULL;
   }
   newd->parent=pwd;
   newd->numberchild=0;
   pwd->children[pwd->numberchild]=newd;
   pwd->numberchild++;
  }
  else if (strcmp(command, "mkdir") == 0)
  {
   struct node *newd = (struct node *)malloc(sizeof(struct node));
   newd->number = (pwd->numberchild) + 1;
   newd->type = 'd';
   strcpy(newd->name, par);
   for (i = 0; i < 10; i++)
   {
    newd->children[i] = NULL;
   }
   newd->parent = pwd;
   newd->numberchild = 0;

   pwd->children[pwd->numberchild] = newd;
   pwd->numberchild++;
  }
  else if(strcmp(command,"pwd")==0)
  {
   printf("pwd==%s",pwd->name);
  }
  else
  {
   printf("invalid");
  }
  printf("\n> ");
  gets(cmd);
  i = 0;
  while (cmd[i] != ' ' && cmd[i] != '\0')
  {
   command[i] = cmd[i];
   i++;
  }
  command[i] = '\0';
  i++;
  j = 0;
  while (cmd[i] != '\0')
  {
   par[j] = cmd[i];
   i++;
   j++;
  }
  par[j] = '\0';
 }
}
  
     
 
