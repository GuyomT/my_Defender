/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-nathan.rousseau
** File description:
** display_tower
*/

#include "defender.h"

void display_tower_zone(game_t *settings)
{
    for (int i = 0; i < 12; i++) {
        sfRenderWindow_drawRectangleShape(settings->set_w->window, \
        settings->play->tower_place[i], NULL);
    }
    for (int i = 0; i < 8; i++) {
        if (settings->play->tower[i]->created == true) {
            sfRenderWindow_drawRectangleShape(settings->set_w->window, \
            settings->play->tower[i]->shape, NULL);
            sfRenderWindow_drawCircleShape(settings->set_w->window, \
            settings->play->tower[i]->range, NULL);
        }
    }
}