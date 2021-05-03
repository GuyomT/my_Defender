/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** original_state_button_start_menu
*/

#include "defender.h"

void original_state_start_button(button_t *start_button)
{
    sfVector2f scale = sfRectangleShape_getScale(start_button->shape);
    sfVector2f pos = sfRectangleShape_getPosition(start_button->shape);
    sfVector2u texture_size = sfTexture_getSize(start_button->texture);
    if (scale.x != 1.0 || scale.y != 1.0) {
        sfRectangleShape_setScale(start_button->shape, \
        (sfVector2f){1.0, 1.0});
        pos.x = (1920 - (texture_size.x * 2.0)) / 2;
        pos.y = (1080 - (texture_size.y * 2.0)) / 2;
        sfRectangleShape_setPosition(start_button->shape, pos);
    }
}

void original_state_quit_button(button_t *quit_button)
{
    sfVector2f scale = sfRectangleShape_getScale(quit_button->shape);
    sfVector2f pos = sfRectangleShape_getPosition(quit_button->shape);
    sfVector2u texture_size = sfTexture_getSize(quit_button->texture);
    if (scale.x != 1.0 || scale.y != 1.0) {
        sfRectangleShape_setScale(quit_button->shape, \
        (sfVector2f){1.0, 1.0});
        pos.x = (1920 - (texture_size.x * 1.5)) / 2;
        pos.y = ((1080 - texture_size.y * 1.5)) / 2 + 400;
        sfRectangleShape_setPosition(quit_button->shape, pos);
    }
}

void original_state_how_button(button_t *how_button)
{
    sfVector2f scale = sfRectangleShape_getScale(how_button->shape);
    sfVector2f pos = sfRectangleShape_getPosition(how_button->shape);
    sfVector2u texture_size = sfTexture_getSize(how_button->texture);
    if (scale.x != 1.0 || scale.y != 1.0) {
        sfRectangleShape_setScale(how_button->shape, \
        (sfVector2f){1.0, 1.0});
        pos.x = (1920 - (texture_size.x * 1.5)) / 2;
        pos.y = ((1080 - texture_size.y * 1.5)) / 2 + 200;
        sfRectangleShape_setPosition(how_button->shape, pos);
    }
}