SRCS = philo.c routines.c utils1.c utils.c parassign.c
OBJS = ${SRCS:.c=.o}
NAME = philo
INC = philo.h 
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
