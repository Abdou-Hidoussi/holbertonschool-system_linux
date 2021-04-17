#include "hls.h"

int main(int argc, char const *argv[])
{
    int op[4] = {0, 0, 0, 0};
    Node_t *files = NULL, *head = NULL;

    files = count_flags(argc, argv, op);
    head = files;
    while (files != NULL)
    {
        printf("%s", files->str);
        files = files->next;
    }
    show_dir(head, op);
    free_list(head);
    return 0;
}
