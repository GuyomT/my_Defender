/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** prep_game_struct
*/

#include "defender.h"

game_t *set_bool_menu(game_t *settings)
{
    settings->start_menu = true;
    settings->pause = false;
    settings->game = false;
    settings->how_to_play = false;
    return (settings);
}

game_t *prep_struct_for_game(game_t *settings)
{
    settings = malloc(sizeof(game_t));
    if (!settings)
        return NULL;
    settings->set_w = create_window_struct(settings->set_w);
    if (!settings->set_w)
        return NULL;
    settings->start = init_start_menu(settings->start);
    if (!settings->start)
        return NULL;
    settings->play = init_game_menu(settings->play);
    if (!settings->play)
        return NULL;
    settings->pause_menu = init_pause_menu(settings->pause_menu);
    if (!settings->pause_menu)
        return NULL;
    settings->how_menu = init_help_menu(settings->how_menu);
    if (!settings->how_menu)
        return NULL;
    settings = set_bool_menu(settings);
    return (settings);
}