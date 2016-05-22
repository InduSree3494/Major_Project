#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Triplet.h"
int flag=0;
char obj_owl[50],pred_owl[50];

int search( char line[], char obj[])
{        
	int l,i,j,lo,index,k;
        l=strlen(line);
        lo=strlen(obj);
	i=0,j=0;
        while(i<l)
        {
	    if (line[i]==obj[0])
		{
		   index=0;
		   for (k=0;k<lo,i<l;k++)
			{
			   if (line[i]!=obj[k])
				break;
			   else 
				{
				  obj_owl[index]=line[i];
				  index++;
				  i++;
				}
			}
		    if (k==lo && i<l)
			{
			    while (i<l && line[i]!='"')
				{
				   obj_owl[index]=line[i];
			           i++;
			           index++;
				}
			   if(line[i]=='"')
			      flag=1;
			}
		}
	    else 
		{
		   i++;
		}
      if(flag==1)
         break;
	
	}
obj_owl[index]='\0'; 
printf("%s",obj_owl);          
return flag;
}

 
 
int main()
{
  char sub[50],obj[50],pred[50];
  FILE *fp;
  fp=fopen("TK.owl","r+");
  char *str="(ROOT (SBARQ (WHNP (WP Who)) (SQ (VP (VBD brought) (PRT (RP up)) (NP (NNP Tiger) (NN king)))) (. ?)))";
 /* printf("SUBJECT:%s\n",EXTRACT_SUBJECT(str));
  printf("PREDICATE:%s\n",EXTRACT_PREDICATE(str)); 
  printf("OBJECT:%s\n",EXTRACT_OBJECT(str));  */
  
  strcpy(sub,EXTRACT_SUBJECT(str));
  strcpy(pred,EXTRACT_PREDICATE(str));
  strcpy(obj,EXTRACT_OBJECT(str));


//to search for object  
  while(fp!=NULL)
	{
           char line[1000];
	   while(fgets(line,1000,fp)!= NULL) /* read a line from a file */
		 {
      			//printf("%s\n",line);//print the file contents on stdout.
                        flag=search(line,obj);
                        if(flag==1)
                              break;
			
    		 }
          if(flag==1)
               break;
			
	
	}


printf("%s\n",obj_owl);
  
}



