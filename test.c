#include <fcntl.h>
int	main()
{
	open("test.txt", O_RDONLY);
	sleep(1100000);
}
