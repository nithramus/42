#include <stdlib.h>
#include <unistd.h>

int main()
{
	int i;
	char *yolo;

	i = 0;
	while (i < 100000)
	{
		yolo = malloc(50);
		write(1, "test\ntest\ntest\ntest\ntest\ntest\ntest\ntest\ntest\ntest\n", 50);
		free(yolo);
		i++;
	}
	return(1);
}

