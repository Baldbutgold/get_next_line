#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*read;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	return buffer;
}
int	main()
{
	int	fd;
	char	*c;

	fd = open("test.txt", O_RDONLY);
	read(fd, c, 1);
	printf("%d\n", fd);
	printf("%c", c[0]);
}
