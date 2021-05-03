/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** button
*/

#include "defender.h"

button_t *init_button(button_t *button, sfVector2f size, sfVector2f pos)
{
    button->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(button->shape, size);
    sfRectangleShape_setPosition(button->shape, pos);
    sfRectangleShape_setTexture(button->shape, button->texture, sfTrue);
    button->size = size;
    button->pos = pos;
    return (button);
}

button_t *init_pause_button(button_t *pause_button, char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2u texture_size;
    pause_button->texture = sfTexture_createFromFile(filepath, NULL);
    texture_size = sfTexture_getSize(pause_button->texture);
    size.x = texture_size.x * 2.0;
    size.y = texture_size.y * 2.0;
    pos.x = 1400.0;
    pos.y = 40.0;
    pause_button = init_button(pause_button, size, pos);
    pause_button->ptr = &pause;
    pause_button->sound = sfMusic_createFromFile("include/data/btn_pause.ogg");
    sfMusic_setVolume(pause_button->sound, 30.0);
    return pause_button;
}