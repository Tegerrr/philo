NAME = philo
NAME_B = philo_bonus

SRC	= 	mandatory/error.c	mandatory/main.c\
		mandatory/philo.c	mandatory/parsing.c\
		mandatory/utils.c	mandatory/habits.c

SRC_B = bonus/error.c	bonus/main.c\
		bonus/philo.c	bonus/parsing.c\
		bonus/utils.c	bonus/habits.c

HEADER = mandatory/philo.h
HEADER_B = bonus/philo.h

OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_B = $(patsubst %.c, %.o, $(SRC_B))

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread

CC = cc

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ -c $<

bonus :
		make OBJ="$(OBJ_B)" HEADER="$(HEADER_B)" NAME="$(NAME_B)" all

clean :
		rm -f $(OBJ) $(OBJ_B)

fclean : clean
		$(RM) $(NAME)

re : fclean all

rb : fclean bonus

.PHONY : all clean fclean re bonus rb