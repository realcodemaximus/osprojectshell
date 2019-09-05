void wc(char * example,int bit)
{
    FILE *filePointer;
    char ch;
    
    filePointer = fopen(example,"r");
    
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        int ans = 0,chr = 0,nl = 0,longestLine = 0,line = 0,byte=0;
        printf("%c",ch);
        
        while ((ch = fgetc(filePointer)) != EOF)
        {
            if(ch == '\n'){
                nl++;
                if(longestLine < line){
                    longestLine = line;
                }
                line=0;
            }else{
                line++;
            }
            
            if(ch!='\n' && ch!=' ')
            chr++;
            
            byte++;
        }
        if(bit==0){
        printf("char :%d \n",chr);
        printf("bytes :%d \n",byte);
        printf("no. of lines :%d \n",nl);
        printf("length of a longest line :%d \n",longestLine);
        }
        if(bit==1)
        {
            printf("no. of lines :%d \n",nl);
        }
        if(bit==2)
        {
            printf("char :%d \n",chr);
        }
        if (bit==3)
        {
            printf("bytes :%d \n",byte);
        }
        if(bit==4)
        {
            printf("length of a longest line :%d \n",longestLine);
        }
    }
    
    fclose(filePointer);
}
