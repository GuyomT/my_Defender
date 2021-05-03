/*
** EPITECH PROJECT, 2021
** my_defender_final
** File description:
** take_dammage
*/

#include "defender.h"

GameObject_t *lower_speed(GameObject_t *obj)
{
    if (obj->obj_speed.x > 9 && obj->obj_speed.y > 9) {
        obj->obj_speed.x /= 2;
        obj->obj_speed.y /= 2;
    }
    return obj;
}

bool take_dammage(tower_t *tower, GameObject_t *obj)
{
    sfVector2f pos_twr = sfCircleShape_getPosition(tower->range);
    sfVector2f pos_obj = sfSprite_getPosition(obj->sprite);
    sfTime elapsed_time = sfClock_getElapsedTime(tower->clock);
    float time = sfTime_asMilliseconds(elapsed_time);
    double a;
    double d;
    pos_twr.x += tower->radius;
    pos_twr.y += tower->radius;
    a = pos_twr.x - pos_obj.x;
    d = pos_twr.y - pos_obj.y;
    if (sqrt(pow(a, 2) + pow(d, 2)) < (double)tower->radius) {
        if (time > tower->shoot_speed && tower->tower_type == FREEZE_T) {
            obj = lower_speed(obj);
            sfClock_restart(tower->clock);
            return true;
        } else if (time > tower->shoot_speed) {
            sfClock_restart(tower->clock);
            return true;
        }
    } return false;
}