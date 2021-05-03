/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** free_obj_button
*/

#include "defender.h"

void free_game_object(GameObject_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    sfClock_destroy(obj->clock);
    free(obj->paths);
    free(obj);
}

void free_button(button_t *button)
{
    sfRectangleShape_destroy(button->shape);
    sfTexture_destroy(button->texture);
    if (button->sound)
        sfMusic_destroy(button->sound);
    free(button);
}