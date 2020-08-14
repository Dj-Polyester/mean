#ifndef GLOBAL_H
#define GLOBAL_H

#if __APPLE__
	#define INITBACK initBackApple
	#define INITBACKY initBackAppleY
	#define INITFRONT initFrontApple
	#define GENMODEL genModelApple
	#define GENCOMP genCompApple
	#define SERVEBACK serveBackApple
	#define SERVEFRONT serveFrontApple

#elif _WIN32
    #define INITBACK initBackWin
	#define INITBACKY initBackWinY
    #define INITFRONT initFrontWin
	#define GENMODEL genModelWin
	#define GENCOMP genCompWin
	#define SERVEBACK serveBackWin
	#define SERVEFRONT serveFrontWin

#elif __linux__
    #define INITBACK initBackLinux
	#define INITBACKY initBackLinuxY
    #define INITFRONT initFrontLinux
	#define GENMODEL genModelLinux
	#define GENCOMP genCompLinux
	#define SERVEBACK serveBackLinux
	#define SERVEFRONT serveFrontLinux
#endif

#include "includes.h"
#include "defines.h"
#include "literals.h"

char* currdir();
void error();
char* join(char*,char*);
FILE* createFile(const char*);
void createDir(const char*);
void replaceFileLine(const char*, int, const char*);

#endif