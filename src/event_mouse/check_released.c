/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** check_released_start_menu
*/

#include "defender.h"

void check_released_start_menu_button(start_menu_t *start, game_t *settings, \
sfVector2i mouse_pos)
{
    if (check_button_play(start->start_button, mouse_pos) == true) {
        start->start_button->ptr(settings);
    }
    if (check_button_quit(start->quit_button, mouse_pos) == true) {
        start->quit_button->ptr(settings);
    }
    if (check_if_over_button(start->how_button, mouse_pos) == true) {
        start->how_button->ptr(settings);
    }
}

void check_released_pause_button(button_t *pause_button, game_t *settings, \
sfVector2i mouse_pos)
{
    if (check_if_over_button(pause_button, mouse_pos) == true) {
        pause_button->ptr(settings);
    }
}

void check_released_pause_menu_button(pause_t *pause_menu, game_t *settings, \
sfVector2i mouse_pos)
{
    if (check_button_quit(pause_menu->quit, mouse_pos) == true) {
        pause_menu->quit->ptr(settings);
    }
    if (check_if_over_button(pause_menu->resume, mouse_pos) == true) {
        pause_menu->resume->ptr(settings);
    }
    if (check_if_over_button(pause_menu->main_menu, mouse_pos) == true) {
        pause_menu->main_menu->ptr(settings);
    }
}

void check_released_go_back_button(how_t *how_menu, game_t *settings, \
sfVector2i mouse_pos)
{
    if (check_if_over_button(how_menu->menu, mouse_pos) == true) {
        how_menu->menu->ptr(settings);
    }
}