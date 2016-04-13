##
## Makefile for rt1 in /home/alies_a/rendu/gfx_raytracer1
## 
## Made by alies_a
## Login   <alies_a@epitech.net>
## 
## Started on  Fri Jan 29 14:31:30 2016 alies_a
## Last update Wed Apr 13 12:37:43 2016 alies_a
##

NAME    =       gif

CC	=	gcc -g

LIB	=	./lib/

INC	=	./include/

CFLAGS	=	-I$(INC) \
		-W -Wall -Wextra

LDFLAGS	=	-I/home/${USER}/.froot/include \
                -L/home/${USER}/.froot/lib \
                -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

SRC	=	./src/

SRCS	=	$(SRC)main.c \
		$(SRC)tekpixel.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
