#ifndef PUZZLE_H
# define PUZZLE_H

#include <unistd.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

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

# define STDERR		2
# define STDOUT		1
# define STDIN		0

typedef struct				s_attr
{
	uint8_t					p;
	char					**f;
}							t_attr;

int		err(const int err, const char *str);

#endif
