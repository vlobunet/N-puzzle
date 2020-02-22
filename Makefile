NAME		= N-puzzle
SRCS		= src/main.c

OBJS		= $(SRCS:.c=.o)
FLAGS		= -g3 -Wall -Wextra -Werror
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
	@gcc -o $(NAME) $(FLAGS) $(OBJS) $(LIB) -ltermcap
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
