/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** button_start_menu
*/

#include "defender.h"

button_t *create_quit_button(button_t *button, char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2u texture_size;
    button->texture = sfTexture_createFromFile(filepath, NULL);
    texture_size = sfTexture_getSize(button->texture);
    size.x = texture_size.x * 1.5;
    size.y = texture_size.y * 1.5;
    pos.x = (1920 - (texture_size.x * 1.5)) / 2;
    pos.y = (1080 - (texture_size.y * 1.5)) / 2 + 400;
    button = init_button(button, size, pos);
    button->ptr = &close_start_window;
    button->sound = NULL;
    return (button);
}

button_t *create_start_button(button_t *button, char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2u texture_size;
    button->texture = sfTexture_createFromFile(filepath, NULL);
    texture_size = sfTexture_getSize(button->texture);
    size.x = texture_size.x * 2.0;
    size.y = texture_size.y * 2.0;
    pos.x = (1920 - (texture_size.x * 2.0)) / 2;
    pos.y = (1080 - (texture_size.y * 2.0)) / 2;
    button = init_button(button, size, pos);
    button->ptr = &get_ingame;
    button->sound = sfMusic_createFromFile("include/data/button_sound.ogg");
    sfMusic_setVolume(button->sound, 20.0);
    return (button);
}

button_t *create_help_button(button_t *button, char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2u texture_size;
    button->texture = sfTexture_createFromFile(filepath, NULL);
    texture_size = sfTexture_getSize(button->texture);
    size.x = texture_size.x * 2.0;
    size.y = texture_size.y * 2.0;
    pos.x = (1920 - (texture_size.x * 2.0)) / 2;
    pos.y = (1080 - (texture_size.y * 2.0)) / 2 + 200;
    button = init_button(button, size, pos);
    button->ptr = &get_in_help_menu;
    return button;
}