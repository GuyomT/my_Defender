/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-nathan.rousseau
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#define ERROR 84
#define EXIT_HELP 1
#define EXIT_OPTIONS 2
#define EXIT 0
#define BASIC_T 1
#define FREEZE_T 2
#define MORTAR_T 3
#define SNIPER_T 4

#include <SFML/Window/Event.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include "struct.h"

//button_functions
void get_ingame(game_t *settings);
void close_start_window(game_t *settings);
void pause(game_t *settings);
void resume(game_t *settings);
void main_menu(game_t *settings);
void get_in_help_menu(game_t *settings);
void go_back_main_menu(game_t *settings);

//prep_game_struct
game_t *prep_struct_for_game(game_t *settings);

//window
int open_window(game_t *settings);

//events
int handle_events(game_t *settings);

//init_window
window_params_t *create_window_struct(window_params_t *set_w);

//start_menu
start_menu_t *init_start_menu(start_menu_t *start);

//button
button_t *init_button(button_t *button, sfVector2f size, sfVector2f pos);
button_t *init_pause_button(button_t *pause_button, char *filepath);

//check_clicks
void check_released_events(game_t *settings);
void check_released_start_menu_buttons(start_menu_t *start, game_t *settings, \
sfVector2i mouse_pos);
void check_click_events(game_t *settings);
void check_click_pause_menu_button(pause_t *pause_menu, sfVector2i mouse_pos);
void check_click_go_back_button(how_t *how_menu, sfVector2i mouse_pos);

//check_clicks start_menu
bool check_button_play(button_t *start_button, sfVector2i mouse_pos);
bool check_button_quit(button_t *quit_button, sfVector2i mouse_pos);
bool check_if_over_button(button_t *button, sfVector2i mouse_pos);
void check_clicked_start_menu_button(start_menu_t *start, \
sfVector2i mouse_pos);

//draw_menu_start
void display_start_menu(game_t *settings);

//game_menu
game_menu_t *init_game_menu(game_menu_t *play);

//monsters
GameObject_t **init_golem(GameObject_t **golem, int nb_golem);
GameObject_t **init_wolf(GameObject_t **wolf, int nb_wolf);
GameObject_t **init_dino(GameObject_t **dino, int nb_dino);

//display_game
void display_game(game_t *settings);

//game_objects
void update_sprite(GameObject_t *obj, float move_x);
GameObject_t *center_origin(GameObject_t *obj);
GameObject_t *create_game_object(char *filepath_to_img, int nb_frames, \
sfVector2f pos, float speed);
void move_game_object(GameObject_t *obj, sfVector2f obj_speed);
void update_game_object(GameObject_t *obj);

//display_background
void display_background(game_t *settings);

//display_monster
void display_golem(game_t *settings);
void display_wolf(game_t *settings);
void display_dino(game_t *settings);

//spawn_monsters
game_menu_t *make_dino_alive(game_menu_t *play);
game_menu_t *make_golem_alive(game_menu_t *play);
game_menu_t *make_wolf_alive(game_menu_t *play);

//original_state_button
void original_state(game_t *settings);
void original_button_state_start_menu(start_menu_t *start, game_t *settings);
void original_state_quit_button(button_t *quit_button);
void original_button_state_start_menu(start_menu_t *start, game_t *settings);
void original_pause_button(button_t *pause_button, game_t *settings);

//int_to_str
char *int_to_str(int nb);
int nbr_len(int nb);
char *my_revstr(char *str);
int my_strlen(char *str);
int my_getnbr(char const *str);

//check_released
void check_released_start_menu_button(start_menu_t *start, game_t *settings, \
sfVector2i mouse_pos);
void check_released_pause_button(button_t *pause_button, game_t *settings, \
sfVector2i mouse_pos);
void check_click_pause_button(button_t *pause_button, sfVector2i mouse_pos);
void check_released_pause_menu_button(pause_t *pause_menu, game_t *settings, \
sfVector2i mouse_pos);
void check_released_go_back_button(how_t *how_menu, game_t *settings, \
sfVector2i mouse_pos);

//pause_menu
pause_t *init_pause_menu(pause_t *pause_menu);
pause_t *init_texture_pause_menu(pause_t *pause_menu, char *filepath);

//display_pause_menu
void display_pause_menu(game_t *settings);

//original_state_button_start_menu
void original_state_quit_button(button_t *quit_button);
void original_state_start_button(button_t *start_button);
void original_state_how_button(button_t *how_button);

//original_state_button_pause_menu
void original_button_state_resume_button(pause_t *pause_menu, game_t *settings);
void original_button_state_quit_button(pause_t *pause_menu, game_t *settings);
void original_button_state_main_menu_button(pause_t *pause_menu, \
game_t *settings);

//money
money_t *create_money(money_t *money);

//life
life_t *create_life(life_t *life);

//waves
waves_t *create_waves(waves_t *waves);

//prep_tower_zone
sfRectangleShape *prepare_tower(sfRectangleShape *tower, sfVector2f pos, \
sfVector2f size);
sfRectangleShape **prep_towers_zone(sfRectangleShape **tower_place);

//free struct
void free_start_menu(start_menu_t *start);
void free_game_menu(game_menu_t *play);
void free_pause_menu(pause_t *pause);
void free_window(window_params_t *set_w);

//free_obj_button
void free_game_object(GameObject_t *obj);
void free_button(button_t *button);

//init_tower
tower_t **init_tower(tower_t **tower);
void display_tower_zone(game_t *settings);

//is_in_rectangle
game_menu_t *is_click_for_tower(game_menu_t *play, sfVector2i mouse_pos, \
game_t *settings);

//visual_effect
game_menu_t *select_tower(game_menu_t *play, int nbr_tower);
game_menu_t *warning_wrong_zone(game_menu_t *play, game_t *settings);
game_menu_t *outline_unselected(game_menu_t *play);

//next_tower
int next_tower(tower_t **tower);

//create_tower
game_menu_t *create_tower(game_menu_t *play, int nb_rect, game_t *settings);

//button_start_menu
button_t *create_start_button(button_t *button, char *filepath);
button_t *create_quit_button(button_t *button, char *filepath);
button_t *create_help_button(button_t *button, char *filepath);

//display_how_to_play
void display_how_to_play(game_t *settings);

//how_to_play_menu
how_t *init_help_menu(how_t *how_menu);

//create_params_tower
tower_t *create_params_tower(tower_t *tower, int type, int damage, \
char *filepath);
tower_t *create_rect_shape(tower_t *tower, sfVector2u size, sfVector2f pos);
tower_t *create_range(tower_t *tower, sfVector2f pos);

//attack
game_menu_t *handle_attack(game_menu_t *play);
bool take_dammage(tower_t *tower, GameObject_t *obj);
game_menu_t *init_monsters(game_menu_t *play, int wave);
game_menu_t *next_wave(game_menu_t *play);
game_menu_t *init_texts(game_menu_t *play);

#endif /* !DEFENDER_H_ */
