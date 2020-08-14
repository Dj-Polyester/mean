#include "../include/main.h"


int main(int argc, char const *argv[])
{ 
        //mean init [-y] --options
        if (ISEQUAL(argv[1],"init"))
        {
            if (argc == 3 && ISEQUAL(argv[2],"-y"))
            {
                INITBACKY();
                INITFRONT();
            }
            else if (argc == 2)
            {
                INITBACK();
                INITFRONT();
            }
            else error("Invalid number/set of items entered.");
        }
        //mean serve [b/f]
        else if (ISEQUAL(argv[1],"serve"))
        {
            if (argc > 2 && ISEQUAL(argv[2],"b"))
            {
                SERVEBACK(argc,argv);
            }
            else if (argc > 2 && ISEQUAL(argv[2],"f"))
            {
                SERVEFRONT();
            }
            else
                error("Invalid number/set of items entered.");
        }
        //mean gen [model/comp] --options
        else if (ISEQUAL(argv[1],"gen"))
        {
            if (argc > 3 && ISEQUAL(argv[2],"model"))
            {
                GENMODEL(argc,argv);
            }
            else if (argc > 3 && ISEQUAL(argv[2],"comp"))
            {
                GENCOMP();
            }
            else
                error("Invalid number/set of items entered.");
        }
        else
        {            
            error("Undefined argument. Try init, serve or gen");
        }
    return 0;
}
