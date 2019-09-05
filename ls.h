void ls(char d[1000])
{
DIR *p;
struct dirent *d1;
char cwd[1000];
p=opendir(d);
 if(p==NULL){
  perror("can't find directory");
  exit(-1);
}

while(d1=readdir(p))
 printf("%s\n",d1->d_name);
 printf("\n");
}
