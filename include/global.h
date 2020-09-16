#ifndef GLOBAL_H
#define GLOBAL_H

#if __APPLE__
	#define INIT initApple
	#define INITY initAppleY
	#define GENMODEL genModelApple
	#define SERVE serveApple

#elif _WIN32
    #define INIT initWin
	#define INITY initWinY
	#define GENMODEL genModelWin
	#define SERVE serveWin

#elif __linux__
    #define INIT initLinux
	#define INITY initLinuxY
	#define GENMODEL genModelLinux
	#define SERVE serveLinux
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