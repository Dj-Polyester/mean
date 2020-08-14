#ifndef DEFINE_H
#define DEFINE_H

#define MKDIR createDir
#define MKFILE createFile
#define CURRDIR currdir()
#define ABSDIR(path) join(currdir(),path)
#define RELDIR(path) join(".",path)
#define ISEQUAL !strcmp
#define BUFFERSIZE 1000

#endif