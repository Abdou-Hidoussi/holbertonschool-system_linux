#include "hls.h"

void read_local_file()
{
    DIR *dir;
    struct dirent *read;

    if(dir = opendir("."))
    {
        while ((read = readdir(dir)) != NULL)
        {
            printf("%s ", (*read).d_name);
        }
        printf("\n");
        closedir(dir);
    }
}