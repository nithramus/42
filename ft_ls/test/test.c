#include <unistd.h>

int main()
{
	int i;
	char test[] ="test\n";

	i = 0;
	while (i < 100000)
	{
		write(1, test, 5);
		write(1, test, 5);
		write(1, test, 5);
		write(1, test, 5);
		write(1, test, 5);
		write(1, test, 5);
		write(1, test, 5);
		write(1, test, 5);
		write(1, test, 5);
		write(1, test, 5);
		i++;
	}
	return (1);
}

