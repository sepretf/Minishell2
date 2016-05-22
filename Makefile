##
## Makefile for  in /home/sepret_f/CPE_2015_BSQ
##
## Made by fabrice sepret
## Login   <sepret_f@epitech.net>
##
## Started on  Fri Dec 18 16:00:02 2015 fabrice sepret
## Last update Tue Apr 12 12:01:26 2016 fabrice sepret
##

SRC =	get_next_line.c \
	main.c \
	my_put.c \
	my_exec_prog.c \
	error.c \
	my_strcmp.c \
	my_get_home.c \
	my_atoi.c \
	my_unset.c \
	chang_env.c \
	my_env.c \
	my_strcat.c \
	com_to_str.c \
	check.c \
	redirect.c \
	redirect2.c \
	try_pipe.c \
	manag_str.c \

NAME =	mysh

OBJ =	$(SRC:.c=.o)

RM =	rm -rf

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
