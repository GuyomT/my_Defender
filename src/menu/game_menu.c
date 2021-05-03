/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** game_menu
*/

#include "defender.h"

sfRectangleShape **init_tower_place(sfRectangleShape **tower_place)
{
    tower_place = malloc(sizeof(sfRectangleShape *) * (13));
    if (!tower_place)
        return NULL;
    tower_place[12] = NULL;
    for (int i = 0; i < 12; i++)
        tower_place[i] = sfRectangleShape_create();
    tower_place = prep_towers_zone(tower_place);
    return tower_place;
}

game_menu_t *init_clock_game_menu(game_menu_t *play)
{
    play->clock_golem = sfClock_create();
    play->clock_wolf = sfClock_create();
    play->clock_dino = sfClock_create();
    return play;
}

game_menu_t *init_monsters(game_menu_t *play, int wave)
{
    play->golem = init_golem(play->golem, play->waves[wave][0]);
    play->wolf = init_wolf(play->wolf, play->waves[wave][1]);
    play->dino = init_dino(play->dino, play->waves[wave][2]);
    if (!play->golem || !play->wolf || !play->dino)
        return NULL;
    return play;
}

game_menu_t *init_waves(game_menu_t *play)
{
    int mob = 1;
    play->waves = malloc(sizeof(int *) * (14));
    if (!play->waves)
        return NULL;
    play->waves[13] = NULL;
    for (int i = 0; i < 13; i++) {
        play->waves[i] = malloc(sizeof(int) * (3));
        if (!play->waves[i])
            return NULL;
    }
    for (int x = 0; x < 13; x++) {
        for (int y = 0; y < 3; y++) {
            play->waves[x][y] = mob;
            mob += 2;
        }
        if (x == 12)
            play->waves[x][0] = 30;
        mob -= 4;
    } play->tower_value = 0;
    return play;
}

game_menu_t *init_game_menu(game_menu_t *play)
{
    if (!(play = malloc(sizeof(game_menu_t))))
        return NULL;
    if (!(play = init_waves(play)))
        return NULL;
    if (!(play = init_monsters(play, 0)))
        return NULL;
    if (!(play->pause_button = malloc(sizeof(button_t))))
        return NULL;
    play->pause_button = init_pause_button(play->pause_button, \
    "include/data/pause_button.png");
    if (!(play->tower_place = init_tower_place(play->tower_place)))
        return NULL;
    if (!(play->tower = init_tower(play->tower)))
        return NULL;
    play = init_clock_game_menu(play);
    if (!(play = init_texts(play)))
        return NULL;
    return play;
}