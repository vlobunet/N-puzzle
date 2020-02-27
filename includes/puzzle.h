#ifndef PUZZLE_H
# define PUZZLE_H

#include <unistd.h>
#include <fcntl.h>
#include "../libftASM/includes/libfts.h"


#include <stdio.h>

# define BLACK      "\033[1;30m"
# define RED        "\033[1;31m"
# define GREEN      "\033[01;38;05;46m"
# define YELLOW     "\033[01;38;05;226m"
# define BLUE       "\033[03;38;05;21m"
# define VIOLET     "\033[01;38;05;201m"
# define CYAN       "\033[1;36m"
# define WHITE      "\033[01;38;05;15m"
# define RES		"\033[m"

# define ERR_SYS	0
# define ERR_USAGE	1
# define ERR_FILE	2
# define ERR_NUMBER 3

# define STDERR		2
# define STDOUT		1
# define STDIN		0

# define ATRIPUTES	"hmleug"
# define INVALID	1
# define VALID		0

# define BUFF_SIZE 1024

typedef struct		s_gnl
{
	int				fd;
	int				state;
	char			*rest;
	struct s_gnl	*next;
}					t_gnl;

typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

typedef struct		s_attr
{
	uint8_t			p;
	char			**f;
}					t_attr;

typedef struct		s_mapp
{
	uint8_t			size;
	int				**array;
	uint8_t			t[100];
}					t_mapp;

typedef struct		s_node
{
	int				g_score;
	int				h_score;
	int				*puzzle;
	struct s_node	*next;
	struct s_node	*from;
}					t_node;

typedef struct		s_set
{
	t_node			*open;
	t_node			*closed;
	t_node			*path;
	int				*goal;
	int				open_size;
	int				closed_size;
	int				size;
	int				heuristic;
	int				algo;
	char			*hashmap1;
	char			*hashmap2;
}					t_set;

// typedef struct s_visual
// {
// 	t_mlx			*mlx;
// } t_visual;
int		err(const int err, const char *str);
int		check_file(int c, char **v);
t_attr	*check_argv(char **argv, t_attr *atr);
int		get_next_line(int const fd, char **line);
int		control_attr(char *str, char *valid_letter, int i, int j);
int		file_check(char *fname, int fd, char *line, t_mapp *map);
int		ft_solvable(int **matrix, uint8_t size);
t_mapp	*input_map(t_mapp *map);
t_mapp *get_struct(void);
int		control_attr(char *str, char *valid_letter, int i, int j);
int control_line(char *line, t_mapp **map, char **s, uint8_t c);
uint8_t		*get_line(int **matrix, int size, uint16_t power);

void AStar(int **m, uint8_t size);

#endif
