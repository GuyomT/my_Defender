/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init_tower
*/

#include "defender.h"

tower_t **init_tower(tower_t **tower)
{
    tower = malloc(sizeof(tower_t) * (9));
    if (!tower)
        return NULL;
    tower[8] = NULL;
    for (int i = 0; i < 8; i++) {
        tower[i] = malloc(sizeof(tower_t));
        if (!tower[i])
            return NULL;
        tower[i]->created = false;
        tower[i]->shape = sfRectangleShape_create();
        tower[i]->range = sfCircleShape_create();
    }
    return tower;
}