#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int fl=0;
char* NP_SUBTREE(char *sentence) 
 { 
int i=0,l,count_close=0,count_open=0,j=0;
  l=strlen(sentence);
  char *np=(char *)malloc(sizeof(char) * l);
   
  while(i<l)
    {
       if ( sentence[i]=='(' && sentence[i+1]=='N' &&  sentence[i+2]=='P')
        { 
          count_open+=1;
          np[j]=sentence[i];
          np[j+1]=sentence[i+1];
          np[j+2]=sentence[i+2];  
          j+=3;
          i+=3;
          break;
        }
       i++;
   }
   
  while(i<l)
    {
     if (sentence[i]=='(')      
        count_open+=1;
     else if (sentence[i]==')')
             count_close+=1;
     np[j]=sentence[i] ; 
     i++;
     j++;
    
     if (count_open==count_close) 
        break;
    }
  np[j]='\0';
  return np;
  }
char* PP_SUBTREE(char *sentence) 
 { 
int i=0,l,count_close=0,count_open=0,j=0;
  l=strlen(sentence);
  char *np=(char *)malloc(sizeof(char) * l);
   
  while(i<l)
    {
       if ( sentence[i]=='(' && sentence[i+1]=='P' &&  sentence[i+2]=='P')
        { 
          count_open+=1;
          np[j]=sentence[i];
          np[j+1]=sentence[i+1];
          np[j+2]=sentence[i+2];  
          j+=3;
          i+=3;
          break;
        }
       i++;
   }
   
  while(i<l)
    {
     if (sentence[i]=='(')      
        count_open+=1;
     else if (sentence[i]==')')
             count_close+=1;
     np[j]=sentence[i] ; 
     i++;
     j++;
    
     if (count_open==count_close) 
        break;
    }
  np[j]='\0';
  return np;
  }
char* VP_SUBTREE(char *sentence) 
 { 
int i=0,l,j=0,count_open=0,count_close=0;
  l=strlen(sentence);
  char *vp=(char *)malloc(sizeof(char) * l);
  while (i<l)
    {
       if( sentence[i]=='(' &&  sentence[i+1]=='V' && sentence[i+2]=='P')
        { count_open+=1;
          vp[j]=sentence[i];
          vp[j+1]=sentence[i+1]; 
          vp[j+2]= sentence[i+2];
          j+=3;
          i+=3;
          break;
        }
   i++;
     }
    while(i<l)
    {
     if (sentence[i]=='(')      
       { count_open+=1;
         
       }
     else if (sentence[i]==')')
      { count_close+=1;
      } 
   
     vp[j]=sentence[i] ; 
     i++;
     j++;
    
   if(count_open==count_close) 
       break;
    }
vp[j]='\0';
return vp;
}

int LEVEL(char *sentence,char *tag)  //to find level of tags
{
   int l,level,length,flag;
flag=0;
level=0;
   l=strlen(sentence);
 length=strlen(tag);

   int i;
  i=9;
if(length==2)
{
  while(i<l)
{
   if(sentence[i]=='(')
      level=level+1;
   
   else if(sentence[i]==')')
      level=level-1;
  i++;
  if(sentence[i]==tag[0] && sentence[i+1]==tag[1])
        {  flag=1;
           break;
         }
}
if(flag==1)
 return level;
else
 return -1;

}

else if (length==3)
{
while(i<l)
{
   if(sentence[i]=='(')
      level=level+1;
   
   else if(sentence[i]==')')
      level=level-1;
  i++;
  if(sentence[i]==tag[0] && sentence[i+1]==tag[1] && sentence[i+2]==tag[2])
        {    flag=1;
             break;
        }
}
if(flag==1)
 return level;
else
 return -1;;
}

else if (length==4)
{
  while(i<l)
{
   if(sentence[i]=='(')
      level=level+1;
   
   else if(sentence[i]==')')
      level=level-1;
  i++;
  if(sentence[i]==tag[0] && sentence[i+1]==tag[1] && sentence[i+2]==tag[2] && sentence[i+3]==tag[3])
        {  flag=1;
           break;
        }
}
if(flag==1)
 return level;
else
 return -1;
}
}

int INDEX(char *sentence,char *tag)  //to find the index of tags
{
  int i,l,length,flag;
  flag=0;
  i=0;
  l=strlen(sentence);
  length=strlen(tag);
if(length==2)
{
  while(i<l)
  {
    if (sentence[i]==tag[0] && sentence[i+1]==tag[1])
        { flag=1;
          break;
        }
   i++;
  }
if(flag==1)
 return i;
else
 return -1;
}

else if(length==3)
{
  while(i<l)
  {
    if (sentence[i]==tag[0] && sentence[i+1]==tag[1] && sentence[i+2]==tag[2])
        break;
   i++;
  }
if(flag==1)
 return i;
else
 return -1;
}

else if(length==4)
{
  while(i<l)
  {
    if (sentence[i]==tag[0] && sentence[i+1]==tag[1] && sentence[i+2]==tag[2] && sentence[i+3]==tag[3])
        break;
   i++;
  }
if(flag==1)
 return i;
else
 return -1;
}
}

/*char* EXTRACT_ATTRIBUTE(char *word,int flag,char *sentence)
{
  char *result;
 
    if (flag==1)
   {
      char *tag=(char *)malloc(sizeof(char) * 5);
      tag[0]='V';
      tag[1]='P';
      SIBLINGS(sentence,tag);
    }
} 

int SIBLINGS (char *sentence,char *tag)
{
int i,index,level,current_ind,l,lev,t_open,t_close,count_open,count_close;
t_open=0;
t_close=0;
count_open=0;
count_close=0;
i=0;
char *siblings=(char *)malloc(sizeof(char) * 100);

while(sentence[i]!=' ')
{  
    i++;
}
i=i+1;
printf("%d\n",i);
lev=LEVEL(sentence,tag);
index=INDEX(sentence,tag);
printf("%d\n",lev);
printf("%d\n",index);
current_ind=-1;
level=-1;
while(i<=index)           //to find index of the parent
{
//printf("%c\n",sentence[i]);
  if(sentence[i]=='(')
    {  level=level+1;
       if (level==lev-1 && i>current_ind)
          current_ind=i;
    }    
   else if (sentence[i]==')')
           level=level-1;
   i++;
}
int j;
j=0;
i=current_ind;
l=strlen(sentence);
printf("%d\n",i);
level=-1;
while(i<l)  //to start from parent and loop till break1 condition and copying the siblings to an array
{
  if (sentence[i]=='(')
     { 
       level=level+1;
       count_open+=1;
       if(sentence[i+1]!=tag[0] && sentence[i+2]!=tag[1] && level==lev)
            { 
              printf("%c\n",sentence[i]);
              while(i<l)
            { 
              if (sentence[i]=='(')
	         t_open+=1;
	       else if (sentence[i]==')')
	         t_close+=1; 
       
               if (t_open==t_close)
                    break;
               else
                   { siblings[j]=sentence[i];
                     j++;
                      
                   }
                 i++;
               }
            }
     }
 else if (sentence[i]==')')
           { 
             level=level-1;
             count_close+=1;    
           }
 i++;
 if (count_open==count_close)  //break1 condition
          break;     
}
siblings[j]='\0';
printf("%s\n",siblings);
}
*/
int MAX_LEVEL(char *sentence)
{
  int i,l,level,max;
   l=strlen(sentence);
   level=0;
    max=0;
    i=0;
  //printf("Here");
  while (i<l)
    {
      if (sentence[i]=='(')
       	  level++;
      else if (sentence[i]==')')
       	        level--;
      	      
      if (level > max)
      	 max=level;
      i++;
    }
  return max;
}

char* EXTRACT_OBJECT(char *sentence1)  //to find siblings of vp
{
  int index,count_close,count_open,t_open,t_close,j,i,l,lev,level,flag;
  char obj[50];
  char *sentence;
  char *tag=(char *)malloc(sizeof(char) *5);

  t_open=0;
  t_close=0;
  lev=LEVEL(sentence1,tag);
  index=INDEX(sentence1,tag);
  level=lev;
  sentence=VP_SUBTREE(sentence1);
l=strlen(sentence1);
  int len;
len=strlen(sentence);
//printf("%d",len);
 i=0;
j=0;
  char *dl=(char *)malloc(sizeof(char) * l);
if(fl==1)
{
//printf("dfdf");
 while (i<l)  //to search for dialogues
        {
if(sentence1[i]=='(' && sentence1[i+1]=='`' && sentence1[i+2]=='`' && sentence1[i+3]==' ' && sentence1[i+4]=='`' &&  sentence1[i+5]=='`' && sentence1[i+6]==')')
           { i=i+6;
            while (i< l && !(sentence1[i]=='(' && sentence1[i+1]=='\'' && sentence1[i+2]=='\'' && sentence1[i+3]==' ' && sentence1[i+4]=='\'' && sentence1[i+5]=='\'' && sentence1[i+6]==')'))
		{//printf("Here\n");
                   
		   if( sentence1[i]==' ' && sentence1[i+1]!='(')
			   { i++;
			     while (sentence1[i]!=')')
			      { 
				dl[j]=sentence1[i];
				//printf("%c\n",dl[j]);
				i++;
				j++;
			      } 
                             dl[j]=' '; 
                             j++;
			   }
		    i++;
                   
		}
	   }
	else i++;
           }
	dl[j]='\0';

printf("OBJECT : %s\n",dl);

}
else
{
j=0;
i=0;
  /* In absence of VP subtree */
  if (len==0)            //If VP subtree is absent look for deepest noun of PP subtree
   {
    char *nptree=NP_SUBTREE(sentence1);
    char *pptree=PP_SUBTREE(nptree);
  /*  l=strlen(nptreeparent);
    i=4;
    j=0;
    char *np=(char *)malloc(sizeof(char) * l);
    while (i<l)
    { np[j]=nptreeparent[i];
      i++;
      j++; 
    }
    j--;
    np[j]='\0';
*/
    //printf("%s\n",pptree);
    int l=strlen(pptree),i=0,
    level=0,
    maxlevel=0,
    flag=0,maxindex=0;
    char *obj1=(char *)malloc(sizeof(char) * l);
 while (i<l)
      {
        if (pptree[i]=='(')
           {
             level++;
             if (level > maxlevel && pptree[i+1]=='N')
                {
                 maxlevel=level;
                 maxindex=i;
                }  	
           }
        else if (pptree[i]==')')
                level--;
        i++;
      }
      
 i=maxindex;
 if (pptree[i+1]=='N' && pptree[i+2]=='N')
    {i=i+4;
       j=0;
  while (pptree[i]!=')')
       {
        obj1[j]=pptree[i];
        j++;
        i++;
       }
  obj1[j]='\0';
printf("OBJECT:%s\n",obj1);
	}
 else if (pptree[i+1]=='N' && pptree[i+2]=='N' && pptree[i+3]=='P')
    {
	i=i+5;
  j=0;
  while (pptree[i]!=')')
       {
        obj1[j]=pptree[i];
        j++;
        i++;
       }
       while(i<l)
       {
       	if (pptree[i+1]=='N' && pptree[i+2]=='N' && pptree[i+3]=='P')
       	{
       		 	i=i+5;
       		 	obj1[j]=' ';
       		 	j++;
							
			  while (pptree[i]!=')')
			       {
			        obj1[j]=pptree[i];
			        j++;
			        i++;
			       }
       
		   }
	   }
       
  obj1[j]='\0';
printf("OBJECT:%s\n",obj1); 
  
  
}
   }
  /* end of absence of VP subtree */
else
{
  //printf("%s\n",sentence);
  l=strlen(sentence);

  i=0;     
  //printf("%c\n",sentence[i]);            //i initialised to index of VP
  //printf("i before is %d\n",i); 
  count_open=0;
  count_close=0;
  while (i<l)  //to start from VP and loop till break1 condition
        {
         //printf("i is %d\n",i);
         //printf("%c\n",sentence[i]);
	  if (sentence[i]=='(')
	     { 
	       //printf("%c\n",sentence[i]);
	      count_open+=1;
	      if ((sentence[i+1]=='N' && sentence[i+2]=='P') || (sentence[i+1]=='P' && sentence[i+2]=='P'))  
		  {               
		   while(i<l)
		   {
		     if(sentence[i]=='(')
			 t_open+=1;
		     else if (sentence[i]==')')
			  t_close+=1;
		     else if ((sentence[i]=='N' && sentence[i+1]=='N' ) || (sentence[i]=='W' && sentence[i+1]=='P' ))
				 {  i=i+3; //skipping space
				    j=0;
				    while(sentence[i]!=')')
					{ 
					 obj[j]=sentence[i];
					 j++;
					 i++;
					}
				    obj[j]='\0';
		                    //printf("%s\n",obj);
		                    
			            tag[0]='N';
				    tag[1]='N';
				    tag[2]='\0';

		                    flag=1;
		                    if(flag==1)
		                      break;
				    i--; 
				 }
		    i++;
		    if (t_close==t_open)
		       {
			t_close=0;
			t_open=0;
			break;
		       }
		 }
		}

	if (sentence[i+1]=='A' && sentence[i+2]=='D' && sentence[i+3]== 'J' && sentence[i+4]=='P' ) 
		  { 
		   while(i<l)
		   {              
		      if (sentence[i]=='(')
		         t_open+=1;
		      else if (sentence[i]==')')
		              t_close+=1;
		           else if (sentence[i]=='J' && sentence[i+1]=='J')
		                   { 
				    i=i+3; //skipping space
		                    j=0;
		                    while (sentence[i]!=')')
				      { 
					obj[j]=sentence[i];
				        j++;
				        i++;
				      }
		           	    obj[j]='\0';
		                    flag=2;
				    tag[0]='J';
				    tag[1]='J';
				  
		                    i--; 
		                   }
				else if ( sentence[i] == 'J' && sentence[i+1]== 'J' && sentence[i+2]=='R')
					  {
					    i=i+4; //skipping space
					    j=0;
					    while(sentence[i]!=')')
					      { obj[j]=sentence[i];
						j++;
						i++;
					      }
					    obj[j]='\0'; 
					    i--;
					  }             
		      i++;
		      if (t_close==t_open)
			 {
			  t_close=0;
			  t_open=0;
			  break;
			 }
		 }
	       }
	 if (flag==1)
	    break;
	     
	    }
         else if(sentence[i]==')')
		   { 
		     count_close+=1;    
		   }
      
   i++;
//printf("i is %d\n",i);
   if(count_open==count_close)  //break1 condition
          break;
}   //end of while
 
printf("OBJECT:%s\n",obj);

}
//printf("%d\n",flag); 
//EXTRACT_ATTRIBUTE(obj,flag,sentence1);      
}
}   //end of function EXTRACT_OBJECT

char* EXTRACT_SUBJECT(char *sentence)
{
  int i,j,k,l,level,flag=0;
  char *sub;
  if (sentence[7]=='S' && sentence[8]=='B' && sentence[9]=='A' && sentence[10]=='R' && sentence[11]=='Q')  //WHNP 
     {
       i=6;
       l=strlen(sentence);
       sub=(char *)malloc(sizeof(char) * l);
         
       while(i<l)
       {
         if (sentence[i]=='(' && sentence[i+1]=='W' && sentence[i+2]=='P')  //For who and what
            {
              i=i+4;
              k=0;
              while (sentence[i]!=')')
                   {
                     sub[k]=sentence[i];
                     i++;
                     k++;
                   }
              sub[k]='\0';
	      break;
            }
         if (sentence[i]=='(' && sentence[i+1]=='W' && sentence[i+2]=='D' && sentence[i+3]=='T')   // For which
            {
              i=i+5;
              k=0;
              while (sentence[i]!=')')
                   {
                     sub[k]=sentence[i];
                     i++;
                     k++;
                   }
              sub[k]='\0';
            }
            i++;
       }
     }
  else
     {    
     	  char *nptree=NP_SUBTREE(sentence);
          int maxlevel=MAX_LEVEL(nptree);    //Finding max level of NP subtree
          //printf("%s\n",nptree);
          l=strlen(nptree);
          sub=(char *)malloc(sizeof(char) * l);
	  for (k=2;k<=maxlevel;k++)
	     {
	       i=0;
	       level=0;
	       while (i<l)
	  	{
	  	  if (nptree[i]=='(')
	  	    {     
	  	          level++;
	  	          if (level==k)
	  	          {
	  	            if (nptree[i+1]=='N' && nptree[i+2]=='N')
	  	             {
	  	     	       i=i+4;
	  	     	       j=0;
	  	     	       while (nptree[i]!=')')
	  	     	             {
	  	     	              sub[j]=nptree[i];
	  	     	              j++;
	  	     	              i++;
	  	     	             }
	  	     	      sub[j]='\0';
	  	     	      flag=1;
	  	             }
		  	    if (nptree[i+1]=='N' && nptree[i+2]=='N' && nptree[i+3]=='S')
		  	     {
		  	     	i=i+5;
		  	     	j=0;
		  	     	while (nptree[i]!=')')
		  	     	      {
		  	     	      sub[j]=nptree[i];
		  	     	      j++;
		  	     	      i++;
		  	     	      }
		  	     	sub[j]='\0';
		  	     	flag=1;
		  	     }
		  	    if (nptree[i+1]=='N' && nptree[i+2]=='N' && nptree[i+3]=='P')
		  	     {
		  	     	i=i+5;
		  	     	j=0;
		  	     	while (nptree[i]!=')')
		  	     	      {
		  	     	      sub[j]=nptree[i];
		  	     	      j++;
		  	     	      i++;
		  	     	      }
		  	     	
		  	    /* while(i<l)
		  	     	 { 
						if (nptree[i+1]=='N' && nptree[i+2]=='N')
		  	             {
		  	     	i=i+4;
		  	     	sub[j]=' ';
		  	     	j++;
		  	     	while (nptree[i]!=')')
		  	     	      {
		  	     	      sub[j]=nptree[i];
		  	     	      j++;
		  	     	      i++;
		  	     	      }
						}
		  	     	
		  	     }*/
		  	     sub[j]='\0';
		  	     	flag=1;
		  }
		  	    if (nptree[i+1]=='N' && nptree[i+2]=='N' && nptree[i+3]=='P' && nptree[i+4]=='S')
		  	     {
		  	     	i=i+6;
		  	     	j=0;
		  	     	while (nptree[i]!=')')
		  	     	      {
		  	     	      sub[j]=nptree[i];
		  	     	      j++;
		  	     	      i++;
		  	     	      }
		  	     	sub[j]='\0';
		  	     	flag=1;
	  	             }
	  	             if (nptree[i+1]=='P' && nptree[i+2]=='R' && nptree[i+3]=='P' && nptree[i+4]==' ' )  //Personal Pronoun
	  	             {
	  	     	       i=i+5;
	  	     	       j=0;
	  	     	       while (nptree[i]!=')')
	  	     	             {
	  	     	              sub[j]=nptree[i];
	  	     	              j++;
	  	     	              i++;
	  	     	             }
	  	     	      sub[j]='\0';
	  	     	      flag=1;
	  	             }
	  	          }  // level==k
	  	   }
	  	  else if (nptree[i]==')')
	  	        {
	  	          level--; 
	  	        }
	  	  i++;
	  	  if (flag==1)
	  	    break;
		}   //end of while  
	  
	  	  if (flag==1)
	  	  break;
	    } //end of for
    }
    return sub;
}

char* EXTRACT_PREDICATE(char *sentence)
{
 //printf("fdfdhhthjfj\n");
 int i=0,l,maxindex,level=0,maxlevel=0,flag=0,j;
 char *vptree=VP_SUBTREE(sentence);
//printf("%s\n",vptree);
int len;
len=strlen(vptree);
//printf("%d",len);
 if (len==0)            //If VP subtree is absent look for deepest noun of NP subtree which is sibling PP subtree
   {
    char *nptreeparent=NP_SUBTREE(sentence);
    
    l=strlen(nptreeparent);
    i=4;
    j=0;
    char *np=(char *)malloc(sizeof(char) * l);
    while (i<l)
    { np[j]=nptreeparent[i];
      i++;
      j++; 
    }
    j--;
    np[j]='\0';
    char *nptree=NP_SUBTREE(np);  //To get NP subtree of NP subtree ie; sibling of PP subtree
    //printf("%s\n",nptree);
     
    l=strlen(nptree);
    i=0;
    level=0;
    maxlevel=0;
    flag=0;
    char *obj1=(char *)malloc(sizeof(char) * l);
 while (i<l)
      {
	
        if (nptree[i]=='(')
           {
             level++;
             if (level > maxlevel && nptree[i+1]=='N')
                {
                 maxlevel=level;
                 maxindex=i;
                }  	
           }
        else if (nptree[i]==')')
                level--;
        i++;
      }
      
 i=maxindex;
 if (nptree[i+1]=='N' && nptree[i+2]=='N')
    i=i+4;
  j=0;
  while (nptree[i]!=')')
       {
        obj1[j]=nptree[i];
        j++;
        i++;
       }
  obj1[j]='\0';
  return obj1;
    
   }
 else 
 {
 l=strlen(vptree);
 i=0;
 level=0;
 maxlevel=0;
 flag=0;
 char *obj=(char *)malloc(sizeof(char) * l);
 while (i<l)
      {
      if(vptree[i]=='(' && vptree[i+1]=='`' && vptree[i+2]=='`' && vptree[i+3]==' ' && vptree[i+4]=='`' &&  vptree[i+5]=='`' && vptree[i+6]==')')
         { fl=1;
           break;
         }
        if (vptree[i]=='(')
           {
             level++;
             if (level > maxlevel && vptree[i+1]=='V')
                {
                 maxlevel=level;
                 maxindex=i;
                }  	
           }
        else if (vptree[i]==')')
                level--;
        i++;
      }
      
 i=maxindex;
 if (vptree[i+1]=='V' && vptree[i+2]=='B')
    i=i+4;
 else if (vptree[i+1]=='V' && vptree[i+2]=='B' && vptree[i+3]=='G')
         i=i+5;
      else if (vptree[i+1]=='V' && vptree[i+2]=='B' && vptree[i+3]=='D')
              i=i+5;
           else if (vptree[i+1]=='V' && vptree[i+2]=='B' && vptree[i+3]=='N')
           	    i=i+5;
           	else if (vptree[i+1]=='V' && vptree[i+2]=='B' && vptree[i+3]=='P')
           	         i=i+5;
           	     else if (vptree[i+1]=='V' && vptree[i+2]=='B' && vptree[i+3]=='Z')
           	             i=i+5;
  j=0;
  while (vptree[i]!=')')
       {
        obj[j]=vptree[i];
        j++;
        i++;
       }
  obj[j]='\0';

  return obj;
 
}


}

char* EXTRACT_DIALOGUES(char *sentence)
{
int i,l,j;
i=0;
j=0;
l=strlen(sentence);
i=i+13;
char *dl=(char *)malloc(sizeof(char) * l);
while (i<l)  //to search for dialogues
        {
if(sentence[i]=='(' && sentence[i+1]=='`' && sentence[i+2]=='`' && sentence[i+3]==' ' && sentence[i+4]=='`' &&  sentence[i+5]=='`' && sentence[i+6]==')')
           { i=i+6;
            while (i< l && !(sentence[i]=='(' && sentence[i+1]=='\'' && sentence[i+2]=='\'' && sentence[i+3]==' ' && sentence[i+4]=='\'' && sentence[i+5]=='\'' && sentence[i+6]==')'))
		{//printf("Here\n");
                   
		   if( sentence[i]==' ' && sentence[i+1]!='(')
			   { i++;
			     while (sentence[i]!=')')
			      { 
				dl[j]=sentence[i];
				//printf("%c\n",dl[j]);
				i++;
				j++;
			      } 
                             dl[j]='_'; 
                             j++;
			   }
		    i++;
                   
		}
	   }
	else i++;
           }
	dl[j-1]='\0';


printf("OBJECT : %s\n",dl);	
printf("SUBJECT : Who\n");
printf("PREDICATE : said\n");	


}



int main()
{
	int l,i;
	i=0;
//char *nptreeparent="(NP (DT the) (NN author)) (PP (IN of) (NP (DT The) (NNP King)))";
//printf("%s",NP_SUBTREE(nptreeparent));
  char *str="(ROOT (SBARQ (WHNP (WP Who)) (SQ (VP (VBN authored) (NP (DT the) (NN TigerKing)))) (. ?)))";
  
  i=i+13;
  if(str[i]=='(' && str[i+1]=='`' && str[i+2]=='`' && str[i+3]==' ' && str[i+4]=='`' &&  str[i+5]=='`' && str[i+6]==')')
  {
  	EXTRACT_DIALOGUES(str);
  }
    
  else
  {
  
printf("SUBJECT:%s\n",EXTRACT_SUBJECT(str));
printf("PREDICATE:%s\n",EXTRACT_PREDICATE(str)); 
  EXTRACT_OBJECT(str);
//printf("%d\n",MAX_LEVEL(str));


}
}
