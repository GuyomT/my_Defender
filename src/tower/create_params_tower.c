/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** create_params_tower
*/

#include "defender.h"

tower_t *create_params_tower(tower_t *tower, int type, int damage, \
char *filepath)
{
    tower->texture = sfTexture_createFromFile(filepath, NULL);
    tower->tower_type = type;
    tower->created = true;
    tower->dammage = damage;
    tower->clock = sfClock_create();
    return tower;
}

tower_t *create_rect_shape(tower_t *tower, sfVector2u size, sfVector2f pos)
{
    sfRectangleShape_setSize(tower->shape, \
    (sfVector2f){size.x * 0.6, size.y * 0.6});
    sfRectangleShape_setTexture(tower->shape, tower->texture, sfTrue);
    sfRectangleShape_setPosition(tower->shape, pos);
    return (tower);
}

tower_t *create_range(tower_t *tower, sfVector2f pos)
{
    sfCircleShape_setFillColor(tower->range, sfTransparent);
    sfCircleShape_setOutlineThickness(tower->range, 1);
    sfCircleShape_setRadius(tower->range, tower->radius);
    sfCircleShape_setOutlineColor(tower->range, sfBlack);
    sfCircleShape_setPosition(tower->range, pos);
    return tower;
}