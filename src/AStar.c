#include "../includes/puzzle.h"

void	set_coord(int *coord, int *dir, int size, int *goal)
{
	if (*dir % 2 == 0)
	{
		coord[1] = *dir == 0 ? coord[1] + 1 : coord[1] - 1;
		if (coord[1] == size || coord[1] < 0 || goal[coord[0] + coord[1] * size])
		{
			coord[1] = *dir == 0 ? coord[1] - 1 : coord[1] + 1;
			*dir = (*dir + 1) % 4;
			set_coord(coord, dir, size, goal);
		}
	}
	else
	{
		coord[0] = *dir == 3 ? coord[0] + 1 : coord[0] - 1;
		if (coord[0] == size || coord[0] < 0 || goal[coord[0] + coord[1] * size])
		{
			coord[0] = *dir == 3 ? coord[0] - 1 : coord[0] + 1;
			*dir = (*dir + 1) % 4;
			set_coord(coord, dir, size, goal);
		}
	}
}

int		*goal(int size, int dir, int i, int sqr, int *ret)
{
	int coord[2];

	sqr = size * size;
	ret = ft_memalloc(sqr * sizeof(int) + sizeof(int));
	coord[0] = 0;
	coord[1] = 0;
	while (i <= sqr)
	{
		ret[coord[0] + coord[1] * size] = (i == sqr ? -1 : i);
		if (i != sqr)
			set_coord(coord, &dir, size, ret);
		i++;
	}
	return (ret);
}

void	init_sett(t_set *set, int *line, int s, t_node **cur)
{
	set->goal = goal(s, 3, 1, s * s, NULL);
	printf("goal: ");
	for (int i = 0; i < s * s; i++)
		printf("[%d]", set->goal[i]);
	set->size = s;
	set->open_size = 0;
	set->closed_size = 0;
	*cur = ft_memalloc(sizeof(t_node));
	(*cur)->puzzle = line;
	(*cur)->g_score = 0;
	(*cur)->next = NULL;
	(*cur)->from = NULL;
	set->closed = NULL;
	set->open = NULL;
	set->path = NULL;
	set->hashmap1 = (char*)ft_memalloc(2000000);
	set->hashmap2 = (char*)ft_memalloc(2000000);
}

int *remake_in_line(int **m, uint8_t size)
{
	int *ret = (int*)malloc(sizeof(int) * (size * size));
	int i = 0;
	int j = 0;
	int k = 0;

	while (j < size)
	{
		i = -1;
		while (++i < size)
			ret[k++] = (m[j][i] ? m[j][i] : -1);
		j++;
	}
	return (ret);
}

void AStar(int **m, uint8_t size)
{
	t_set set;
	t_node *cur;


	int *line = remake_in_line(m, size);
	init_sett(&set, line, size, &cur);
	
}