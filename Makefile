NAME = philo

SRC	= 	error.c	main.c\
		philo.c	parsing.c\
		utils.c	habits.c

HEADER = philo.h

OBJ = $(patsubst %.c, %.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror

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