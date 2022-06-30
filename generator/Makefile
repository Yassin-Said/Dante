##
## EPITECH PROJECT, 2021
## makefile
## File description:
## compile all program
##

IFLAG   =	-I ./includes

SRC	=	main.c \
		lib/my/my_strlen.c	\
		utility.c	\
		parse_cond.c	\
		move.c

CFLAG	=	-W -Werror -Wextra -Wall -g3

LIBS	=	-L/usr/lib/x86_64-linux-gnu -lm

GFLAG   =	-lcsfml-graphics -lcsfml-system -lcsfml-window

TFLAG	=	-lcriterion --coverage

NAME	=	generator
all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(IFLAG) $(SRC) $(CFLAG) $(LFLAG) $(GFLAG) $(LIBS)

clean:
	rm -f *~

fclean:	clean
	rm -f $(NAME)	\
	rm -f my_ls	\
	rm -f *.gcno	\
	rm -f *.gcda	\
	rm vgcore*

val:
	gcc -o $(NAME) -I ./includes/ $(SRC) $(IFLAG) $(CFLAG) $(GFLAG) $(LIBS) -g3

tests_run:
	gcc -o test $(MFLAG) $(IFLAG) $(SRC) $(CFLAG) $(LFLAG) $(MFLAG)
	./test

re: fclean all
