#include "../includes/puzzle.h"

int		check_numbers(int **matrix, int size)
{
	int *comp, y;
	int x = 0;
	int power = size * size;

	comp = (int *)malloc(power * sizeof(int));
	while (x < power)
	{
		comp[x] = -1;
		x++;
	}
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (matrix[x][y] >= power)
				return (0);
			if (comp[matrix[x][y]] != -1)
				return (0);
			comp[matrix[x][y]] = 0;
			y++;
		}
		x++;
	}
	free(comp);
	return (1);
}

uint8_t		*get_line(int **matrix, int size, uint16_t power)
{
	uint16_t i = 0;
	uint16_t x = 0;
	uint16_t y = 0;
	uint16_t u = 0; 
	uint8_t j = size - 1;
	uint8_t *line = (uint8_t *)malloc(power * sizeof(uint8_t));
	while (i < power)
	{
		while (j && i < power)
		{
			line[i] = matrix[x][y];
			if (!(u % 4)) y++;
			if (u % 4 == 1) x++;
			if (u % 4 == 2) y--;
			if (u % 4 == 3) x--;
			i++;
			j--;
		}
		u++;
		j = size - u + u / 2;
	}
	return(line);
}

uint8_t		number_swap(uint8_t *line, uint16_t power, uint16_t n)
{
	int		i;
	uint8_t	u;

	i = 0;
	u = line[n];
	if (u == 0)
		return (0);
	while (n < power)
	{
		if (u > line[n] && line[n] != 0)
			i++;
		n++;
	}
	return (i);
}

int		ft_solvable(int **matrix, uint8_t size)
{
	uint8_t		i = 0;
	uint16_t	n = 0;
	uint8_t		poszero;
	uint16_t	power = size * size;
	uint8_t		*line = get_line(matrix, size, power);

	while (n < power)
	{
		i += number_swap(line, power, n);
		n++;
	}
	n--;
	while (line[n] != 0)
		n--;
	poszero = power - n;
	if ((size % 2 == 0 && ((i % 2 == 1 && poszero % 2 == 0) ||
		(i % 2 == 0 && poszero % 2 == 1))) ||
		(size % 2 == 1 && i % 2 == 0))
		return (1);
	else
		return (0);
}
