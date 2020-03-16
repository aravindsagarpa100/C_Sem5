#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char address[10],opcode[10],operand[10],res[10];
char opp[10],addd[10];

char optabs[][10]={"ADD","ADDF","AND","COMP","DIV",
                  "J","JEQ","JGT","JLT","JSUB","LDA",
                  "LDB","LDCH","LDL","LDX","LPS","MUL",
                  "RD","OR","RSUB","SSK","STA","STB","STCH",
                  "STI","STL","STSW","STX","SUB","TD",
                  "TIX","WD"};
char opvalues[][10]={"18","58","40","28","24","3C","30","34",
                   "38","48","00","68","50","08","04","D0",
                   "20","D8","44","4C","EC","0C","78","54",
                   "D4","14","E8","10","1C","E0","2C","DC"};


char *trim2(char *stringx)
{
  char *final2;
  int len;
    while(isspace(stringx[0]))
    {
        stringx++;
    }
    
    final2=stringx;
    len=strlen(final2);
    
    while(len>0 && isspace(final2[len-1]))
    {
        len--;
    }
    
    final2[len]='\0';
    return final2;
}

int mktoken2(char line2[])
{
    char *line33,token[3][10],*toc2; 
    int k=0; 
    line33=trim2(line2); 
    toc2=strtok(line33," ");
    
    while(toc2)
    {
        strcpy(token[k++],toc2);    
        toc2=strtok(NULL," ");
    }      
    strcpy(opp,token[0]);
    strcpy(addd,token[1]);
    return 0;
}


char *trim(char *string)
{
  char *final;
  int len;
    while(isspace(string[0]))
    {
        string++;
    }
    
    final=string;
    len=strlen(final);
    
    while(len>0 && isspace(final[len-1]))
    {
        len--;
    }
    
    final[len]='\0';
    return final;
}

int mktoken(char line2[])
{
    char *line3,token[3][10],*toc;
    int k=0;   
    line3=trim(line2); 
    toc=strtok(line3," ");
    
    while(toc)
    {
        strcpy(token[k++],toc);    
        toc=strtok(NULL," ");
    }
    
    if(k==3)
    {
        strcpy(address,token[0]);
        strcpy(opcode,token[1]);
        strcpy(operand,token[2]);
    }
    
    else if(k==2)
    {        
        strcpy(opcode,token[0]);
        strcpy(operand,token[1]);
    }
    else
    {
        strcpy(opcode,token[0]);
        strcpy(operand,"-");
    }
    return k;
}

int opcodefun(char op[])
{
    int i;
    for(i=0;i<(sizeof(optabs)/10);i++)
    {
      if(strcmp(op,optabs[i])==0)
        {
          strcpy(res,opvalues[i]);
          return 1;
        }
    }
        
    return 0;
}




void main()
{
    FILE *f,*temp,*symtab,*name,*optab,*length;
    int i,j,t,locctr,flag,m;
    char line[50],l[10],nm[10],sym[30],abc[20],pqr[20];
    
    f=fopen("passtwo.txt","w");
    fclose(f);
    temp=fopen("temp.txt","r");    
    length=fopen("len.txt","r");
    symtab=fopen("symtab.txt","r");
    f=fopen("passtwo.txt","a");
    name=fopen("name.txt","r");
    
    fgets(l,20,length);
    fgets(nm,20,name);
    fprintf(f,"H ^ %s ^ %s\n",nm,l);

    for ( i = 0; i < 20; i++)
    {
      pqr[i]=0;
    }
    
    
    while(!feof(temp))
    {
      fgets(line,50,temp);
      m=mktoken(line); 
      if(strcmp(opcode,"START")==0)
      {
         strcpy(abc,operand);
         fgets(line,50,temp);
         m=mktoken(line); 
      }

      if(strcmp(opcode,"END")!=0)
      {
        if (strcmp(opcode,"WORD")==0)
        {
          fprintf(f,"T ^ 00000%s\n",operand);
        }
        else if (strcmp(opcode,"BYTE")==0)
        {
          if (operand[0]=='x')
          {
            for (i = 2; i < strlen(operand)-1; i++)
            {
              pqr[i-2]=operand[i];
              pqr[strlen(operand)-3]=0;
            }
            switch(strlen(pqr))
            {
              case 1:fprintf(f,"T ^ 00000%s\n",pqr);break;
              case 2:fprintf(f,"T ^ 0000%s\n",pqr);break;
              case 3:fprintf(f,"T ^ 000%s\n",pqr);break;
              case 4:fprintf(f,"T ^ 00%s\n",pqr);break;
              case 5:fprintf(f,"T ^ 0%s\n",pqr);break;
              case 6:fprintf(f,"T ^ %s\n",pqr);break;
              default:printf(" ");break;
            }
            
          }
          else
          {
            fprintf(f,"T ^ ");
            for (i = 2; i < strlen(operand)-1; i++)
            { 
              fprintf(f,"%x",operand[i]);
            }
            fprintf(f,"\n");
          }
                   
        }
        
        else if(strcmp(opcode,"RSUB")==0)
        {
          fprintf(f,"T ^ 4C0000\n");
        }
        else
        {
            t=opcodefun(opcode);
            if(t!=0)
            {
                while(!feof(symtab))
                {
                    fgets(sym,20,symtab);
                    m=mktoken2(sym); 
                    if(strcmp(operand,opp)==0)
                    {
                      for(i=2;i<6;i++)
                      {
                        res[i]=addd[i-2];
                      }
                      flag=1;
                    }
                }

                if(flag==1)
                {
                  fprintf(f,"T ^ %s\n",res);
                  flag=0;
                }
                

            }
        }
      
      }
      fclose(symtab);
      symtab=fopen("symtab.txt","r");
    }
    fprintf(f,"E ^ %s\n",abc);


}
