#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
// 파일을 여는 open() 함수와 O_RDONLY 등의 파일 접근 모드가 정의

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	//printf("%s", line); // 마지막 \0 확인
	free(line);
	close(fd);
	system("leaks a.out");
	return (0);
}
