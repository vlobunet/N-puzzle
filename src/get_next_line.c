#include "../includes/puzzle.h"

// int	ft_buffer(char **buf, char **line)
// {
// 	int		len;
// 	char	*to_free;

// 	if (ft_strchr(*buf, '\n') != NULL)
// 	{
// 		len = ft_strchr(*buf, '\n') - *buf;
// 		to_free = *line;
// 		*line = ft_strsub(*buf, 0, len);
// 		free(to_free);
// 		to_free = *buf;
// 		*buf = ft_strdup(ft_strchr(*buf, '\n') + 1);
// 		free(to_free);
// 		return (1);
// 	}
// 	*line = ft_strdup(*buf);
// 	ft_strdel(buf);
// 	return (0);
// }

// int	read_k(char **line, const int fd, char **buf, char *str)
// {
// 	char	*tmp;
// 	int		len;
// 	int		k;

// 	while ((k = read(fd, str, BUFF_SIZE)) > 0)
// 	{
// 		str[k] = '\0';
// 		printf("k:[%d][%s]\n", k, str);
// 		tmp = *line;
// 		*line =
// 		(tmp ?
// 			ft_strjoin(tmp, str) :
// 			ft_strdup(str));
// 		(tmp) ? ft_strdel(&tmp) : 0;
// 		if (ft_strchr(*line, '\n'))
// 		{
// 			len = ft_strchr(*line, '\n') - *line;
// 			*buf = ft_strdup(ft_strchr(*line, '\n') + 1);
// 			tmp = *line;
// 			*line = ft_strsub(tmp, 0, len);
// 			ft_strdel(&tmp);
// 			break ;
// 		}
// 		ft_bzero(str, BUFF_SIZE);
// 	}
// 	return (k);
// }

// int	get_next_line(const int fd, char **line)
// {
// 	int			k;
// 	static char	*buf[256];
// 	char		*str;

// 	if (fd < 0 || !line || BUFF_SIZE < 0 || (read(fd, NULL, 0) < 0))
// 		return (-1);
// 	if (!(str = ft_strnew(BUFF_SIZE)))
// 		return (-1);
// 	*line = NULL;
// 	if (buf[fd] != NULL)
// 		if (ft_buffer(&buf[fd], line))
// 		{
// 			ft_strdel(&str);
// 			return (1);
// 		}
// 	if ((k = read_k(line, fd, &buf[fd], str)) == -1)
// 		return (-1);
// 	ft_strdel(&str);
// 	if (k == 0 && ft_strlen(*line) == 0)
// 		return (0);
// 	return (1);
// }

static char		**alloc_str(t_gnl *elem, char **str, char *buf)
{
	int		i;
	int		n;
	char	*buffer;

	n = 0;
	i = 0;
	buffer = NULL;
	if (str[0])
	{
		i = ft_strlen(str[0]);
		buffer = malloc((ft_strlen(str[0]) + 1) * sizeof(char));
		ft_strcpy(buffer, str[0]);
		free(str[0]);
	}
	while (buf[n] != '\n' && buf[n] && buf[0])
		n++;
	while (elem->rest[n] != '\n' && elem->rest[n] && !buf[0])
		n++;
	str[0] = malloc((i + n + 1) * sizeof(char));
	ft_bzero(str[0], i + n + 1);
	if (buffer)
		ft_strcpy(str[0], buffer);
	free(buffer);
	return (str);
}

static t_gnl	*create_node(t_gnl *begin, int fd)
{
	t_gnl *elem;

	if (!begin)
	{
		elem = malloc(sizeof(t_list));
		if (elem)
		{
			elem->fd = 257;
			elem->rest = NULL;
			elem->next = NULL;
		}
		return (elem);
	}
	elem = begin;
	while (elem->next && elem->fd != fd)
		elem = elem->next;
	if (elem->fd == fd)
		return (elem);
	elem->next = malloc(sizeof(t_list));
	elem->next->fd = fd;
	elem->next->state = 0;
	elem->next->next = NULL;
	elem->next->rest = malloc((BUFF_SIZE + 1) * sizeof(char));
	ft_bzero(elem->next->rest, BUFF_SIZE + 1);
	return (elem->next);
}

static int		stock_rest(t_gnl *elem, char **str, char *buf)
{
	int i;

	i = 0;
	str[0] = NULL;
	if (elem->rest[0] == '\0')
		return (0);
	str = alloc_str(elem, str, buf);
	while (elem->rest[i] && elem->rest[i] != '\n')
	{
		str[0][i] = elem->rest[i];
		i++;
	}
	str[0][i] = '\0';
	if (elem->rest[i] == '\n')
	{
		i++;
		ft_memmove(elem->rest, elem->rest + i, BUFF_SIZE - i);
		ft_bzero(elem->rest + (BUFF_SIZE - i), i + 1);
		return (1);
	}
	return (0);
}

static int		stock_buf(t_gnl *elem, char *buf, char **str)
{
	int i;
	int n;

	n = 0;
	if (!buf[0] && !elem->rest[0] && elem->state)
		return (3);
	elem->state = 0;
	ft_bzero(elem->rest, BUFF_SIZE);
	str = alloc_str(elem, str, buf);
	i = ft_strlen(str[0]);
	while (buf[n] && buf[n] != '\n')
		str[0][i++] = buf[n++];
	if (!buf[n] && n < BUFF_SIZE)
		return (elem->state = 1);
	if (buf[n] == '\n')
	{
		n++;
		i = 0;
		while (buf[n])
			elem->rest[i++] = buf[n++];
		ft_bzero(buf, BUFF_SIZE);
		return (elem->state = 1);
	}
	ft_bzero(buf, BUFF_SIZE);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*begin;
	t_gnl			*elem;
	char			buf[BUFF_SIZE + 1];
	int				u;
	int				i;

	if (!line || BUFF_SIZE < 1)
		return (-1);
	i = 1;
	ft_bzero(buf, BUFF_SIZE + 1);
	u = 0;
	if (!begin)
		begin = create_node(NULL, -1);
	elem = begin;
	if (elem->fd != fd)
		elem = create_node(elem, fd);
	u = stock_rest(elem, line, buf);
	while (!u || u == 2)
	{
		if ((i = read(fd, buf, BUFF_SIZE) == -1))
			return (-1);
		if ((u = stock_buf(elem, buf, line)) == 3)
			return (0);
	}
	return (1);
}