/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** original_state_button
*/

#include "defender.h"

void original_button_state_start_menu(start_menu_t *start, game_t *settings)
{
    sfVector2i mouse_pos;
    mouse_pos = sfMouse_getPositionRenderWindow(settings->set_w->window);
    if (check_if_over_button(start->start_button, mouse_pos) == true) {
        sfRectangleShape_setScale(start->start_button->shape, \
        (sfVector2f){1.10, 1.10});
    } else {
        original_state_start_button(start->start_button);
    }
    if (check_if_over_button(start->quit_button, mouse_pos) == true) {
        sfRectangleShape_setScale(start->quit_button->shape, \
        (sfVector2f){1.20, 1.20});
    } else {
        original_state_quit_button(start->quit_button);
    }
    if (check_if_over_button(start->how_button, mouse_pos) == true) {
        sfRectangleShape_setScale(start->how_button->shape, \
        (sfVector2f){1.10, 1.10});
    } else {
        original_state_how_button(start->how_button);
    }
}

void original_pause_button(button_t *pause_button, game_t *settings)
{
    sfVector2i mouse_pos;
    sfVector2f scale;
    sfVector2f pos;
    mouse_pos = sfMouse_getPositionRenderWindow(settings->set_w->window);
    if (check_if_over_button(pause_button, mouse_pos) == true) {
        sfRectangleShape_setScale(pause_button->shape, \
        (sfVector2f){1.20, 1.20});
    } else {
        scale = sfRectangleShape_getScale(pause_button->shape);
        if (scale.x != 1.0 || scale.y != 1.0) {
            sfRectangleShape_setScale(pause_button->shape, \
            (sfVector2f){1.0, 1.0});
            pos.x = 1400;
            pos.y = 40.0;
            sfRectangleShape_setPosition(pause_button->shape, pos);
        }
    }
}

void original_button_state_pause_menu(pause_t *pause_menu, game_t *settings)
{
    original_button_state_quit_button(pause_menu, settings);
    original_button_state_resume_button(pause_menu, settings);
    original_button_state_main_menu_button(pause_menu, settings);
}

void original_button_go_back(how_t *how_menu, game_t *settings)
{
    sfVector2i mouse_pos;
    sfVector2f scale;
    sfVector2f pos;
    mouse_pos = sfMouse_getPositionRenderWindow(settings->set_w->window);
    if (check_if_over_button(how_menu->menu, mouse_pos) == true) {
        sfRectangleShape_setScale(how_menu->menu->shape, \
        (sfVector2f){1.20, 1.20});
    } else {
        scale = sfRectangleShape_getScale(how_menu->menu->shape);
        if (scale.x != 1.0 || scale.y != 1.0) {
            sfRectangleShape_setScale(how_menu->menu->shape, \
            (sfVector2f){1.0, 1.0});
            pos.x = 0;
            pos.y = 800;
            sfRectangleShape_setPosition(how_menu->menu->shape, pos);
        }
    }
}

void original_state(game_t *settings)
{
    if (settings->start_menu == true) {
        original_button_state_start_menu(settings->start, settings);
    }
    else if (settings->game == true) {
        original_pause_button(settings->play->pause_button, settings);
    }
    else if (settings->pause == true) {
        original_button_state_pause_menu(settings->pause_menu, settings);
    }
    else if (settings->how_to_play == true) {
        original_button_go_back(settings->how_menu, settings);
    }
}