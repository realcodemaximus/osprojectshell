#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<limits.h>
#include<grp.h>
#include<pwd.h>
#include<time.h>
#include<sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include<ctype.h>
#include<fcntl.h>
#include"wc.h"
#include"ls.h"
#include"ls-l.h"
int main()
{   int pid;
    int status;
    printf("This is shell of group 16\n");
    printf("Group@16#\n");
    while(1)
    {
    pid=fork();
    if(pid==-1)
    {
        printf("BAD FORK\n");
        exit(1);
    }
    if(pid==0)
    {
	  char s[1000],s1[1000],s2[1000],s3[1000],s4[1000];
	  int i,j;
   	 scanf(" %[^\n]",s);
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

	 // Determining the type of first command. Type becomes 1 if command has no file arguement , otherwise 2.

   	 int type=2,flag=0;
   	 for(i=0;i<strlen(s);i++)
   	 {
        	if(isspace(s[i]))
        	{
            		break;
       		}
         	s1[i]=s[i];
   	}

   	 if(s1[0]=='l')
   	 type=1;

	 // Determing the source file for the operation to be performed . It is only done for commands of type 2

	 if(type==2)
	 {
	 int index=i+1;
	 i=0;
	 for(index;index<strlen(s);index++)
	 {
		
		if(isspace(s[index]))
			break;
		s2[i]=s[index];
		i++;
	 }
	// checking if there is a output redirection operator		
	 }
         for(i=0;i<strlen(s)-2;i++)
   	 {
       		 if(isspace(s[i]) && s[i+1]=='>' && isspace(s[i+2]))
       		 {
           		 flag=1;
           		 break;
       		 }    
   	 }
	 
	 // If flag==1 i.e we need to write output to some file, we will now read the name of the location from the user.

	 if(flag)
	 {
	 i=i+3;
	 j=0;
	 for(;i<strlen(s);i++)
	 {
	 	s3[j]=s[i];
		 j++;
	 }
	 }
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	//First calling dup() system call if flag==1 so to store the output

	 if(flag)
	 {
	 int file_desc = open(s3,O_WRONLY);
	 dup2(file_desc, 1);
	 }
      
        if(strncmp(s1,"ls-l",4)==0)
        {
        getcwd(s4,sizeof(s4)); 
        ls1();
		exit(0);
        }

		else if((strncmp(s1,"ls",2)==0)||type==1)
        {
        getcwd(s4,sizeof(s4));
        ls(s4);
		exit(0);
        }

        else
		{

        if(strncmp(s1,"wc-l",4)==0)
        wc(s2,1);
        
		else if(strncmp(s1,"wc-c",4)==0)
        wc(s2,2);
        
		else if(strncmp(s1,"wc-m",4)==0)
        wc(s2,3);
        
		else if(strncmp(s1,"wc-L",4)==0)
        wc(s2,4);
        
		else if(strncmp(s1,"wc",2)==0)
        wc(s2,0);
        
		exit(0);
	}
    }
    else                   
    {
        wait(&status);
        printf("Group@16# \n");
    }
    }
}
