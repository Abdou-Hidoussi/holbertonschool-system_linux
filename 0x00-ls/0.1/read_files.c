#include "hls.h"

void read_files(int argc, char const *argv[],int *op)
{
    int i = 1;

    while (i < argc)
    {
        if (argv[i][0] != '-')
        {
            read_file(argv[i], op);
        }
        i++;
    }
    
}

void read_file(char const *name, int *op)
{
    DIR *dir;
    struct dirent *read;

    if(dir = opendir(name))
    {
        while ((read = readdir(dir)) != NULL)
        {
            if ((*read).d_name[0] != '.')
            {
                printf("%s ", (*read).d_name);
                if (op[0] == 1)
                {
                    printf("\n");
                }
            }
            else
            {
                if (op[1] == 1)
                {
                    printf("%s ", (*read).d_name);
                    if (op[0] == 1)
                    {
                        printf("\n");
                    }
                }
            }
        }
        printf("\n");
        closedir(dir);
    }
}