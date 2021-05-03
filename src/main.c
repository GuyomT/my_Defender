/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-nathan.rousseau
** File description:
** main
*/

#include "defender.h"

int main(void)
{
    game_t *settings = NULL;

    settings = prep_struct_for_game(settings);
    if (!settings)
        return ERROR;
    open_window(settings);
    return (EXIT_SUCCESS);
}