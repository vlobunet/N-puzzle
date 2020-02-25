#include "../includes/puzzle.h"

t_mapp *get_struct(void)
{
	t_mapp *ret;
	uint8_t i = 0;

	if (!(ret = (t_mapp *)malloc(sizeof(t_mapp))))
		return (NULL);
	ret->size = 0;
	ret->array = 0;
	while (i < 100)
	{
		ret->t[i] = 0;
		i++;
	}
	return (ret);
}

int control_line(char *line, t_mapp **map, char **s, uint8_t c)
{
	uint8_t i = 0;
	int 	num;

	s = ft_strsplit(line, 32);
	if (!(*map)->size)
	{
		if (s && s[0] && !s[1] && ft_atoi(s[0]) > 2)
		{
			(*map)->size = ft_atoi(s[0]);
			(*map)->array = (int **)malloc(sizeof(int *) * (*map)->size);
			for (i = 0; i < (*map)->size; i++)
				(*map)->array[i] = (int *)malloc(sizeof(int) * (*map)->size);
			return (0);
		}
		else
			return (1);
	}
	i = 0;
	while (i < (*map)->size && s[i])
	{
		num = ft_atoi(s[i]);
		if ((num <= (*map)->size * (*map)->size - 1) && !(*map)->t[num])
		{
			(*map)->t[num] = (!num ? 1 : num);
			(*map)->array[c][i] = num;
		}
		else
			return (1);
		i++;
	}
	if (i < (*map)->size || s[i])
		return (1);
	return (0);
}

int file_check(char *fname, int fd, char *line, t_mapp *map)
{
	uint8_t row = -2;

	if ((fd = open(fname, O_RDONLY)) == -1)
		return (err(ERR_FILE, "No such file or directory"));
	if (!(map = get_struct()))
		return (err(ERR_SYS, "malloc is bed"));
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '#')
			continue ;
		if (!control_attr(line, "0987654321 ", 0, 0) ||
			control_line(line, &map, NULL, ++row))
		{
			ft_strdel(&line);
			close(fd);
			return (1);
		}
		ft_strdel(&line);
	}
	if (!ft_solvable(map->array, map->size))
		return (err(ERR_FILE, "Not Solvable"));
	return(0);
}