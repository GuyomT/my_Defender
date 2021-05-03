/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** check_click_start_menu
*/

#include "defender.h"

void check_clicked_start_menu_button(start_menu_t *start, \
sfVector2i mouse_pos)
{
    if (check_button_play(start->start_button, mouse_pos) == true) {
        sfRectangleShape_setScale(start->start_button->shape, \
        (sfVector2f){0.75, 0.75});
    }
    if (check_button_quit(start->quit_button, mouse_pos) == true) {
        sfRectangleShape_setScale(start->quit_button->shape, \
        (sfVector2f){0.75, 0.75});
    }
    if (check_button_quit(start->how_button, mouse_pos) == true) {
        sfRectangleShape_setScale(start->how_button->shape, \
        (sfVector2f){0.75, 0.75});
    }
}

void check_click_pause_button(button_t *pause_button, sfVector2i mouse_pos)
{
    if (check_if_over_button(pause_button, mouse_pos) == true) {
        sfRectangleShape_setScale(pause_button->shape, \
        (sfVector2f){0.75, 0.75});
    }
}

void check_click_pause_menu_button(pause_t *pause_menu, sfVector2i mouse_pos)
{
    if (check_if_over_button(pause_menu->quit, mouse_pos) == true) {
        sfRectangleShape_setScale(pause_menu->quit->shape, \
        (sfVector2f){0.75, 0.75});
    }
    if (check_if_over_button(pause_menu->resume, mouse_pos) == true) {
        sfRectangleShape_setScale(pause_menu->resume->shape, \
        (sfVector2f){0.75, 0.75});
    }
    if (check_if_over_button(pause_menu->main_menu, mouse_pos) == true) {
        sfRectangleShape_setScale(pause_menu->main_menu->shape, \
        (sfVector2f){0.75, 0.75});
    }
}

void check_click_go_back_button(how_t *how_menu, sfVector2i mouse_pos)
{
    if (check_if_over_button(how_menu->menu, mouse_pos) == true) {
        sfRectangleShape_setScale(how_menu->menu->shape, \
        (sfVector2f){0.75, 0.75});
    }
}