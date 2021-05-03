/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** button_functions_two
*/

#include "defender.h"

void get_in_help_menu(game_t *settings)
{
    sfMusic_stop(settings->start->music);
    sfSprite_destroy(settings->set_w->sprite);
    sfTexture_destroy(settings->set_w->texture);
    settings->set_w->texture = \
    sfTexture_createFromFile("include/data/how_to_play.png", NULL);
    settings->set_w->sprite = sfSprite_create();
    sfSprite_setTexture(settings->set_w->sprite, \
    settings->set_w->texture, sfTrue);
    sfSprite_setScale(settings->set_w->sprite, (sfVector2f){2.2, 2.2});
    settings->start_menu = false;
    settings->how_to_play = true;
}

void go_back_main_menu(game_t *settings)
{
    sfSprite_destroy(settings->set_w->sprite);
    sfTexture_destroy(settings->set_w->texture);
    sfTexture_createFromFile("include/data/bg.png", NULL);
    settings->set_w->sprite = sfSprite_create();
    sfSprite_setTexture(settings->set_w->sprite, \
    settings->set_w->texture, sfTrue);
    settings->start_menu = true;
    settings->how_to_play = false;
    sfMusic_play(settings->start->music);
}