#include "ft_ls.h"

static char		*create_path(char *path, char *dir)
{
	char *new;

	if (!(new = ft_strjoin(path, "/")))
		afficher_error_malloc();
	if (!(new = ft_strjoin(new, dir)))
		afficher_error_malloc();
	return (new);
}

void	go_to_dir(char *path, s_param *param)
{
	DIR *dir;
	struct dirent *list_elem;
	struct stat info;
	char	*new_path;


	print_list_fichier(path, param);
	dir = opendir(path);
	while ((list_elem = readdir(dir)) != NULL)
	{
		new_path = create_path(path, list_elem->d_name);
		if (stat(new_path, &info) == -1)
			afficher_error_malloc();
		else if (S_ISDIR(info.st_mode) && list_elem->d_name[0] != '.')
		{
			ft_printf("%c\n", list_elem->d_name[0]);
			ft_printf("\n%s:\n\n", new_path);
			if (param->rmaj)
				go_to_dir(new_path, param);
		}
	}
}
