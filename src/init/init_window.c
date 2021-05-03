/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-nathan.rousseau
** File description:
** init_background
*/

#include "defender.h"

void setup_window_struc(window_params_t *set_w)
{
    set_w->sprite = sfSprite_create();
    set_w->texture = sfTexture_createFromFile("include/data/bg.png", NULL);
    sfSprite_setTexture(set_w->sprite, set_w->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(set_w->window, 60);
}

window_params_t *create_window_struct(window_params_t *set_w)
{
    set_w = malloc(sizeof(window_params_t));
    if (!set_w)
        return NULL;
    set_w->mode.width = 1920;
    set_w->mode.height = 1080;
    set_w->mode.bitsPerPixel = 32;
    set_w->window = sfRenderWindow_create(set_w->mode, "TOWER", sfClose, NULL);
    setup_window_struc(set_w);
    return (set_w);
}