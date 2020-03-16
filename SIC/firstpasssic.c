#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char label[10],opcode[10],operand[10];
char codes[][10]={"ADD","ADDF","ADDR","AND","CLEAR","COMP","COMPF","COMPR","DIV","DIVF","DIVR","J","JEQ","JGT","JLT","JSUB","LDA","LDB","LDCH","LDF","LDL","LDS","LDT","LDX","LPS","MUL","MULF","MULR","OR","RD","RMO","RSUB","SHIFTL","SHIFTR","STA","STB","STCH","STF","STL","STS","STSW","STT","STX","SUB","SUBF","SUBR","TD","TIX","TIXR","WD","FIX","FLOAT"};

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
        strcpy(label,token[0]);
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
    for(i=0;i<(sizeof(codes)/10);i++)
    {
        if(!strcmp(op,codes[i]))
        {
        	return 1;
        }
    }
	return 0;
}

int length(char a[])
{
    if (a[0]=='c')
    {
        return strlen(a)-3;
    }
    else
    {
        return (strlen(a)-3)/2;
    }
}



void main() 
{   
    FILE *f,*temp,*fp3,*fp4,*len,*name;
    int i,j,k=0,locctr,adr1,m,l,lc=0;
    char line[50],sym[100][10];

    temp=fopen("temp.txt","w");
    fclose(temp);
    fp3=fopen("symtab.txt","w");
    fclose(fp3);
    f=fopen("prg2.txt","r");    
    temp=fopen("temp.txt","a");
    fp3=fopen("symtab.txt","a");
    len=fopen("len.txt","w");
    name=fopen("name.txt","w");
    
    fgets(line,50,f);
    lc++;
    m=mktoken(line); 
    
    if(strcmp(opcode,"START")==0)
    {
    	fprintf(name,"%s",label);
        locctr=atoi(operand);
        adr1=locctr;
        fprintf(temp,"- %s %04x\n",opcode,adr1);
        fgets(line,50,f);
        lc++;
        m=mktoken(line); 
    }
    else
    {
        locctr=0;
        adr1=locctr;
    }
    
    while(!feof(f))
    {
        if(m==3)
        {
        	for(l=0;l<k;l++)
        	{
        		if(strcmp(label,sym[l])==0)
        		{
        			printf("Duplicate error on line:%d\n",lc);
                    fgets(line,50,f);
                    m=mktoken(line);
        		}
        	}
    		strcpy(sym[k++],label);
            fprintf(fp3,"%s %04x\n",label,locctr);
        }
        
        fprintf(temp,"%04x %s %s\n",locctr,opcode,operand); 
        
        if(!strcmp(opcode,"WORD"))
        {
            locctr+=3;
        }
        else if(strcmp(opcode,"BYTE")==0)
        {
            locctr+=length(operand);
        }
        else if(strcmp(opcode,"RESW")==0)
        {
            locctr+=atoi(operand)*3;
        }
        else if(strcmp(opcode,"RESB")==0)
        {
            locctr+=atoi(operand);
        }
        else if(opcodefun(opcode)==1)
        {
            locctr+=3;
        }
        else if(!strcmp(opcode,"END"))
        {   
        	break;
        }
        else
        {
            printf("Invalid opcode on line:%d\n",lc);
        }
        
        fgets(line,50,f);
        lc++;
        m=mktoken(line);
    }
    
    fprintf(len,"%06x",locctr);
    
} 
