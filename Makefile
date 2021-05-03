##
## EPITECH PROJECT, 2021
## B-MUL-200-NAN-2-1-mydefender-nathan.rousseau
## File description:
## Makefile
##

CC = gcc

FILES = main.c										\
		game.c										\
		init/init_window.c							\
		init/prep_game_struct.c						\
		button/button.c 							\
		button/button_functions.c 					\
		button/original_state_button.c 				\
		button/original_state_button_start_menu.c	\
		button/original_state_button_pause_menu.c 	\
		button/button_functions_two.c 				\
		display/display_game.c 						\
		display/display_background.c 				\
		display/display_monsters.c 					\
		display/draw_start_menu.c 					\
		display/display_pause_menu.c 				\
		display/display_help_menu.c 				\
		display/display_tower.c						\
		ennemies/monsters.c							\
		ennemies/game_objects.c						\
		menu/start_menu.c 							\
		menu/game_menu.c 							\
		menu/pause_menu.c 							\
		menu/button_start_menu.c 					\
		menu/how_to_play_menu.c 					\
		event_mouse/check_click.c					\
		event_mouse/event_click.c 					\
		event_mouse/check_released.c 				\
		event_mouse/check_button.c 					\
		monsters/spawn_monsters.c 					\
		tools/int_to_str.c 							\
		tools/is_in_rectangle.c 					\
		tools/my_get_nbr.c							\
		tower/prep_tower_zone.c						\
		tower/create_tower.c 						\
		tower/init_tower.c 							\
		tower/next_tower.c 							\
		tower/visual_effect_tower.c 				\
		tower/create_params_tower.c					\
		font/money.c								\
		font/life.c									\
		font/waves.c								\
		font/texts.c 								\
		free/free_struct.c							\
		free/free_obj_button.c 						\
		attack/handle_attack.c 						\
		attack/take_dammage.c 						\


SRC = $(FILES:%=src/%)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I./include/

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lm -lcsfml-audio

RM = rm -f

NAME = my_defender

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lm $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug        :        CFLAGS += -g
debug        :        re

.PHONY: all clean fclean re debug