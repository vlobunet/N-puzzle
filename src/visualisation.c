// #include "../includes/puzzle.h"
// #include "../includes/macro.h"

// static int		init_modes(t_param *param, t_puzzle puzzle)
// {
// 	int		i;
// 	t_state *state;

// 	if (puzzle.heuristic == h)
// 		param->heuri = "Hamming";
// 	else if (puzzle.heuristic == e)
// 		param->heuri = "Euclidian";
// 	else
// 		param->heuri = "Manhattan Distance";

// 	if (puzzle.search == astar)
// 		param->search = "A*";
// 	else if (puzzle.search == greedy)
// 		param->search = "Greedy";
// 	else
// 		param->search = "Uniform";
// 	param->complex_size = puzzle.nb_state_create;
// 	i = 0;
// 	state = puzzle.closed;
// 	while (state->next)
// 	{
// 		i++;
// 		state = state->next;
// 	}
// 	param->complex_time = i;
// 	return (1);
// }

// static int		init_param(t_param **param, t_puzzle puzzle)
// {
// 	if (!((*param) = (t_param *)ft_memalloc(sizeof(t_param))))
// 		return (0);
// 	if (!((*param)->mlx = mlx_init_window(W, H, "N-puzzle")))
// 	{
// 		free(*param);
// 		return (0);
// 	}
// 	init_modes(*param, puzzle);
// 	(*param)->speed = 40;
// 	return (1);
// }

// char	*get_moves(t_state *state)
// {
// 	int		i;
// 	char	*moves;
// 	t_state	*pre_move;

// 	if (!(moves = (char *)calloc(sizeof(char), (state->g))))
// 		return (NULL);
// 	pre_move = state;
// 	i = state->g;
// 	moves[i] = '\0';
// 	while (--i >= 0)
// 	{
// 		moves[i] = pre_move->move;
// 		pre_move = pre_move->pre_move;
// 	}
// 	return (moves);
// }

// t_img	*img_create(t_mlx *mlx, int dim[2])
// {
// 	t_img	*image;

// 	if (!(image = (t_img *)malloc(sizeof(t_img))))
// 		return (NULL);
// 	image->dim[0] = dim[0];
// 	image->dim[1] = dim[1];
// 	image->ptr = mlx_new_image(mlx->ptr, image->dim[0], image->dim[1]);
// 	image->data = (int *)mlx_get_data_addr(image->ptr, &image->opp, &image->sizeline, &image->endian);
// 	image->opp /= 8;
// 	image->size = image->dim[0] * image->dim[1];
// 	if (!image->ptr || !image->data)
// 	{
// 		free(image);
// 		return (NULL);
// 	}
// 	return (image);
// }

// static t_img	*new_map(t_mlx *mlx, int width, int height, t_state *state)
// {
// 	t_img	*img;
// 	int		len[2];
// 	int		val;

// 	len[0] = width;
// 	len[1] = height;
// 	if (!(img = img_create(mlx, len)))
// 		return (NULL);
// 	val = 2 * BOARD_START; // (200 * 2)
// 	img->piece_size = (img->dim[0] - val < img->dim[1] - val) ? img->dim[0] - val : img->dim[1] - val;
// 	img->piece_size = img->piece_size / state->board_size - BOARD_SPACE;
// 	return (img);
// }

// static int	ft_rapport(int first, int second, double p)
// {
// 	if (first == second)
// 		return (first);
// 	return ((int)((double)first + (second - first) * p));
// }

// int			color_mix(int c1, int c2, double p)
// {
// 	int r;
// 	int g;
// 	int b;

// 	if (c1 == c2)
// 		return (c1);
// 	r = ft_rapport((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
// 	g = ft_rapport((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
// 	b = ft_rapport(c1 & 0xFF, c2 & 0xFF, p);
// 	return (r << 16 | g << 8 | b);
// }

// int		coord_to_pos(int x, int y, int width)
// {
// 	return ((int)(x + y * width));
// }

// static void	display_piece(t_img *img, int start[2], int color)
// {
// 	int	index[2];

// 	index[1] = -1;
// 	while (++index[1] < img->piece_size)
// 	{
// 		index[0] = -1;
// 		while (++index[0] < img->piece_size)
// 		{
// 			img->data[coord_to_pos(start[0] + index[0], start[1] + index[1], WIN_WIDTH)] = color;
// 		}
// 	}
// }

// void		display_board(t_state *state, t_img *img)
// {
// 	int		i;
// 	int		start[2];
// 	int		color;

// 	i = -1;
// 	start[0] = BOARD_START;
// 	start[1] = -img->piece_size + BOARD_START;
// 	while (++i < state->board_count)
// 	{
// 		start[0] += img->piece_size + BOARD_SPACE;
// 		if (i % state->board_size == 0)
// 		{
// 			start[0] = BOARD_START;
// 			start[1] += BOARD_SPACE + img->piece_size;
// 		}
// 		if (state->board[i] != 0)
// 		{
// 			color = color_mix(C_RED, C_BLUE, (double)state->board[i] / (double)state->board_count);
// 			display_piece(img, start, color);
// 		}
// 	}
// }

// void		display_numb(t_mlx *mlx, t_state *state, int size)
// {
// 	int		i;
// 	int		start[2];
// 	char	*line;

// 	i = -1;
// 	start[0] = BOARD_START;
// 	start[1] = -size + BOARD_START;
// 	while (++i < state->board_count)
// 	{
// 		start[0] += size + BOARD_SPACE;
// 		if (i % state->board_size == 0)
// 		{
// 			start[0] = BOARD_START;
// 			start[1] += BOARD_SPACE + size;
// 		}
// 		line = ft_itoa(state->board[i]);
// 		mlx_string_put(mlx->ptr, mlx->win, start[0] + 50,
// 			start[1] + 50, C_BLACK, line);
// 		free(line);
// 	}
// }

// void	free_image(t_param *param, t_img *img)
// {
// 	if (img)
// 	{
// 		mlx_destroy_image(param->mlx->ptr, img->ptr);
// 		free(img);
// 	}
// }

// void			visu_print(t_param *p, t_state *state)
// {
// 	t_img	*img;
// 	char	move;

// 	move = '-';
// 	if ((img = new_map(p->mlx, WIN_WIDTH, WIN_HEIGHT, state)))
// 	{
// 		display_board(p->state, img);
// 		mlx_put_image_to_window(p->mlx->ptr, p->mlx->win, img->ptr, 0, 0);
// 		if (p->current_step < p->state->g)
// 			move = p->moves[p->current_step];
// 		display_numb(p->mlx, p->state, img->piece_size);
// 		free_image(p, img);
// 	}
// }

// void	up(t_state *state)
// {
// 	int	pos;
// 	int	size;

// 	pos = state->zero;
// 	size = state->board_size;
// 	if (pos < state->board_count - size)
// 	{
// 		state->board[pos] = state->board[pos + size];
// 		state->board[pos + size] = 0;
// 		state->zero = pos + size;
// 	}
// }

// void	down(t_state *state)
// {
// 	int	pos;
// 	int	size;

// 	pos = state->zero;
// 	size = state->board_size;
// 	if (pos >= size)
// 	{
// 		state->board[pos] = state->board[pos - size];
// 		state->board[pos - size] = 0;
// 		state->zero = pos - size;
// 	}
// }

// void	right(t_state *state)
// {
// 	int		pos;
// 	int		size;

// 	pos = state->zero;
// 	size = state->board_size;
// 	if ((pos) % size != 0)
// 	{
// 		state->board[pos] = state->board[pos - 1];
// 		state->board[pos - 1] = 0;
// 		state->zero = pos - 1;
// 	}
// }

// void	left(t_state *state)
// {
// 	int		pos;
// 	int		size;

// 	pos = state->zero;
// 	size = state->board_size;
// 	if ((pos + 1) % size != 0)
// 	{
// 		state->board[pos] = state->board[pos + 1];
// 		state->board[pos + 1] = 0;
// 		state->zero = pos + 1;
// 	}
// }

// int		move_add(t_state *pre_move, t_state *state, char move)
// {
// 	state->g += 1;
// 	state->pre_move = pre_move;
// 	state->move = move;
// 	return (1);
// }

// static void	operate_move(t_state *state, char move)
// {
// 	if (move == UP)
// 		up(state);
// 	else if (move == DOWN)
// 		down(state);
// 	else if (move == RIGHT)
// 		right(state);
// 	else if (move == LEFT)
// 		left(state);
// }

// int			event_loop(t_param *p)
// {
// 	int turn;

// 	if (p->run && p->current_step <= p->state->g)
// 	{
// 		turn = (p->speed > 100) ? (p->speed - 100) / 10 : 1;
// 		if (p->current_step + turn > p->state->g)
// 			turn = p->state->g - p->current_step;
// 		while (turn-- > 0 && p->current_step <= p->state->g)
// 			operate_move(p->state, p->moves[p->current_step++]);
// 		visu_print(p, p->state);
// 		usleep(50000000 / (p->speed * p->speed));
// 	}
// 	else
// 		usleep(150000);
// 	return (1);
// }

// int			event_keyboard(int key, t_param *p)
// {
// 	if (key == SP_KEY && !p->end)
// 		p->run = !p->run;
// 	if (key == ESC_KEY)
// 		exit(0);
// 	else
// 	{
// 		if (key == NKMN_KEY && p->speed > SPEED_MIN)
// 			p->speed -= 10;
// 		if (key == NKPL_KEY && p->speed < SPEED_MAX)
// 			p->speed += 10;
// 		if (key == N_KEY)
// 			p->display_num = !p->display_num;
// 	}
// 	return (1);
// }

// int				visu_init(t_param *p, t_state *state, t_puzzle *puzzle)
// {
// 	if (init_param(&p, *puzzle) == 0)
// 		return (0);
// 	p->state = state;
// 	if (!(p->moves = get_moves(state)))
// 	{
// 		error_print("Error print_step moves");
// 		return (0);
// 	}
// 	p->current_step = 0;
// 	p->puzzle = puzzle;
// 	visu_print(p, state);
// 	mlx_ho1(p->mlx->win, KEYPRESS, KPMASK, event_keyboard, p);
// 	mlx_loop_ho1(p->mlx->ptr, event_loop, p);
// 	mlx_loop(p->mlx->ptr);
// 	//del_param(p);
// 	return (1);
// }