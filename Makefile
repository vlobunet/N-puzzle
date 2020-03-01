NAME		=	N-puzzle
SRCS		=	src/main.c \
				src/error.c \
				src/file_check.c \
				src/check_attr.c \
				src/get_next_line.c \
				src/validation.c \
				src/ft_solvable.c \
				src/input_map.c \
				src/AStar.c \
				src/goal.c \
				src/hash.c \
				src/heuristic_func.c

OBJS		= $(SRCS:.c=.o)
FLAGS		= -g3 -Wall -Wextra -Werror -fsanitize=address,undefined -g
INCL 		= -I./includes -I./libftASM/includes
HEADER		= includes/puzzle.h
LIB			= libftASM/libfts.a

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[01;38;05;46m
YELLOW      = \033[01;38;05;226m
BLUE        = \033[03;38;05;21m
VIOLET      = \033[01;38;05;201m
CYAN        = \033[1;36m
WHITE       = \033[01;38;05;15m
RES			= \033[m


all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@gcc -o $(NAME) $(FLAGS) $(OBJS) $(LIB)
	@echo  "\b$(YELLOW) : OK$(RES)"

%.o: %.c $(HEADER)
	@gcc -c $(FLAGS) $(INCL) -o $@ -c $<
	@echo  "$(YELLOW)█$(RES)\c)"

$(LIB):
	@echo  "$(GREEN)Compiling: $(WHITE)libftASM$(RES)$(YELLOW) : $(RES)\c)"
	@make -C libftASM
	@echo  "$(GREEN)Compiling: $(WHITE)N-puzzle$(RES)$(YELLOW) : $(RES)\c)"

clean:
	@make -C libftASM clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(OBJS)
	@make -C libftASM fclean

re: fclean $(NAME)
