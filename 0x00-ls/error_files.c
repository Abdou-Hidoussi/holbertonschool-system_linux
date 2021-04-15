#include "hls.h"
/**
 * error_file - error treatment
 * @name: name of program
 * @cmd: name of file
 */
void error_file(char const *name, char const *cmd)
{
	printf("%s : %s : %s\n", name, cmd, strerror(errno));
}
