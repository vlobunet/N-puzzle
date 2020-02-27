#include "../includes/puzzle.h"

void visualisation(t_mapp *map)
{
	t_visual *p;

	p = (t_visual *)malloc(sizeof(t_visual));
	p->mlx = mlx_init_window(WIDTH, HEIGHT, "N-puzzle");
	p->speed = 20;
}