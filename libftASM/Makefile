NAME = libfts.a

SRC = ft_bzero.s ft_isalpha.s ft_isdigit.s ft_isascii.s ft_isprint.s \
	ft_isalnum.s ft_tolower.s ft_toupper.s ft_strcat.s ft_strlen.s ft_puts.s \
	ft_memset.s ft_memcpy.s ft_strdup.s ft_cat.s \
	ft_putchar.s ft_putstr.s \
	ft_memalloc.s ft_strchr.s ft_strncmp.s ft_strncpy.s \
	ft_atoll.s ft_atoi.s

OBJDIR = objs

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.s=.o))

AS = nasm

ASFLAGS = -f macho64 -g

CC = clang

CFLAGS = -Wall -Wextra -fsanitize=address,undefined -g

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[01;38;05;46m
YELLOW      = \033[38;05;226m
BLUE        = \033[03;38;05;21m
VIOLET      = \033[01;38;05;201m
CYAN        = \033[1;36m
WHITE       = \033[01;38;05;15m
RES			= \033[m

all: ${NAME}
	@echo  "\b$(YELLOW) : OK$(RES)"

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}

${OBJDIR}/%.o : ./srcs/%.s
	@/bin/mkdir -p ${OBJDIR}
	@${AS} ${ASFLAGS} -o $@ $<
	@echo  "$(BLUE)█$(RES)\c)"

clean:
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
