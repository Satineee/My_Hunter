##
## EPITECH PROJECT, 2022
## CPE
## File description:
## Makefile
##

CC	?=   gcc 

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio


SRC	=	my_hunter.c	\
		init.c	\
		event.c	\
		my_strlen.c	\
		destroy.c	\
		display.c	\
		home_page.c	\
		save_best_score.c	\
		init_arg.c	\
		sleep.c	\
		display_home.c

PATHH	=	-i include/

TESTS	=	tests/test.c

NAME	=	my_hunter

H_NAME	=	my.h

OBJ = $(SRC:.c=.o)

all:	$(NAME) clean

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	
clean:
	@rm -f *~
	@rm -f *#*
	@rm -f *gcno
	@rm -f *gcda
	@rm -f unit_tests
	@rm -f tests/*~
	@rm -f tests/*#*
	@rm -f libmy.a
	@rm -f coding-style-reports.log
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re:	fclean all
