#include "hls.h"
/**
 * error_file - error treatment
 * @cmd: name of file
 */
void error_file(char const *cmd)
{

	switch (errno)
	{
	case 2:
		fprintf(stderr, "hls: cannot access %s: ", cmd);
		perror("");
		break;
	case 13:
		fprintf(stderr, "hls: cannot open directory %s: ", cmd);
		perror("");
		break;
	}

}
