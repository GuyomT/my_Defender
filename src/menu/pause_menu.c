/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** pause_menu
*/

#include "defender.h"

pause_t *init_texture_pause_menu(pause_t *pause_menu, char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2u texture_size;

    pause_menu->menu = sfRectangleShape_create();
    pause_menu->texture = sfTexture_createFromFile(filepath, NULL);
    texture_size = sfTexture_getSize(pause_menu->texture);
    size.x = texture_size.x * 1.25;
    size.y = texture_size.y * 1.25;
    pos.x = (1920 - (texture_size.x * 1.25)) / 2 - 220;
    pos.y = (1080 - (texture_size.y * 1.25)) / 2;
    sfRectangleShape_setSize(pause_menu->menu, size);
    sfRectangleShape_setTexture(pause_menu->menu, pause_menu->texture, sfTrue);
    sfRectangleShape_setPosition(pause_menu->menu, pos);
    return pause_menu;
}

button_t *init_quit_button(button_t *button, char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2u texture_size;
    button->texture = sfTexture_createFromFile(filepath, NULL);
    texture_size = sfTexture_getSize(button->texture);
    size.x = texture_size.x * 1.2;
    size.y = texture_size.y * 1.2;
    pos.x = (1920 - (texture_size.x * 1.2)) / 2 - 210;
    pos.y = (1080 - (texture_size.y * 1.2)) / 2 + 250;
    button = init_button(button, size, pos);
    button->ptr = &close_start_window;
    button->sound = NULL;
    return button;
}

button_t *init_resume_button(button_t *button, char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2u texture_size;
    button->texture = sfTexture_createFromFile(filepath, NULL);
    texture_size = sfTexture_getSize(button->texture);
    size.x = texture_size.x * 1.2;
    size.y = texture_size.y * 1.2;
    pos.x = (1920 - (texture_size.x * 1.2)) / 2 - 350;
    pos.y = (1080 - (texture_size.y * 1.2)) / 2;
    button = init_button(button, size, pos);
    button->ptr = &resume;
    button->sound = NULL;
    return button;
}

button_t *init_main_menu_button(button_t *button, char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2u texture_size;
    button->texture = sfTexture_createFromFile(filepath, NULL);
    texture_size = sfTexture_getSize(button->texture);
    size.x = texture_size.x * 1.2;
    size.y = texture_size.y * 1.2;
    pos.x = (1920 - (texture_size.x * 1.2)) / 2 - 50;
    pos.y = (1080 - (texture_size.y * 1.2)) / 2 - 5;
    button = init_button(button, size, pos);
    button->ptr = &main_menu;
    button->sound = NULL;
    return button;
}

pause_t *init_pause_menu(pause_t *pause_menu)
{
    pause_menu = malloc(sizeof(pause_t));
    if (!pause_menu)
        return NULL;
    pause_menu = init_texture_pause_menu(pause_menu, \
    "include/data/pause_menu.png");
    if (!(pause_menu->quit = malloc(sizeof(button_t))))
        return NULL;
    pause_menu->quit = init_quit_button(pause_menu->quit, \
    "include/data/quit_button.png");
    if (!(pause_menu->resume = malloc(sizeof(button_t))))
        return NULL;
    pause_menu->resume = init_resume_button(pause_menu->resume, \
    "include/data/resume_button.png");
    if (!(pause_menu->main_menu = malloc(sizeof(button_t))))
        return NULL;
    pause_menu->main_menu = init_main_menu_button(pause_menu->main_menu, \
    "include/data/main_menu_button.png");
    return pause_menu;
}