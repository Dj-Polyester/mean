#include "../include/global.h"

char* currdir()
{
	long path_max;
    size_t size;
    char *buf;
    char *ptr;


    path_max = pathconf(".", _PC_PATH_MAX);
    if (path_max == -1)
        size = 1024;
    else if (path_max > 10240)
        size = 10240;
    else
        size = path_max;


    for (buf = ptr = NULL; ptr == NULL; size *= 2)
    {
        if ((buf = realloc(buf, size)) == NULL)
        {
           error("Could not allocate buffer");
        }

        ptr = getcwd(buf, size);
        if (ptr == NULL && errno != ERANGE)
        {
            error("Could not get current directory");
        }
    }

    free (buf);
    return ptr;
}
char* join(char* s1,char* s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1); 
    strcpy(result, s1);
    strcat(result, s2);
    
    return result;
}
void createDir(const char* dirname)
{
    struct stat st = {0};
    if (stat(dirname, &st) == -1)
        mkdir(dirname, 0777);
    else
    {
        printf("Path %s already exists\n",dirname);
    }
}
FILE* createFile(const char* dirname)
{
    FILE* fptr;
    if (!(fptr = fopen(dirname,"w+")))
    {
        printf("Could not open %s\n",dirname);
        fclose(fptr);
        exit(1);
    }
    return fptr;
}
void error(char* str)
{
	printf("%s",str);
	printf("\n");
	exit(1);
}
void replaceFileLine(const char* path,int line,const char* txt2replace)
{
    
    /* File pointer to hold reference of input file */
    FILE * fPtr;
    FILE * fTemp;
    
    int count;
    
    char buffer[BUFFERSIZE];

    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        exit(1);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, BUFFERSIZE, fPtr)) != NULL)
    {
        count++;

        /* If current line is line to replace */
        if (count == line)
            //fputs(txt2replace, fTemp);
             fprintf(fTemp,txt2replace);
            // fprintf(fTemp,"\nheyman\n");
            // fputs(txt2replace, fTemp);
        else
            fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temporary file as original file */
    rename("replace.tmp", path);
}
