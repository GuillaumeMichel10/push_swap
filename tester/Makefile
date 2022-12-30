##
## EPITECH PROJECT, 2022
## B-CPE-101-NCY-1-1-myprintf-guillaume.michel
## File description:
## Makefile
##

CFLAGS	+=	-W -Wall -Wextra
LDFLAGS	=	-lncurses

SRC     =       $(wildcard *.c)

OBJ     =		$(SRC:.c=.o)

NAME    =		push_swap_tester

all:	$(NAME)

$(NAME):        $(OBJ)
		gcc -g -o $(NAME) *.c -s $(LDFLAGS) -O2 -g3
		make clean

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f *.log
		rm -f $(NAME)

re:		fclean all
