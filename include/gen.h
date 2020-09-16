#ifndef GLOBAL_H
#define GLOBAL_H

#include "literals.h"
#include "global.h"
#include "includes.h"
#include "defines.h"


void createModel(const char*, const char*, const char*);
void createRouter(const char*, const char*, const char*);
void createMR(const char*);
void genModelLinux();
char* capitalizeInitial(const char*);

#endif