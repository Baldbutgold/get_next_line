#include "get_next_line.h"

char	*extract_line(char *buffer, char *line)
{
	size_t	pos;
	char	*extracted_line;

	pos = ft_strchr(buffer, '\n') + 1;
	extracted_line = ft_substr(buffer, 0, pos);
	line = ft_substr(buffer, pos, ft_strlen(buffer));
	return (extracted_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*test;
	static char	*line;
	int		read_pos;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = ft_strdup("");
	read_pos = read(fd, buffer, BUFFER_SIZE);
	buffer[read_pos] = 0;
	printf("this is buffer : %s", buffer);
	if (ft_strchr(buffer, '\n') >= 0)
	{
		printf("\\n exists\n");
		test = extract_line(buffer, line);
		printf("testing if line stores the rest of the string : %s\n", line);
		return test;
		//extract text here
	}
	else
	{
		printf("\\n doesn't exist\n");
		//read more here
	}
	return line;
}
int	main()
{
	int	fd;
	char	*c;

	fd = open("test.txt", O_RDONLY);
	c = get_next_line(fd);
	printf("%s", c);
}
