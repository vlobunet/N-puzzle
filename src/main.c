#include "../includes/puzzle.h"

int file_check(char *fname, int fd, char *line)
{
	if ((fd = open(fname, O_RDONLY)) == -1)
		return (err(ERR_FILE, "No such file or directory"));
	while (get_next_line(fd, &line) > 0)
	{
		printf("line: [%s]\n", line);
		ft_strdel(&line);
	}
	return(0);

}

void run_puzzle(t_attr *attr)
{
	char **f_names;

	f_names = attr->f;
	while (f_names && *f_names)
	{
		if (file_check(*f_names, 0, NULL) == VALID)
			printf("%s : VALID\n", *f_names);
		else err(ERR_FILE, *f_names);
		f_names++;
	}
}

int main(int c, char **v)
{
	t_attr *attr;

	if (c < 2)
		return (err(ERR_USAGE, "invalid number attributes"));
	if (!(attr = check_argv(v + 1, NULL)))
		return (1);
	if (attr && !attr->f)
		return (err(ERR_FILE, "You must also specify the path to the map."));
	run_puzzle(attr);
	return (0);
}