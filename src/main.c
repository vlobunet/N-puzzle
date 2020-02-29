#include "../includes/puzzle.h"

int main(int c, char **v)
{
	t_attr	*attr = NULL;;
	t_mapp	*map = NULL;
	char	**f_names = NULL;

	if (c >= 2)
		attr = check_argv(v + 1, NULL);
	else
		attr = init_array_attributes();
	if (attr && attr->f)
	{
		f_names = attr->f;
		while (f_names && *f_names)
		{
			if (file_check(*f_names, 0, NULL, NULL, attr) == INVALID)
				err(ERR_FILE, *f_names);
			f_names++;
		}
	}
	else
		map = input_map(NULL);
	if (attr && map && ft_solvable(map->array, map->size))
		AStar(map->array, map->size, attr);
	else
		return (err(ERR_SYS, "Error input or map not Solvable"));
	return (0);
}