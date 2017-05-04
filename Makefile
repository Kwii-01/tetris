##
## Makefile for navy in /home/robin.milas/Current/PSU_2016_navy
## 
## Made by Robin MILAS
## Login   <robin.milas@epitech.net>
## 
## Started on  Mon Dec  5 18:52:38 2016 Robin MILAS
## Last update Sun Mar 19 23:16:31 2017 Milas Robin
##

CC	=	gcc

RM	=	rm -f

SRCS	=	src/main.c				\
		src/debuger.c				\
		src/err.c				\
		src/flags.c				\
		src/flags_next.c			\
		src/flags_handler.c			\
		src/fill_shape.c			\
		src/get_shapes.c			\
		src/game/commands.c			\
		src/game/game.c				\
		src/game/draw_map.c			\
		src/game/highscore.c			\
		src/game/left_right.c			\
		src/game/informations.c			\
		src/game/init.c				\
		src/game/display_game.c			\
		src/game/launch_tetriminos.c		\
		src/game/print_next.c			\
		src/game/down.c				\
		src/game/remove_line.c			\
		src/game/touch_something.c		\
		src/insert.c				\
		src/parse_nb.c				\
		src/set_term.c				\
		src/simpleflag.c			\
		src/simpleflag_next.c			\
		src/tetriminos.c			\
		src/tools/my_itoa.c			\
		src/tools/my_strcmp.c			\
		src/tools/my_strlen.c			\
		src/tools/my_strcats.c			\
		src/tools/get_next_line.c		\
		src/tools/my_cpy_atm.c			\
		src/tools/get_nbr.c			\
		src/tools/my_str_to_wordtab.c		\
		src/tools/my_tabcat.c			\
		src/tools/my_strcpy.c			\
		src/tools/math.c


OBJS	=	$(SRCS:.c=.o)

NAME	=	tetris

CFLAGS	=	-Wall -Wextra  -I./include

LDFLAGS	=	-L./lib/libprtf.a -lprtf -lncurses

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		make -C ./lib/libprtf.a
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean	:
		make clean -C ./lib/libprtf.a
		$(RM) $(OBJS)

fclean	:
		make fclean -C ./lib/libprtf.a
		$(RM) $(NAME) $(OBJS)

re	:	fclean all

.PHONY	:	all re fclean clean
