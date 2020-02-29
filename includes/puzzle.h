#ifndef PUZZLE_H
# define PUZZLE_H

#include <unistd.h>
#include <fcntl.h>
#include <math.h>
# include <mlx.h>
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
# define W			500
# define H			500

# define ESC		53

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
	uint8_t			h;
	uint8_t			m;
	uint8_t			l;
	uint8_t			u;
	uint8_t			g;
	uint8_t			e;
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

typedef struct		s_visual
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
}					t_visual;
//////////////////////////////////////////////////////////////////////////////

typedef struct	s_img
{
	int		index;
	int		win_pos[2];
	int		dim[2];
	int		sizeline;
	int		size;
	int		endian;
	int		opp;
	int		start;
	int		org[2];
	int		piece_size;
	void	*ptr;
	int		*data;
}				t_img;

typedef struct	s_mlx
{

	int		dim[2];
	int		color;
	void	*ptr;
	void	*win;
}				t_mlx;

typedef struct	s_param
{
	int				press;
	int				ready;
	int				m_color;
	int				i_color;
	int				b_mode;
	int				run;
	int				end;
	int				colors[3];
	int				speed;
	int				display_num;
	int				current_step;
	int				complex_time;
	int				complex_size;
	char			*moves;
	char			*heuri;
	char			*search;
	t_mlx			*mlx;
	t_img			*img;
	// t_puzzle		*puzzle;
	// t_state			*state;
}				t_param;

typedef struct	s_tdata
{
	t_param	*p;
	t_img	*img;
}				t_tdata;

//////////////////////////////////////////////////////////////////////////////

int		err(const int err, const char *str);
int		check_file(int c, char **v);
t_attr	*check_argv(char **argv, t_attr *atr);
int		get_next_line(int const fd, char **line);
int		control_attr(char *str, char *valid_letter, int i, int j);
int		file_check(char *fname, int fd, char *line, t_mapp *map, t_attr *atr);
int		ft_solvable(int **matrix, uint8_t size);
t_mapp	*input_map(t_mapp *map);
t_mapp *get_struct(void);
int		control_attr(char *str, char *valid_letter, int i, int j);
int control_line(char *line, t_mapp **map, char **s, uint8_t c);
uint8_t		*get_line(int **matrix, int size, uint16_t power);

void AStar(int **m, uint8_t size, t_attr *attr);
int		*goal(int size, int dir, int i, int squr, int *ret);
int		in_closed(int *line, t_set *set);

int	heuristic_manhatan(int *current, int *goal, int n);
int	heuristic_hamming(int *current, int *goal, int n);
int	linear_conflict_manhattan(int *current, int *goal, int n);
int	heuristic_euclidian(int *current, int *goal, int n);
int	*cpy_line(int *puzzle, int size);

unsigned int	get_hash_2(int *line, int size);
unsigned int	get_hash_1(int *line, int size);
t_attr	*init_array_attributes(void);
void display_puzzle(void);

#endif
