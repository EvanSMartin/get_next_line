#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	*s;
	int		fd1;
	int		fd2;
	int		fd3;
	int		i1;
	int		i2;
	int		i3;

	i1 = 0;
	i2 = 0;
	i3 = 0;
	if (argc == 0)
		return (0);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);


	while(get_next_line(fd1, &s) > 0)
	{
			printf("%s\n", s);
			i1++;
	}
	while(get_next_line(fd2, &s) > 0)
	{
		printf("%s\n", s);
		i2++;
	}
	while(get_next_line(fd3, &s) > 0)
	{
		printf("%s\n", s);
		i3++;
	}

	printf("%d\n", i1);
	printf("%d\n", i2);
	printf("%d\n", i3);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
	

}
