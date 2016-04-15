##
## Makefile for rt in /home/josso/en_cours/rt
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Fri Jan 29 18:32:59 2016 Arthur Josso
## Last update Fri Apr 15 14:51:11 2016 alies_a
##

NAME    =	raytracer1

CC	= 	gcc -g

INC     =       ./include/

CFLAGS 	+=	-I$(INC) \
		-W -Wall -Wextra -O3

LDFLAGS +=	-I/home/${USER}/.froot/include/ \
                -L/home/${USER}/.froot/lib/ \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window \
                -lsfml-system -lstdc++ -ldl -lm \
		-lpthread

SRCS	=	./src/

INIT	=	./src/init/

MATH	=	./src/math/

PREVIEW	=	./src/preview/

LIGHT	=	./src/light/

DISPLAY	=	./src/display/

CORE	=	./src/core/

TCORE	=	./tcore/

MY	=	./src/my/

EXIT	=	./src/exit/

PERLIN	=	./src/perlin/

SOLVER	=	./src/solver/

JIF	=	./src/jif/

SRC	= 	$(SRCS)main.c \
		$(DISPLAY)thread.c \
		$(DISPLAY)display.c \
		$(INIT)init.c \
		$(INIT)get.c \
		$(INIT)get2.c \
		$(INIT)load.c \
		$(INIT)add_cam.c \
		$(INIT)add_cylinder.c \
		$(INIT)add_light.c \
		$(INIT)add_sphere.c \
		$(INIT)add_cone.c \
		$(INIT)add_torus.c \
		$(MATH)find_k.c \
		$(MATH)math.c \
		$(MATH)sphere.c \
		$(MATH)cylinder.c \
		$(MATH)cone.c \
		$(MATH)torus.c \
		$(MATH)screen.c \
		$(MATH)rotation.c \
		$(SOLVER)op.c \
		$(SOLVER)math.c \
		$(SOLVER)utils.c \
		$(SOLVER)deg_2.c \
		$(SOLVER)deg_3.c \
		$(SOLVER)deg_4.c \
		$(LIGHT)light.c \
		$(LIGHT)phong.c \
		$(LIGHT)normal_vec.c \
		$(LIGHT)reflect.c \
		$(LIGHT)refract.c \
		$(LIGHT)antialiasing.c \
		$(PERLIN)gen_tab.c \
		$(PERLIN)perlin.c \
		$(PERLIN)core_perlin.c \
		$(TCORE)tekpixel.c \
		$(TCORE)tekray.c \
		$(CORE)color.c \
		$(CORE)vector.c \
		$(CORE)vector2.c \
		$(CORE)texture.c \
		$(CORE)get_perlin.c \
		$(CORE)reflec_vector.c \
		$(CORE)bump_vec.c \
		$(PREVIEW)move.c \
		$(EXIT)exit.c \
		$(JIF)new.c \
                $(JIF)open.c \
                $(JIF)add.c \
                $(JIF)close.c \
                $(JIF)next.c \
		$(JIF)path_open.c \
		$(MY)my_getnbr.c \
		$(MY)my_getdouble.c \
		$(MY)my_strcmp.c \
		$(MY)my_getpixel.c

OBJ	= 	$(SRC:.c=.o)

RM	= 	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) 

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
