#include "hls.h"
/**
 * error_file - error treatment
 * @name: name of program
 * @cmd: name of file
 */
void error_file(char const *name, char const *cmd)
{
	printf("%s : %s : %i\n", name, cmd, errno);
}
