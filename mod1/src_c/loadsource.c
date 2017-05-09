#include "libft/libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char* LoadSource(const char *filename)
{
	int t;
	long size;
	char *file;

	t = open(filename, O_RDONLY);
	if (!t)
	{
		ft_putendl("fichier au mauvais endroit");
		return (0);
	}
	size = lseek(t, 0, SEEK_END);
	ft_printf("%ld\n", size);
	file = mem_stock(size + 1);
	if (!file)
	{
		ft_putendl("error");
		return (NULL);
	}
	lseek(t, 0, SEEK_SET);
	if (!(read(t, file, size)))
	{
		ft_putendl("erreur du fichier");
		return NULL;
	}
	file[size] = '\0';
	ft_putendl(file);
	return file;
}

