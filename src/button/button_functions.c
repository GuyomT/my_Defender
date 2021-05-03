/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** button_functions
*/

#include "defender.h"

void get_ingame(game_t *settings)
{
    sfMusic_stop(settings->start->music);
    sfSprite_destroy(settings->set_w->sprite);
    sfTexture_destroy(settings->set_w->texture);
    settings->set_w->texture = \
    sfTexture_createFromFile("include/data/map_game.png", NULL);
    settings->set_w->sprite = sfSprite_create();
    sfSprite_setTexture(settings->set_w->sprite, \
    settings->set_w->texture, sfTrue);
    sfSprite_setScale(settings->set_w->sprite, (sfVector2f){2.2, 2.2});
    settings->start_menu = false;
    settings->game = true;
    sfMusic_play(settings->start->start_button->sound);
}

void pause(game_t *settings)
{
    settings->game = false;
    settings->pause = true;
    sfMusic_play(settings->play->pause_button->sound);
}

void close_start_window(game_t *settings)
{
    if (settings->start_menu == true) {
        sfMusic_stop(settings->start->music);
    }
    settings->start_menu = false;
    settings->game = false;
    settings->pause = false;
}

void resume(game_t *settings)
{
    settings->pause = false;
    settings->game = true;
}

void main_menu(game_t *settings)
{
    settings->pause = false;
    settings->start_menu = true;
    sfMusic_play(settings->start->music);
    sfSprite_destroy(settings->set_w->sprite);
    sfTexture_destroy(settings->set_w->texture);
    settings->set_w->texture = \
    sfTexture_createFromFile("include/data/bg.png", NULL);
    settings->set_w->sprite = sfSprite_create();
    sfSprite_setTexture(settings->set_w->sprite, \
    settings->set_w->texture, sfTrue);
}