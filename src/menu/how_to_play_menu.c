/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** how_to_play_menu
*/

#include "defender.h"

button_t *init_go_back_button(button_t *button, char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2u texture_size;
    button->texture = sfTexture_createFromFile(filepath, NULL);
    texture_size = sfTexture_getSize(button->texture);
    size.x = texture_size.x * 2.0;
    size.y = texture_size.y * 2.0;
    pos.x = 0;
    pos.y = 850;
    button = init_button(button, size, pos);
    button->ptr = &go_back_main_menu;
    return button;
}

how_t *init_help_menu(how_t *how_menu)
{
    how_menu = malloc(sizeof(how_t));
    if (!how_menu)
        return NULL;
    how_menu->menu = malloc(sizeof(button_t));
    if (!how_menu->menu)
        return NULL;
    how_menu->menu = init_go_back_button(how_menu->menu, \
    "include/data/main_menu_button.png");
    return how_menu;
}