#include "../includes/puzzle.h"

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

int		check_lines(char **argv, uint8_t is_nm)
{
	while (argv && *argv && *argv[0] == '-')
	{
		if (!check_word(*argv) || !control_attr(*argv,
			(is_nm ? "p" : "t"), 1, 0))
		{
			is_nm ? err(ERR_USAGE, *argv) : err_otool(ERR_USAGE, *argv);
			return (0);
		}
		argv++;
	}
	return (1);
}

int check_file(int c, char **v)
{
	if (c < 2)
		return (err(ERR_USAGE, "invalid number attributes"));
	if (v[1] && v[1][0] == '-' && check_attributes())
		return (err(ERR_))
}