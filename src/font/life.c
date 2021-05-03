/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** life
*/

#include "defender.h"

life_t *create_life(life_t *life)
{
    if (!(life = malloc(sizeof(life_t))))
        return NULL;
    life->font = sfFont_createFromFile("include/data/arial.ttf");
    life->pos.x = 110;
    life->pos.y = 30;
    life->text = sfText_create();
    life->life = 500;
    sfText_setString(life->text, int_to_str(life->life));
    sfText_setFont(life->text, life->font);
    sfText_setCharacterSize(life->text, 40);
    sfText_setPosition(life->text, life->pos);
    sfText_setColor(life->text, sfWhite);
    return life;
}