#include "hls.h"
/**
*main - 0
*@argc: number of arguments
*@argv: passing arguments
*Return: int
*/
int main(int argc, char const *argv[])
{
	int op[4] = {0, 0, 0, 0};
	Node_t *files = NULL, *head = NULL;

	files = count_flags(argc, argv, op);
	head = files;

	show_dir(head, op);

	free_list(head);
	return (0);
}
