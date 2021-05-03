/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** display_pause_menu
*/

#include "defender.h"

void display_pause_menu_quit_button(game_t *settings)
{
    sfRenderWindow_drawRectangleShape(settings->set_w->window, \
    settings->pause_menu->quit->shape, NULL);
}

void display_pause_menu_resume_button(game_t *settings)
{
    sfRenderWindow_drawRectangleShape(settings->set_w->window, \
    settings->pause_menu->resume->shape, NULL);
}

void display_pause_menu_texture(game_t *settings)
{
    sfRenderWindow_drawRectangleShape(settings->set_w->window, \
    settings->pause_menu->menu, NULL);
}

void display_pause_menu_main_menu_button(game_t *settings)
{
    sfRenderWindow_drawRectangleShape(settings->set_w->window, \
    settings->pause_menu->main_menu->shape, NULL);
}

void display_pause_menu(game_t *settings)
{
    display_pause_menu_texture(settings);
    display_pause_menu_quit_button(settings);
    display_pause_menu_resume_button(settings);
    display_pause_menu_main_menu_button(settings);
}