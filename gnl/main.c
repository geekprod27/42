#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char	*line;
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf(">>> line : |%s| <<<\n", line);
		free(line);
	}

}