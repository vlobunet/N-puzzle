#include "../includes/puzzle.h"

int main(int c, char **v)
{
	t_attr	*attr = NULL;;
	t_mapp	*map = NULL;
	char	**f_names;

	if (c < 2)
	{
		if (!(map = input_map(NULL)))
			return(err(ERR_SYS, "erroneous input or puzzle is insoluble."));
	}
	else if (!(attr = check_argv(v + 1, NULL)))
		return (1);
	if (attr && !attr->f)
		return (err(ERR_FILE, "You must also specify the path to the map."));
	else
	{
		f_names = attr->f;
		while (f_names && *f_names)
		{
			if (file_check(*f_names, 0, NULL, NULL) == INVALID)
				err(ERR_FILE, *f_names);
			f_names++;
		}
	}
	return (0);
}