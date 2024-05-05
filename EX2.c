#include<stdio.h>
#include<conio.h> 
#include<ctype.h> 
#include<stdlib.h> 
#include<string.h> 
#include<math.h>
void main()
{
    int i=0,j=0,x=0,n,flag=0; 
    void *p,*add[5];
    char ch,srch,b[15],d[15],c;
    printf("Enter the Expression terminated by $:");
    while((c=getchar())!='$')
    {
        b[i]=c; i++;
    }
    n=i-1;
    printf("Given Expression:");
    i=0;
    while(i<=n)
    {
        printf("%c",b[i]); 
        i++;
    }
    printf("\n Symbol Table\n"); 
    printf("Symbol\taddr\t\ttype"); 
    while(j<=n)
    {
        c=b[j]; 
        if(isalpha(toascii(c)))
        {
            if(j==n)
            {           
                p=malloc(c); 
                add[x]=p;
                d[x]=c;
                printf("%c\t%d\tidentifier",c,p);
            }   
            else
            {
                ch=b[j+1];
                if(ch=='+'||ch=='-'||ch=='*'||ch=='=')
                {
                    p=malloc(c); 
                    add[x]=p;
                    d[x]=c; 
                    printf("\n%c\t%d\tidentifier\n",c,p); 
                    x++;
                }
            }
        } 
        j++;
    }
    printf("\n The symbol is to be searched"); 
    srch='B';
    for(i=0;i<=x;i++)
    {
        if(srch==d[i])
        {
            printf("\n Symbol Found"); 
            printf("\n%c @address %d\n",srch,add[i]); 
            flag=1;
        }
    }
    if(flag==0)
        printf("\nSymbol Not Found"); 
    getch();
}