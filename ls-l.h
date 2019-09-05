void printFileProperties(struct stat stats)
{
    struct tm dt;

    struct passwd *pw = getpwuid(stats.st_uid);
    struct group  *gr = getgrgid(stats.st_gid);
     printf("\nno of links:   %ld",stats.st_nlink);
    printf("\n%s %s", pw->pw_name, gr->gr_name);
    // File permissions
    printf("\nFile access: ");
    if (stats.st_mode & R_OK)
        printf("read ");
    if (stats.st_mode & W_OK)
        printf("write ");
    if (stats.st_mode & X_OK)
        printf("execute");

    // File size
    printf("\nFile size: %ld", stats.st_size);

    // Get file creation time in seconds and 
    // convert seconds to date and time format
    dt = *(gmtime(&stats.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d ", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

    // File modification time
    dt = *(gmtime(&stats.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

}

void ls1()
{   char d[1000];
    DIR *p;
    struct dirent *d1;
    struct stat stats;
    getcwd(d,sizeof(d));
    p=opendir(d);
    if(p==NULL){
    perror("can't find directory");
    exit(-1);
    }
    char a='/';
    while(d1=readdir(p))
    {
        char s[100];
        strcat(s,d);
        int i=0;
        while(s[i]!='\0')
        i++;
        s[i]='/';
        s[i+1]='\0';
        if((d1->d_name[0])!='.')
        {
            strcat(s,(d1->d_name));
            //printf("1 \n");
            // printf("%s\n",s);
            if (stat(s, &stats) == 0)
            {
                printFileProperties(stats);
            }
            else
            {
                printf("Unable to get file properties.\n");
                printf("Please check whether '%s' file exists.\n", s);
            }
             printf("\n%s\n",d1->d_name);
        }
        strcpy(s,"");
    }
}   

