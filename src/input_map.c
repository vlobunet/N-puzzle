#include "../includes/puzzle.h"


t_mapp *input_map(t_mapp *map)
{
	uint8_t i = 0;
	char *line = NULL;

	if (get_next_line(0, &line) <= 0 || !control_attr(line, "0987654321 ", 0, 0))
		return (NULL);
	map = get_struct();
	map->size = ft_atoi(line);
	ft_strdel(&line);
	map->array = (int **)malloc(sizeof(int *) * map->size);
	for (uint8_t j = 0; j < map->size; j++)
		map->array[j] = (int *)malloc(sizeof(int) * map->size);
	if (map->size > 8 || map->size < 3)
		return (NULL);
	while (i < map->size)
	{
		if (get_next_line(0, &line) <= 0)
			return (NULL);
		if (!control_attr(line, "0987654321 ", 0, 0) ||
			control_line(line, &map, NULL, i))
			return (NULL);
		ft_strdel(&line);
		i++;
	}
	if (!ft_solvable(map->array, map->size))
		return (NULL);
	return (map);
} 