#include "ft_ls.h"

static void tri_tab_t(char **tab)
{
	int is_trie;
	int i;
	struct stat info;
	struct stat info2;
	char *tmp;

	is_trie = 1;
	while (is_trie)
	{
		is_trie = 0;
		i = 0;
		while (tab[i])
		{
			if (tab[i + 1])
			{
				stat(tab[i], &info);
				stat(tab[i + 1], &info2);
				if (info.st_mtime < info2.st_mtime)
				{
					tmp = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = tmp;
					is_trie = 1;
				}
			}
			i++;
		}
	}
}

static void tri_tab_alpha(char **tab)
{
	int i;
	int is_trie;
	char *tmp;

	is_trie = 1;
	while (is_trie)
	{
		is_trie = 0;
		i = 0;
		while (tab[i])
		{
			if (tab[i + 1])
			{
				if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				{
					tmp = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = tmp;
					is_trie = 1;
				}
			}
			i++;
		}
	}
}

static void tri_tab_reverse(char **tab)
{
	int i;
	int j;
	char *tmp;

	j = 0;
	i = 0;
	while (tab[i])
		i++;
	i--;
	while (j < i)
	{
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;
		i--;
		j++;
	}
}

char	**tab_of_dir(char *path, s_param *param)
{
	char **tab_of_dir;
	DIR *dir;
	struct dirent *list_elem;
	char *new;

	if (!(tab_of_dir = (char**)malloc(sizeof(char*))))
		afficher_error_malloc();
	*tab_of_dir = NULL;
	if (!(dir = opendir(path)))
		afficher_error_connais_pas();
	while (list_elem= readdir(dir))
	{
		if (!(new = ft_strnew(ft_strlen(list_elem->d_name) + 1)))
			afficher_error_malloc();
		ft_strcpy(new, list_elem->d_name);
		if (!(tab_of_dir = (char**)ft_ptradd_free((void**)tab_of_dir, new)))
			afficher_error_malloc();
	}
	if (param->t)
		tri_tab_t(tab_of_dir);
	else
		tri_tab_alpha(tab_of_dir);
	if (param->r)
		tri_tab_reverse(tab_of_dir);
	return (tab_of_dir);
}
