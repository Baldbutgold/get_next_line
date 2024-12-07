#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = ft_strdup("");
	read(fd, buffer, BUFFER_SIZE);
	if (ft_strchr(buffer, '\n') >= 0)
	{
		printf("new line is here\n");
		//extract text here
	}
	else
	{
		printf("no new line was found\n");
		//read more here
	}
	line = ft_strjoin(line, buffer);
	return line;
}
int	main()
{
	int	fd;
	char	*c;

	fd = open("test.txt", O_RDONLY);
	c = get_next_line(fd);
	printf("%s", c);
	/*int i = 0;*/
	/*while (i < ft_strlen(c))*/
	/*{*/
	/*	printf("char : %c, value is %d\n", c[i], c[i]);*/
	/*	i++;*/
	/*}*/
}
