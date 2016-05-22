#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

double count_words(char *name)   // Find number of words in a tone file
{
  char word[50];
  double count=0;
  FILE *fp1;
  fp1=fopen(name,"r+");
  while(fscanf(fp1,"%s",word)==1)
       { 
        count++;
       }
  fclose(fp1);
  return count;
}

double max(double i,double j)  // find max of two given numbers
{
   return i>j?i:j;
}

double max5(double sum1,double sum2,double sum3,double sum4,double sum5)   //find max of 5 given numbers
{
  return max(sum1,max(sum2,max(sum3,max(sum4,sum5))));
}

double count_aword(char *name,char *word1)    //total number of occurence of a word in a file  
{
  char word[50];
  double count=0;
  FILE *fp1;
  fp1=fopen(name,"r+");
  while(fscanf(fp1,"%s",word)==1)
      { 
        if (!strcmp(word,word1))
           {
             count++;
           }
      }
  fclose(fp1);
  return count;
}


char np[5000][50];
int search (char *word)
{
int j;
j=0;

while(j<5000)  
{
  if(!strcmp(word,np[j]))
     return 1;
  j++;
}

 return 0;
}


int voc(char *name)
{
  int i;
int result;
  FILE *fp;
  fp=fopen(name,"r+");
  int count;
  count=0;
 char word[50];
 
i=0;
while(fscanf(fp, "%s",word)==1)
{
  
result=search(word);
if(result==0)
 { count++;
   strcpy(np[i],word);
   i++;
 }

}
//printf("%d\n",count);
return count;
}

int main()
{
  double countwc1,countwc2,countwc3,countwc4,countwc5,C1,C2,C3,C4,C5;
  char word[50],word2[50];
  int l,v1,v2,v3,v4,v5;
  FILE *fp,*fp1,*fp2,*fp3,*fp4,*fp5;
  fp=fopen("text1","r+");
  
  char tone1[50]="HAPPY";
  char tone2[50]="TECHNICAL";
  char tone3[50]="FEAR";
  char tone4[50]="MOTIVATING";
  char tone5[50]="AGGRESSIVE";

  //Counting total number of words in each tone file
  countwc1=count_words("tone1");
  countwc2=count_words("tone2");
  countwc3=count_words("fear.txt");
  countwc4=count_words("tone4");
  countwc5=count_words("tone5");
  v1= voc("tone1");
  //printf("%d\n",v1);
  v2= voc("tone2");
  v3= voc("fear.txt");
  v4= voc("tone4");
  v5= voc("tone5");
  int i;
  double p,q,sum;
  i=1;
  while (i<=5)
	{
	if (i==1)
	   {
	    sum=0;
	    q=countwc1;
	    while (fscanf(fp,"%s",word2)==1)   //for class 1
		{
                  l=strlen(word2);
                  if( (word2[l-1]==',') || (word2[l-1]=='.') || (word2[l-1]=='-') || (word2[l-1]=='?') ||(word2[l-1]==')') )
                     { strncpy(word,word2,l-1);
                       word[l-1]='\0';
                     }
                  else
                      strcpy(word,word2);
            
		  p=count_aword("tone1",word);
		  //printf("Class 1 %lf\n",p);   
		  sum+=log2((p+1)/(q+v1));
 		  //printf("Class 1 sum%lf\n",p);   
		}
	    C1=log2(1.0/5.0) + sum;
             printf("Happy :%lf\n",C1);
	   }

	else if(i==2)
		{
		sum=0;
		q=countwc2;
		while(fscanf(fp,"%s",word2)==1)   //for class 2
		{ 
		  l=strlen(word2);
                  if( (word2[l-1]==',') || (word2[l-1]=='.') || (word2[l-1]=='-') || (word2[l-1]=='?') ||(word2[l-1]==')') )
                     { strncpy(word,word2,l-1);
                       word[l-1]='\0';
                     }
                  else
                      strcpy(word,word2);

                  p=count_aword("tone2",word); 
		  //printf("Class 2 %lf\n",p);     
		  sum+=log2((p+1)/(q+v2));
		}
		C2=log2(1.0/5.0) + sum;
                printf("Technical :%lf\n",C2);
		}

        else if(i==3)
		{
		sum=0;
		q=countwc3;
		while(fscanf(fp,"%s",word2)==1)   //for class 3
		{ 

                  l=strlen(word2);
                  if( (word2[l-1]==',') || (word2[l-1]=='.') || (word2[l-1]=='-') || (word2[l-1]=='?') ||(word2[l-1]==')') )
                     { strncpy(word,word2,l-1);
                       word[l-1]='\0';
                     }
                  else
                      strcpy(word,word2);
            
		  p=count_aword("fear.txt",word);
		  //printf("Class 3 %lf\n",p);      
		   sum+=log2((p+1)/(q+v3));
		}
		C3=log2(1.0/5.0) + sum;
                printf("Fear :%lf\n",C3);
		}

        else if(i==4)
		{
		sum=0;
		q=countwc4;
		while(fscanf(fp,"%s",word2)==1)   //for class 4
		{ 
                  l=strlen(word2);
                  if( (word2[l-1]==',') || (word2[l-1]=='.') || (word2[l-1]=='-') || (word2[l-1]=='?') ||(word2[l-1]==')') )
                     { strncpy(word,word2,l-1);
                       word[l-1]='\0';
                     }
                  else
                      strcpy(word,word2);
            
		  p=count_aword("tone4",word);
		  //printf("Class 4 %lf\n",p);      
		 sum+=log2((p+1)/(q+v4));
		}
		C4=log2(1.0/5.0) + sum;
                 printf("Motivating :%lf\n",C4);
		}

        else if(i==5)
		{
		sum=0;
		q=countwc5;
		while(fscanf(fp,"%s",word2)==1)   //for class 5
		{ 
                 l=strlen(word2);
                  if( (word2[l-1]==',') || (word2[l-1]=='.') || (word2[l-1]=='-') || (word2[l-1]=='?') ||(word2[l-1]==')') )
                     { strncpy(word,word2,l-1);
                       word[l-1]='\0';
                     }
                  else
                      strcpy(word,word2);
            
		 p=count_aword("tone5",word);
		 //printf("Class 5 %lf\n",p);      
		 sum+=log2((p+1)/(q+v5));
		}
		C5=log2(1.0/5.0) + sum;
                printf("Aggressive :%lf\n",C5);
		}
	i++;
	fseek(fp,0,SEEK_SET);
	}  //end of while

int threshold ;
threshold = (C1+C2+C3+C4+C5)/5;
printf("Threshold: %d\n",threshold);
//Identify the tone
 if (max5(C1,C2,C3,C4,C5)==C1  && C1>threshold)
    printf("***%s***\n",tone1);
 else if (max5(C1,C2,C3,C4,C5)==C2 && C2>threshold)
         printf("***%s***\n",tone2);
       else if (max5(C1,C2,C3,C4,C5)==C3 && C3>threshold)
                printf("***%s***\n",tone3 );
	    else if (max5(C1,C2,C3,C4,C5)==C4 && C4>threshold)
                     printf("***%s***\n",tone4);
                 else if(C5>threshold)
                       printf("***%s***\n",tone5);
} //end of main
