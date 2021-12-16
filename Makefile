NAME		= philo
CC			= clang
FLAGS		= -g -pthread -Wall -Wextra -Werror
RM			= rm -rf
INC			= ./inc
INC_FILE	= ./inc/*

SRCS_PATH	= ./src/
OBJS_PATH	= ./objs/

SRCS_NAME	=	philo.c get_param.c init.c time.c \
				action.c utilit.c error_exit.c
SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -I $(INC) -o $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC_FILE)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

clean:
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)
re:			fclean all

.PHONY: all clean fclean re
