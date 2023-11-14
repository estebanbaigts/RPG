##
## EPITECH PROJECT, 2023
## B-MUL-200-BDX-2-1-myrpg-noa.messer
## File description:
## Makefile
##

NAME = my_rpg

SRC =	src/player/init_player.c \
		src/player/player_update.c \
		src/player/player_render.c \
		src/player/player_event.c \
		src/player/player_animation.c \
		src/player/collision.c \
		src/camera/camera.c \
		src/map/map.c \
		src/map/teleport.c \
		src/map/map_collision.c \
		src/map/layer.c \
		src/utils/get_path.c \
		src/utils/load_texture.c \
		src/utils/player_is_moving.c \
		src/utils/file_to_str.c \
		src/lib/my_strlen.c \
		src/lib/my_strcpy.c \
		src/lib/my_strcat.c \
		src/lib/count_char.c \
		src/lib/my_strdup.c \
		src/particle/particle_list.c \
		src/stat/init_stat.c \
		src/stat/render_stat.c \
		src/npc/init_npc.c \
		src/npc/update_npc.c \
		src/npc/render_npc.c \
		src/npc/dialogue.c \
		src/npc/pancarte.c \
		src/enemies/ghoul/ghoul.c \
		src/enemies/ghoul/ghoul_list.c \
		src/enemies/ghoul/ghoul_animation.c \
		src/enemies/ghoul/ghoul_hit.c \
		src/enemies/enemies.c \
		src/sound/init_sound.c	\
		src/menu/init_menu.c \
		src/menu/update_menu.c \
		src/menu/render_menu.c \
		src/window.c \
		src/event.c \
		src/render.c \
		src/update.c \
		src/game.c \
		src/clock.c \
		src/text.c \
		src/main.c

OBJ = $(SRC:.c=.o)

CPPFLAGS += -I./include
CPPFLAGS += -lcsfml-graphics
CPPFLAGS += -lcsfml-system
CPPFLAGS += -lcsfml-window
CPPFLAGS += -lcsfml-audio

CC = gcc

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
