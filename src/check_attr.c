#include "../includes/puzzle.h"

int		search_letter(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}


t_attr	*init_array_attributes(void)
{
	t_attr	*attr;

	if (!(attr = (t_attr *)malloc(sizeof(t_attr))))
		return (NULL);
	attr->p = 0;
	attr->f = NULL;
	return (attr);
}

int		control_attr(char *str, char *valid_letter, int i, int j)
{
	int ret;

	if (!str || !*str)
		return (0);
	while (str[i])
	{
		j = 0;
		ret = 0;
		while (valid_letter[j])
		{
			if (str[i] == valid_letter[j])
				ret++;
			j++;
		}
		if (!ret)
			return (0);
		i++;
	}
	return (1);
}

int		check_word(char *word)
{
	int i;

	i = 1;
	if (!word || !*word)
		return (0);
	while (word[i])
		if (ft_isalpha(word[i]))
			i++;
		else
			return (0);
	return (1);
}

int		check_lines(char **argv)
{
	while (argv && *argv && *argv[0] == '-')
	{
		if (!check_word(*argv) || !control_attr(*argv, ATRIPUTES, 1, 0))
			return (err(ERR_USAGE, *argv));
		argv++;
	}
	return (0);
}

t_attr	*check_argv(char **argv, t_attr *atr)
{
	if (argv && *argv && *argv[0] == '-' && check_lines(argv))
		return (NULL);
	atr = init_array_attributes();
	while (argv && *argv && *argv[0] == '-')
	{
		search_letter(*argv, 'p') ? atr->p = 1 : 0;
		argv = argv + 1;
	}
	atr->f = (argv && *argv ? argv : NULL);
	return (atr);
}

