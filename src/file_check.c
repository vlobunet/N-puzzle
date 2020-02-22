#include "../includes/puzzle.h"

int check_file(int c, char **v)
{
	t_attr *attr;

	if (c < 2)
		return (err(ERR_USAGE, "invalid number attributes"));
	attr = check_argv(v + 1, NULL);
		return (1);
}