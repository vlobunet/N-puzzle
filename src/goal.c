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

int		*goal(int size, int dir, int i, int squr, int *ret)
{
	int coord[2];

	squr = size * size;
	ret = ft_memalloc(squr * sizeof(int) + sizeof(int));
	coord[0] = 0;
	coord[1] = 0;
	while (i <= squr)
	{
		ret[coord[0] + coord[1] * size] = (i == squr ? -1 : i);
		if (i != squr)
			set_coord(coord, &dir, size, ret);
		i++;
	}
	return (ret);
}
