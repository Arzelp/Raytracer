##
## Makefile for rt1 in /home/alies_a/rendu/gfx_raytracer1
## 
## Made by alies_a
## Login   <alies_a@epitech.net>
## 
## Started on  Fri Jan 29 14:31:30 2016 alies_a
## Last update Fri Apr 15 13:08:13 2016 alies_a
##

NAME    =       jif

CC	=	gcc -g

LIB	=	./lib/

INC	=	./include/

CFLAGS	=	-I$(INC) \
		-W -Wall -Wextra

LDFLAGS	=	-I/home/${USER}/.froot/include \
                -L/home/${USER}/.froot/lib \
                -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

SRC	=	./src/

JIF	=	./src/jif/

SRCS	=	$(SRC)main.c \
		$(SRC)tekpixel.c \
		$(JIF)new.c \
		$(JIF)open.c \
		$(JIF)add.c \
		$(JIF)close.c \
		$(JIF)next.c

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
