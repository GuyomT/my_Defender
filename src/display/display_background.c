/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** display_background
*/

#include "defender.h"

void display_background(game_t *settings)
{
    sfRenderWindow_clear(settings->set_w->window, sfBlack);
    sfRenderWindow_drawSprite(settings->set_w->window, \
    settings->set_w->sprite, NULL);
}