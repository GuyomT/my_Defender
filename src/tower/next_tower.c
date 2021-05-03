/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** next_tower
*/

#include "defender.h"

int next_tower(tower_t **tower)
{
    int i = 0;
    while (tower[i]->created == true) {
        i++;
    }
    return i;
}