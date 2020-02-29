#include "../includes/puzzle.h"

void	print_other(void)
{
	ft_putstr_fd("\t-g -- greedy search\n", STDERR);
	ft_putstr_fd("\t-u -- uniform search\n", STDERR);
	ft_putstr_fd("\t-h -- hamming heuristic\n", STDERR);
	ft_putstr_fd("\t-m -- manhattan heuristic\n", STDERR);
	ft_putstr_fd("\t-l -- linear conflict heuristic\n", STDERR);
	ft_putstr_fd("\t-e -- euclidian heuristic\n", STDERR);
}


int		err(const int err, const char *str)
{
	static const char	*msg[ERR_NUMBER];

	msg[0] = "Fatal Error: ";
	msg[1] = "Bad usage: ";
	msg[2] = "Bad file: ";
	ft_putstr_fd(RED, STDERR);
	ft_putstr_fd(msg[err], STDERR);
	ft_putstr_fd(RES, STDERR);
	ft_putstr_fd(str, STDERR);
	ft_putstr_fd("\n", STDERR);
	if (err == ERR_USAGE)
	{
		ft_putstr_fd("usage: ./ft_nm [-", STDERR);
		ft_putstr_fd(ATRIPUTES, STDERR);
		ft_putstr_fd("] <files> \n", STDERR);
		print_other();
	}
	return (1);
}
