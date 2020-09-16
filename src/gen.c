#include "../include/gen.h"

char* capitalizeInitial(const char* tmp)
{
    char* capitalized = calloc(sizeof(char),45);
    strcpy(capitalized,tmp);
    capitalized[0] = toupper(capitalized[0]);

    return capitalized;
}
void createModel(const char* dirname, const char* modelname, const char* capitalized)
{
    sprintf(dirname,"./backend/db/models/%s.js",modelname);

    // FILE* fptr = MKFILE(dirname);
    FILE* fptr;
    if (!(fptr = fopen(dirname,"w+")))
    {
        printf("Could not open %s\n",dirname);
        fclose(fptr);
        exit(1);
    }
    fprintf(fptr,MODELLITERAL,modelname,capitalized,capitalized,modelname,capitalized);
    fclose(fptr);
}
void createRouter(const char* dirname, const char* routername, const char* capitalized)
{
    sprintf(dirname,"./backend/db/routers/%s.js",routername);

    // FILE* fptr = MKFILE(dirname);
    FILE* fptr;
    if (!(fptr = fopen(dirname,"w+")))
    {
        printf("Could not open %s\n",dirname);
        fclose(fptr);
        exit(1);
    }
    fprintf(fptr,ROUTERLITERAL,capitalized,routername);
    fclose(fptr);
}

void createMR(const char* tmp)
{
     
    char* modelname = calloc(sizeof(char),45);
    char* dirname = calloc(sizeof(char),48);

    strcpy(modelname,tmp);
    char* capitalized = capitalizeInitial(modelname);

    createModel(dirname,modelname,capitalized);
    createRouter(dirname,modelname,capitalized);
    
    free(capitalized);
    free(modelname);
    free(dirname);
}

void genModelLinux(int argc,const char* argv[])
{
    for (int i = 3; i < argc; i++)
    {
        createMR(argv[i]);

        char* name = calloc(80,sizeof(char));
        sprintf(name,ADDROUTERLITERAL,argv[i],argv[i],argv[i]);

        replaceFileLine("./backend/app.js",8,name);
        free(name);
    }
}