##
## Makefile for Ma in /home/alies_a/rendu/gfx_raytracer2
## 
## Made by alies_a
## Login   <alies_a@epitech.net>
## 
## Started on  Mon Apr 11 15:47:30 2016 alies_a
## Last update Mon Apr 11 17:17:09 2016 alies_a
##

NAME    =       raytracer2

CC	=	gcc -g

LIB	=	./lib/

INC	=	./include/

CFLAGS	=	-I$(INC) \
		-W -Wall -Wextra

LDFLAGS	=	-I/home/${USER}/.froot/include \
                -L/home/${USER}/.froot/lib \
                -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
		-lOpenCL

SRC	=	./src/

CL	=	./src/cl/

SRCS	=	$(SRC)main.c \
		$(CL)load.c

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
