#include "../includes/puzzle.h"

void	init_sett(t_set *set, int *line, int s, t_node **cur)
{
	set->goal = goal(s, 3, 1, s * s, NULL);
	set->size = s;
	set->open_size = 0;
	set->closed_size = 0;
	*cur = ft_memalloc(sizeof(t_node));
	set->closed = NULL;
	set->open = NULL;
	set->path = NULL;
	set->hashmap1 = (char*)ft_memalloc(2000000);
	set->hashmap2 = (char*)ft_memalloc(2000000);

	(*cur)->puzzle = line;
	(*cur)->g_score = 0;
	(*cur)->next = NULL;
	(*cur)->from = NULL;
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

int		get_zero(int *line) // получаем позицию нашей пустой клетки
{
	int i;

	i = 0;
	while (line[i] > 0)
		i++;
	return (i);
}

int		*cpy_line(int *line, int size)
{
	int i;
	int *new;

	new = ft_memalloc(sizeof(int) * size * size + sizeof(int));
	i = 0;
	while (line[i])
	{
		new[i] = line[i];
		i++;
	}
	return (new);
}

int	(*g_heuristic[4])(int *curr, int *goal, int n) = {
	heuristic_manhatan,
	heuristic_hamming,
	linear_conflict_manhattan,
	heuristic_euclidian
};

t_node	*node_create(t_node *cur, int *line, t_set *set)
{
	t_node *n;

	n = ft_memalloc(sizeof(t_node));
	n->g_score = set->algo == 1 ? 0 : cur->g_score + 1;
	n->h_score = set->algo == 2 ? 0 : (*g_heuristic[set->heuristic])(line, set->goal, set->size);
	n->from = cur;
	n->puzzle = cpy_line(line, set->size);
	n->next = NULL;
	set->open_size += 1;
	return (n);
}

int		is_solution(int *line, t_node *current, t_set *set)
{
	if (!ft_memcmp(set->goal, line, set->size * set->size * sizeof(int) + sizeof(int)))
	{
		set->path = node_create(current, line, set);
		set->path->next = set->closed;
		set->closed_size += 1;
		set->open_size -= 1;
		set->closed = set->path;
		return (1);
	}
	return (0);
}

void	push(t_node *n, t_set *set)
{
	t_node *cur;
	t_node *last = NULL;

	cur = set->open;
	set->open = !cur ? n : set->open;
	if (cur)
	{
		while (cur)
		{
			if (cur->g_score + cur->h_score >= n->h_score + n->g_score)
			{
				if (last)
					last->next = n;
				else
					set->open = n;
				n->next = cur;
				break ;
			}
			last = cur;
			cur = cur->next;
		}
		if (!cur)
			last->next = n;
	}
}
void	add_to_list(int *line, t_node *cur, t_set *set)
{
	t_node *nw;

	if (!is_solution(line, cur, set) && !set->path)
	{
		if (!in_closed(line, set))
		{
			nw = node_create(cur, line, set);
			push(nw, set);
		}
	}
}


void	swap(int n, t_node *cur, t_set *set)
{
	int		line[set->size * set->size + 1];
	int		i = 0;

	line[set->size * set->size] = 0;
	while (/*cur->puzzle[i]*/ i < set->size * set->size)
	{
		if (cur->puzzle[i] == n)
			line[i] = -1;
		else if (cur->puzzle[i] == -1)
			line[i] = n;
		else
			line[i] = cur->puzzle[i];
		i++;
	}
	add_to_list(line, cur, set);
}

void	fill_open(t_set *set, t_node *cur)
{
	int zero;
	//int coord[2];
	int row;
	int col;

	zero = get_zero(cur->puzzle);
	row = zero % set->size;
	col = zero / set->size;
	(row + 1 < set->size) ? swap(cur->puzzle[row + 1 + col * set->size], cur, set) : 0;
	(row - 1 >= 0) ? swap(cur->puzzle[row - 1 + col * set->size], cur, set) : 0;
	(col + 1 < set->size) ? swap(cur->puzzle[row + (col + 1) * set->size], cur, set) : 0;
	(col - 1 >= 0) ? swap(cur->puzzle[row + (col - 1) * set->size], cur, set) : 0;
}

void			push_hash(int *puzzle, t_set *set)
{
	int key1;
	int key2;

	key1 = get_hash_1(puzzle, set->size);
	key2 = get_hash_2(puzzle, set->size);
	set->hashmap1[key1 / 8] |= 1 << key1 % 8;
	set->hashmap2[key2 / 8] |= 1 << key2 % 8;
}

void	print_puzzle(int *puzzle, int size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			printf("%- 4i", puzzle[x + y * size] == -1
			? 0 : puzzle[x + y * size]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void AStar(int **m, uint8_t size)
{
	t_set set;
	t_node *cur;

	int *line = remake_in_line(m, size);
	init_sett(&set, line, size, &cur);
	set.heuristic = 3; //тут пихаем флаг евристики
	set.algo = 1; //тут пихаем флаг алгоритма
	while (!set.path)
	{
		fill_open(&set, cur);
		push_hash(cur->puzzle, &set);
		cur->next = set.closed;
		set.closed = cur;
		cur = set.open;
		set.open = cur->next;
		set.closed_size += 1;
		set.open_size -= 1;
	}
	printf("complexity: %i, size complexity: + %i = %i\n", set.closed_size, set.open_size, set.open_size + set.closed_size);
	print_puzzle(set.path->puzzle, set.size);
}