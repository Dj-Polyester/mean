#include "../include/serve.h"

void serveBackLinux()
{
    system("cd backend && npm test");
}
void serveFrontLinux()
{
    system("ng serve --open");
}