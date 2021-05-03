/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** visual_effect_tower
*/

#include "defender.h"

game_menu_t *outline_unselected(game_menu_t *play)
{
    for (int i = 0; i < 12; i++) {
        sfRectangleShape_setOutlineColor(play->tower_place[i], sfGreen);
    }
    return play;
}

game_menu_t *warning_wrong_zone(game_menu_t *play, game_t *settings)
{
    play->tower_value = 0;
    for (int i = 0; i < 8; i++) {
        sfRectangleShape_setOutlineColor(play->tower_place[i], sfRed);
    }
    for (int i = 0; i < 8; i++) {
        sfRenderWindow_drawRectangleShape(settings->set_w->window, \
        play->tower_place[i], NULL);
    }
    return play;
}

game_menu_t *select_tower(game_menu_t *play, int nbr_tower)
{
    play->tower_value = (nbr_tower - 7);
    for (int i = 0; i < 12; i++) {
        sfRectangleShape_setOutlineColor(play->tower_place[i], sfGreen);
    }
    sfRectangleShape_setOutlineColor(play->tower_place[nbr_tower], sfYellow);
    return play;
}