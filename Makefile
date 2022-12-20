##
## EPITECH PROJECT, 2022
## B-CPE-101-NCY-1-1-myprintf-guillaume.michel
## File description:
## Makefile
##

CFLAGS	+=	-W -Wall -Wextra

SRC     =       $(wildcard src/*.c)

OBJ     =		$(SRC:.c=.o)

NAME    =		push_swap

all:	$(NAME)

$(NAME):        $(OBJ)
		gcc -g -o $(NAME) src/*.c -s $(CFLAGS) -O2
		make clean

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f *.log
		rm -f $(NAME)

re:		fclean all
