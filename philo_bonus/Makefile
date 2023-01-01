SRCS = philo_bonus.c routines_bonus.c utils1_bonus.c utils_bonus.c parassign_bonus.c
OBJS = ${SRCS:.c=.o}
NAME = philo_bonus
INC = philo_bonus.h 
CC = cc
CFLAGS =  -Wall -Wextra -Werror
RM = rm -vf


all: $(NAME)
$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME) 
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean:
	$(RM) $(NAME) $(OBJS)
re: fclean all
.PHONY: fclean all re clean
