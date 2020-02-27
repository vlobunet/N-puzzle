#ifndef LIBFTS_H
# define LIBFTS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

long long	ft_atoll(const char *str);
int			ft_atoi(const char *str);
char		*ft_strncpy(char * dst, const char * src, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, const char c);
void		*ft_memalloc(const unsigned long int len);
void		ft_cat(const int fd);
char		*ft_strdup(const char *s);
char		*ft_strcat(char *restrict s1, const char *restrict s2);
void		*ft_memcpy(void *restrict dst, const void *restrict src, \
						size_t n);
void		*ft_memset(void *a, int c, size_t len);
void		ft_bzero(void *a, size_t len);
int			ft_toupper(int a);
int			ft_tolower(int a);
size_t		ft_strlen(const char *s);
int			ft_isalpha(int a);
int			ft_isascii(int a);
int			ft_isdigit(int a);
int			ft_isalnum(int a);
int			ft_isprint(int a);
void		ft_putchar(char c);
int			ft_puts(char *s);
int			ft_putstr(char *s);
void		ft_putchar_fd(const char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putendl(char const *s);
char		*ft_strnew(size_t i);
char		**ft_strsplit(const char *s, char delim);
void		ft_strdel(char **as);
void		ft_memdel(void **ap);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strsub(char *str, unsigned int start, size_t len);
char		*ft_strncpy(char *dest, const char *src, size_t len);
char		*ft_strcpy(char *dst, const char *src);

void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *p1, const void *p2, size_t n);

#endif
