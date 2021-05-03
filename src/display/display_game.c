/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** display_game
*/

#include "defender.h"

void display_button(game_t *settings)
{
    sfRenderWindow_drawRectangleShape(settings->set_w->window, \
    settings->play->pause_button->shape, NULL);
}

void display_money(game_t *settings)
{
    if (settings->play->money->moula != \
    my_getnbr(sfText_getString(settings->play->money->text))) {
        sfText_setString(settings->play->money->text, \
        int_to_str(settings->play->money->moula));
    }
    sfRenderWindow_drawText(settings->set_w->window, \
    settings->play->money->text, NULL);
}

void display_life(game_t *settings)
{
    if (settings->play->life->life != \
    my_getnbr(sfText_getString(settings->play->life->text))) {
        sfText_setString(settings->play->life->text, \
        int_to_str(settings->play->life->life));
    }
    sfRenderWindow_drawText(settings->set_w->window, \
    settings->play->life->text, NULL);
}

void display_waves(game_t *settings)
{
    if (settings->play->wave->wave != \
    my_getnbr(sfText_getString(settings->play->wave->text))) {
        sfText_setString(settings->play->wave->text, \
        int_to_str(settings->play->wave->wave));
    }
    sfRenderWindow_drawText(settings->set_w->window, \
    settings->play->wave->text, NULL);
}

void display_game(game_t *settings)
{
    display_money(settings);
    display_life(settings);
    display_waves(settings);
    display_button(settings);
    display_tower_zone(settings);
    display_golem(settings);
    display_wolf(settings);
    display_dino(settings);
}