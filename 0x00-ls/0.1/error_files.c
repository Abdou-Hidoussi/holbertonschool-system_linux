#include "hls.h"
/**
 * error_file - error treatment
 * @cmd: name of file
 */
void error_file(char const *cmd)
{
	fprintf(stderr, "hls: cannot access %s: ", cmd);
	perror("");
}
