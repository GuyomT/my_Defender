/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** free_struct
*/

#include "defender.h"

void free_start_menu(start_menu_t *start)
{
    free_button(start->start_button);
    free_button(start->quit_button);
    free_button(start->how_button);
    sfTexture_destroy(start->texture);
    sfRectangleShape_destroy(start->rect);
    sfMusic_destroy(start->music);
    free(start);
}

void free_game_menu(game_menu_t *play)
{
    free_button(play->pause_button);
    for (int i = 0; play->golem[i]; i++)
        free_game_object(play->golem[i]);
    for (int i = 0; play->golem[i]; i++)
        free_game_object(play->wolf[i]);
    for (int i = 0; play->golem[i]; i++)
        free_game_object(play->dino[i]);
    sfClock_destroy(play->clock_golem);
    sfClock_destroy(play->clock_wolf);
    sfClock_destroy(play->clock_dino);
    for (int i = 0; play->tower_place[i]; i++) {
        sfRectangleShape_destroy(play->tower_place[i]);
    }
    free(play->tower_place);
    sfText_destroy(play->money->text);
    sfFont_destroy(play->money->font);
    free(play->money);
    free(play);
}

void free_pause_menu(pause_t *pause)
{
    free_button(pause->resume);
    free_button(pause->main_menu);
    free_button(pause->quit);
    sfRectangleShape_destroy(pause->menu);
    sfTexture_destroy(pause->texture);
    free(pause);
}

void free_window(window_params_t *set_w)
{
    sfTexture_destroy(set_w->texture);
    sfSprite_destroy(set_w->sprite);
    sfRenderWindow_close(set_w->window);
    sfRenderWindow_destroy(set_w->window);
    free(set_w);
}