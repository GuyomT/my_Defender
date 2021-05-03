/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** texts
*/

#include "defender.h"

game_menu_t *init_texts(game_menu_t *play)
{
    if (!(play->money = create_money(play->money)))
        return NULL;
    if (!(play->life = create_life(play->life)))
        return NULL;
    if (!(play->wave = create_waves(play->wave)))
        return NULL;
    return play;
}