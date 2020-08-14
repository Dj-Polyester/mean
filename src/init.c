#include "../include/init.h"

void createFiles()
{
    //init backend folders

    const char* backendDir = RELDIR("/backend");
    const char* dbDir = RELDIR("/backend/db");
    const char* nodeDir = RELDIR("/backend/node_modules");
    const char* modelsDir = RELDIR("/backend/db/models");
    const char* routersDir = RELDIR("/backend/db/routers");

    MKDIR(backendDir);
    MKDIR(dbDir);
    MKDIR(nodeDir);
    MKDIR(modelsDir);
    MKDIR(routersDir);

    const char* mongooseDir = RELDIR("/backend/db/mongoose.js");
    const char* urlDir = RELDIR("/backend/db/url.js");
    const char* gitignoreDir = RELDIR("/backend/db/.gitignore");
    const char* appDir = RELDIR("/backend/app.js");

    //init backend files
    FILE* fptr = MKFILE(mongooseDir);
    fprintf(fptr, MONGOOSELITERAL); 
    fclose(fptr);

    fptr = MKFILE(urlDir);
    fprintf(fptr, URLLITERAL);
    fclose(fptr);
    
    fptr = MKFILE(appDir);
    fprintf(fptr, APPLITERAL);
    fclose(fptr);
    
    fptr = MKFILE(gitignoreDir);
    fprintf(fptr, GITIGNORELITERAL);
    fclose(fptr);

    free(backendDir);
    free(dbDir);
    free(nodeDir);
    free(modelsDir);
    free(routersDir);
    
    free(mongooseDir);
    free(urlDir);
    free(appDir);
}

void initFrontLinux()
{
    system("ng new frontend");
}
void initBackLinux()
{
    createFiles();
    system("cd ./backend && npm init && npm i express mongoose && npm i nodemon --save-dev");
    replaceFileLine("./backend/package.json",13,NPMLITERAL);
}
void initBackLinuxY()
{
    createFiles();
    system("cd ./backend && npm init -y && npm i express mongoose && npm i nodemon --save-dev");
    // printf("DONE------------------------------------------------------------------");
    replaceFileLine("./backend/package.json",13,NPMLITERAL);
}
