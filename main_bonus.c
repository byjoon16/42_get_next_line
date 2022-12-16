#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
// 파일을 여는 open() 함수와 O_RDONLY 등의 파일 접근 모드가 정의

int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	printf("fd2: %d\n", fd2);

	line = get_next_line(fd);
	printf("%s", line);
	line2 = get_next_line(fd2);
	printf("%s", line2);

	free(line);
	free(line2);
	
	line = get_next_line(fd);
	printf("%s", line);
	line2 = get_next_line(fd2);
	printf("%s", line2);

	free(line);
	free(line2);

	close(fd);
	close(fd2);
	system("leaks a.out");
	return (0);
}