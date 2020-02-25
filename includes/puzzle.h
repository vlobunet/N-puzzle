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

# define ATRIPUTES	"a"
# define INVALID	1
# define VALID		0

# define BUFF_SIZE 1024

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

int		err(const int err, const char *str);
int		check_file(int c, char **v);
t_attr	*check_argv(char **argv, t_attr *atr);
int		get_next_line(const int fd, char **line);
int		control_attr(char *str, char *valid_letter, int i, int j);
int		file_check(char *fname, int fd, char *line, t_mapp *map);
int		ft_solvable(int **matrix, uint8_t size);

#endif
