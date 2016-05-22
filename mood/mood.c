#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
int l,i,n;
l=0;
 char word[50],word1[50],word2[50],sump,sumn; 
FILE *fp,*fp1,*fp2;
   fp=fopen("text","r");
   fp1=fopen("pos.c","r+");
   fp2=fopen("neg.c","r+");
int countpos=0;
int countneg=0;
sump=0;
sumn=0;

while(fscanf(fp,"%s",word2)==1)
{
  
   //fscanf(fp,"%s",word2);
   //printf("%s\n",word2);
   l=strlen(word2);
   if( (word2[l-1]==',') || (word2[l-1]=='.') || (word2[l-1]=='-') || (word2[l-1]=='?') ||(word2[l-1]==')') )
      { strncpy(word,word2,l-1);
        word[l-1]='\0';
      }
   else
    strcpy(word,word2);

for(i=0;i<=strlen(word);i++)
{ if(word[i]>=97&&word[i]<=122) 
     word[i]=word[i]-32;
}
//printf("%s\n",word);

   while(fscanf(fp1,"%s",word1)==1)
    {
        //printf("%s\n",word1);
        if(!strcmp(word,word1))
           {
             //printf("%s\n",word);
             //printf("%s\n",word1);
               countpos+=1;
               if(countpos>=1)
                  { sump+=1;
                    break;
                   }
           }
    }
//printf("%d\n",countpos);
   while(fscanf(fp2,"%s",word1)==1)
    {
        
        if(!strcmp(word,word1))
           { 
             //printf("%s\n",word);
             countneg+=1;
             if(countneg>=1)
                {
                   sumn+=1;
                  break;
                 }
           }
    }

//printf("%d\n",countneg);
fseek(fp1,0,SEEK_SET);
fseek(fp2,0,SEEK_SET);
//n=ftell(fp);
//printf("%d\n",n);
countpos=0;
countneg=0;
}

//printf("%d",countpos);
//printf("%d",countneg);

if(sump>sumn)
  printf("***Mood is positive***\n");
else if (sump==sumn)
  printf("***Mood is neutral***\n");
else
   printf("***Mood is negative***\n"); 
}
