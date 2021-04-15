#include "hls.h"

void get_options(int argc, char const *argv[],int *op)
{
    int i = 0;

    while (i < argc)
    {
        if (!strcmp(argv[i], "-1"))
        {
            op[0] = 1;
        }
        if (!strcmp(argv[i], "-a"))
        {
            op[1] = 1;
        }
        if (!strcmp(argv[i], "-A"))
        {
            op[2] = 1;
        }
        if (!strcmp(argv[i], "-l"))
        {
            op[3] = 1;
        }
        i++;
    }    
}