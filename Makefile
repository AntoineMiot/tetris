##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC	=	main_tetris.c	\
		tetrimino.c \

OBJ		=	$(SRC:.c=.o)

NAME	=	tetris

CFLAGS  = -I include -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L./lib -lmy
	rm *.o

clean:
	rm -f $(OBJ)
	rm -f vgcore.*
	rm -f *.o

fclean:	clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:	fclean all
