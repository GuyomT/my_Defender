/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** display_help_menu
*/

#include "defender.h"

void display_how_to_play(game_t *settings)
{
    sfRenderWindow_drawRectangleShape(settings->set_w->window, \
    settings->how_menu->menu->shape, NULL);
}