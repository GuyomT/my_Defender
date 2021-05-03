/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** draw_start_menu
*/

#include "defender.h"

void display_start_menu(game_t *settings)
{
    sfRenderWindow_drawRectangleShape(settings->set_w->window, \
    settings->start->start_button->shape, NULL);
    sfRenderWindow_drawRectangleShape(settings->set_w->window, \
    settings->start->how_button->shape, NULL);
    sfRenderWindow_drawRectangleShape(settings->set_w->window, \
    settings->start->quit_button->shape, NULL);
    sfRenderWindow_drawRectangleShape(settings->set_w->window, \
    settings->start->rect, NULL);
}