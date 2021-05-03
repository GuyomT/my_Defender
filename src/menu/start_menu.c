/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** start_menu
*/

#include "defender.h"

start_menu_t *create_title(start_menu_t *start, char *filepath)
{
    sfVector2f size;
    sfVector2u texture_size;
    sfVector2f pos;
    start->texture = sfTexture_createFromFile(filepath, NULL);
    texture_size = sfTexture_getSize(start->texture);
    size.x = texture_size.x * 1.0;
    size.y = texture_size.y * 1.0;
    start->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(start->rect, size);
    sfRectangleShape_setTexture(start->rect, start->texture, sfTrue);
    pos.x = (1920 - texture_size.x) / 2;
    pos.y = 50.0;
    sfRectangleShape_setPosition(start->rect, pos);
    return start;
}

start_menu_t *load_music(start_menu_t *start, char *filepath)
{
    start->music = sfMusic_createFromFile(filepath);
    sfMusic_setVolume(start->music, 20.0);
    sfMusic_setLoop(start->music, sfTrue);
    return start;
}

start_menu_t *init_start_menu(start_menu_t *start)
{
    start = malloc(sizeof(start_menu_t));
    if (!start)
        return NULL;
    start->start_button = malloc(sizeof(button_t));
    if (!start->start_button)
        return NULL;
    start->start_button = create_start_button(start->start_button, \
    "include/data/st_button.png");
    start->quit_button = malloc(sizeof(button_t));
    if (!start->quit_button)
        return NULL;
    start->quit_button = create_quit_button(start->quit_button, \
    "include/data/quit_button.png");
    if (!(start->how_button = malloc(sizeof(button_t))))
        return NULL;
    start->how_button = create_help_button(start->how_button, \
    "include/data/help_button.png");
    start = create_title(start, "include/data/title.png");
    start = load_music(start, "include/data/loop_music.ogg");
    return start;
}