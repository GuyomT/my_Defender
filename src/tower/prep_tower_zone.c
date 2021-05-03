/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** prep_tower_zone
*/

#include "defender.h"

sfRectangleShape *prepare_tower(sfRectangleShape *tower, sfVector2f pos, \
sfVector2f size)
{
    sfRectangleShape_setPosition(tower, pos);
    sfRectangleShape_setSize(tower, size);
    sfRectangleShape_setOutlineColor(tower, sfGreen);
    sfRectangleShape_setOutlineThickness(tower, 2.0);
    sfRectangleShape_setFillColor(tower, sfTransparent);
    return tower;
}

sfRectangleShape **prep_towers_zone2(sfRectangleShape **tower_place)
{
    tower_place[0] = prepare_tower(tower_place[0], (sfVector2f){458, 350}, \
    (sfVector2f){128, 78});
    tower_place[1] = prepare_tower(tower_place[1], (sfVector2f){317, 400}, \
    (sfVector2f){128, 78});
    tower_place[2] = prepare_tower(tower_place[2], (sfVector2f){485, 615}, \
    (sfVector2f){128, 78});
    tower_place[3] = prepare_tower(tower_place[3], (sfVector2f){475, 740}, \
    (sfVector2f){128, 78});
    tower_place[4] = prepare_tower(tower_place[4], (sfVector2f){640, 738}, \
    (sfVector2f){128, 78});
    tower_place[5] = prepare_tower(tower_place[5], (sfVector2f){778, 951}, \
    (sfVector2f){128, 78});
    return tower_place;
}

sfRectangleShape **prep_towers_zone(sfRectangleShape **tower_place)
{
    tower_place[6] = prepare_tower(tower_place[6], (sfVector2f){941, 768}, \
    (sfVector2f){128, 78});
    tower_place[7] = prepare_tower(tower_place[7], (sfVector2f){1205, 900}, \
    (sfVector2f){128, 78});
    tower_place[8] = prepare_tower(tower_place[8], (sfVector2f){1545, 20}, \
    (sfVector2f){150, 280});
    tower_place[9] = prepare_tower(tower_place[9], (sfVector2f){1550, 320}, \
    (sfVector2f){135, 230});
    tower_place[10] = prepare_tower(tower_place[10], (sfVector2f){1555, 580}, \
    (sfVector2f){135, 200});
    tower_place[11] = prepare_tower(tower_place[11], (sfVector2f){1560, 810}, \
    (sfVector2f){140, 210});
    tower_place = prep_towers_zone2(tower_place);
    return tower_place;
}