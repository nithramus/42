#include "ft_ls.h"

static void print_droit(struct stat info)
{
	ft_printf("%c", S_IRUSR == (info.st_mode & S_IFMT) ? '-' : 'r');
	ft_printf("%c", S_IWUSR == (info.st_mode & S_IFMT) ? '-' : 'w');
	ft_printf("%c", S_IXUSR == (info.st_mode & S_IFMT) ? '-' : 'x');
	ft_printf("%c", S_IRGRP == (info.st_mode & S_IFMT) ? '-' : 'r');
	ft_printf("%c", S_IWGRP == (info.st_mode & S_IFMT) ? '-' : 'w');
	ft_printf("%c", S_IXGRP == (info.st_mode & S_IFMT) ? '-' : 'x');
	ft_printf("%c", S_IROTH == (info.st_mode & S_IFMT) ? '-' : 'r');
	ft_printf("%c", S_IWOTH == (info.st_mode & S_IFMT) ? '-' : 'w');
	ft_printf("%c ", S_IXOTH == (info.st_mode & S_IFMT) ? '-' : 'x');
}

static void	print_type(struct stat info)
{

	if (S_ISDIR(info.st_mode))
		ft_printf("d");
	else if (S_ISREG(info.st_mode))
		ft_printf("-");
	else if (S_ISCHR(info.st_mode))
		ft_printf("c");
	else if (S_ISBLK(info.st_mode))
		ft_printf("b");
	else
		afficher_error_connais_pas();
}

static void print_l(char *path, char *fichier)
{
	char *new_path;
	struct stat info;

	new_path = create_path(path, fichier);
	stat(new_path, &info);
	print_type(info);
	print_droit(info);
	free(new_path);
}



void	print_list_fichier(char *path, s_param *param)
{
	char **list;
	int i;

	i = 0;
	list = tab_of_dir(path, param);
	while (list[i])
	{
		if (list[i][0] == '.')
		{
			if (param->a)
			{
				if (param->l)
					print_l(path, list[i]);
				ft_printf("%s\n", list[i]);
			}
		}
		else
		{
			if (param->l)
				print_l(path, list[i]);
			ft_printf("%s\n", list[i]);
		}
		i++;
	}
}
