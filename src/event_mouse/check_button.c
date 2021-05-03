/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** check_button
*/

#include "defender.h"

bool check_if_over_button(button_t *button, sfVector2i mouse_pos)
{
    if (mouse_pos.x > button->pos.x && \
    mouse_pos.x < (button->pos.x + button->size.x) && \
    mouse_pos.y > button->pos.y && \
    mouse_pos.y < (button->pos.y + button->size.y)) {
        return (true);
    }
    return (false);
}

bool check_button_quit(button_t *quit_button, sfVector2i mouse_pos)
{
    if (check_if_over_button(quit_button, mouse_pos) == true)
        return true;
    return (false);
}

bool check_button_play(button_t *start_button, sfVector2i mouse_pos)
{
    if (check_if_over_button(start_button, mouse_pos) == true)
        return true;
    return (false);
}