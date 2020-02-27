#include "../includes/puzzle.h"

int	find_dice(int current, int *goal)
{
	int i;

	i = 0;
	while (goal[i])
	{
		if (goal[i] == current)
			return (i);
		i++;
	}
	return (0);
}

int		ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	heuristic_euclidian(int *current, int *goal, int n)
{
	int i;
	int j;
	int h;

	i = 0;
	h = 0;
	while (current[i])
	{
		if (current[i] != -1)
		{
			j = find_dice(current[i], goal);
			h += (int)sqrt(((j % n - i % n) * (j % n - i % n)) +
				((j / n - i / n) * (j / n - i / n)));
		}
		i++;
	}
	return (h);
}

int	ft_in_interval(int nb, int n1, int n2)
{
	if ((nb >= n1 && nb <= n2) || (nb <= n1 && nb >= n2))
		return (1);
	return (0);
}

static int	run_conflict(int *coord, int j, int goal_j, int n)
{
	int coord2[4];

	coord2[0] = j % n;
	coord2[1] = j / n;
	coord2[2] = goal_j % n;
	coord2[3] = goal_j % n;
	if ((coord2[0] == coord[0] && coord2[2] == coord[2])
		|| (coord2[1] == coord[1] && coord2[3] == coord[3]))
	{
		if ((coord2[0] == coord[0]
			&& (ft_in_interval(coord2[1], coord[1], coord[3])
			|| ft_in_interval(coord[1], coord2[1], coord2[3])))
			|| (coord2[1] == coord[1]
			&& (ft_in_interval(coord2[0], coord[0], coord[2])
			|| ft_in_interval(coord[0], coord2[0], coord2[2]))))
			return (1);
	}
	return (0);
}

static void	fill_coord(int coord[4], int i, int j, int n)
{
	coord[0] = i % n;
	coord[1] = i / n;
	coord[2] = j % n;
	coord[3] = j / n;
}

int			linear_conflict_manhattan(int *cur, int *goal, int n)
{
	int i = -1;
	int j;
	int coord[4];
	int h = heuristic_manhatan(cur, goal, n);
	int *cpy = cpy_line(cur, n);

	//cpy = cpy_line(current, n);
	while (cpy[++i])
		if (cpy[i] != -1)
		{
			j = find_dice(cpy[i], goal);
			fill_coord(coord, i, j, n);
			j = i;
			while (cpy[++j])
				if (cpy[j] != -1 && run_conflict(coord, j, find_dice(cpy[j], goal), n))
				{
					h += 2;
					cpy[j] = -1;
				}
		}
	ft_memdel((void **)&cpy);
	return (h);
}

int	heuristic_hamming(int *current, int *goal, int n)
{
	int i;
	int j;
	int h;

	(void)n;
	i = 0;
	h = 0;
	while (current[i])
	{
		if (current[i] != -1)
		{
			j = find_dice(current[i], goal);
			if (j != i)
				h += 1;
		}
		i++;
	}
	return (h);
}

int	heuristic_manhatan(int *current, int *goal, int n)
{
	int i;
	int j;
	int h;

	i = 0;
	h = 0;
	while (current[i])
	{
		if (current[i] != -1)
		{
			j = find_dice(current[i], goal);
			h += ft_abs(j % n - i % n) + ft_abs(j / n - i / n);
		}
		i++;
	}
	return (h);
}
