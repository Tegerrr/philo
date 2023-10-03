NAME = philo

SRC	= mandatory/src/error.c		mandatory/src/main.c\
		mandatory/src/philo.c	mandatory/src/parsing.c\
		mandatory/src/utils.c

HEADER = mandatory/src/philo.h

OBJ = $(patsubst %.c, %.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ -c $<

clean :
		rm -f $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re