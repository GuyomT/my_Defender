/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "defender.h"

typedef struct button_s {
    sfRectangleShape *shape;
    sfTexture *texture;
    sfVector2f size;
    sfVector2f pos;
    sfMusic *sound;
    void (*ptr)();
}button_t;

typedef struct window_params_s{
    sfTexture *texture;
    sfSprite *sprite;
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
}window_params_t;

typedef struct GameObject_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect mask;
    int nb_frames;
    sfClock *clock;
    float frame_speed;
    sfVector2f *paths;
    int nb_paths;
    sfVector2f obj_speed;
    int pv;
    bool has_spawned;
    bool is_destroy;
}GameObject_t;

typedef struct money_s {
    int moula;
    sfFont *font;
    sfText *text;
    sfVector2f pos;
}money_t;

typedef struct life_s {
    int life;
    sfFont *font;
    sfText *text;
    sfVector2f pos;
}life_t;

typedef struct waves_s {
    int wave;
    sfFont *font;
    sfText *text;
    sfVector2f pos;
}waves_t;

typedef struct tower_s {
    int tower_type;
    int dammage;
    sfTexture *texture;
    sfRectangleShape *shape;
    sfCircleShape *range;
    int radius;
    float shoot_speed;
    sfClock *clock;
    bool created;
}tower_t;

typedef struct game_menu_s {
    button_t *pause_button;
    GameObject_t **golem;
    GameObject_t **wolf;
    GameObject_t **dino;
    sfClock *clock_golem;
    sfClock *clock_wolf;
    sfClock *clock_dino;
    sfRectangleShape **tower_place;
    tower_t **tower;
    int **waves;
    int tower_value;
    money_t *money;
    life_t *life;
    waves_t *wave;
    int score;
}game_menu_t;

typedef struct start_menu_s {
    button_t *start_button;
    button_t *quit_button;
    button_t *how_button;
    sfTexture *texture;
    sfRectangleShape *rect;
    sfMusic *music;
}start_menu_t;

typedef struct pause_s {
    button_t *resume;
    button_t *main_menu;
    button_t *quit;
    sfRectangleShape *menu;
    sfTexture *texture;
}pause_t;

typedef struct how_s {
    button_t *menu;
}how_t;

typedef struct game_s {
    window_params_t *set_w;
    start_menu_t *start;
    game_menu_t *play;
    pause_t *pause_menu;
    how_t *how_menu;
    bool start_menu;
    bool game;
    bool pause;
    bool how_to_play;
}game_t;

#endif /* !STRUCT_H_ */
