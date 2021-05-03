/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** original_state_button_pause_menu
*/

#include "defender.h"

void original_button_state_quit_button(pause_t *pause_menu, game_t *settings)
{
    sfVector2i mouse_pos;
    sfVector2f scale;
    mouse_pos = sfMouse_getPositionRenderWindow(settings->set_w->window);
    if (check_button_quit(pause_menu->quit, mouse_pos) == true) {
        sfRectangleShape_setScale(pause_menu->quit->shape, \
        (sfVector2f){1.20, 1.20});
    } else {
        scale = sfRectangleShape_getScale(pause_menu->quit->shape);
        if (scale.x != 1.0 || scale.y != 1.0) {
            sfRectangleShape_setScale(pause_menu->quit->shape, \
            (sfVector2f){1.0, 1.0});
        }
    }
}

void original_button_state_resume_button(pause_t *pause_menu, game_t *settings)
{
    sfVector2i mouse_pos;
    sfVector2f scale;
    mouse_pos = sfMouse_getPositionRenderWindow(settings->set_w->window);
    if (check_button_quit(pause_menu->resume, mouse_pos) == true) {
        sfRectangleShape_setScale(pause_menu->resume->shape, \
        (sfVector2f){1.20, 1.20});
    } else {
        scale = sfRectangleShape_getScale(pause_menu->resume->shape);
        if (scale.x != 1.0 || scale.y != 1.0) {
            sfRectangleShape_setScale(pause_menu->resume->shape, \
            (sfVector2f){1.0, 1.0});
        }
    }
}

void original_button_state_main_menu_button(pause_t *pause_menu, \
game_t *settings)
{
    sfVector2i mouse_pos;
    sfVector2f scale;
    mouse_pos = sfMouse_getPositionRenderWindow(settings->set_w->window);
    if (check_button_quit(pause_menu->main_menu, mouse_pos) == true) {
        sfRectangleShape_setScale(pause_menu->main_menu->shape, \
        (sfVector2f){1.20, 1.20});
    } else {
        scale = sfRectangleShape_getScale(pause_menu->main_menu->shape);
        if (scale.x != 1.0 || scale.y != 1.0) {
            sfRectangleShape_setScale(pause_menu->main_menu->shape, \
            (sfVector2f){1.0, 1.0});
        }
    }
}