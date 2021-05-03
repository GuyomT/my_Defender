/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** money
*/

#include "defender.h"

money_t *create_money(money_t *money)
{
    if (!(money = malloc(sizeof(money_t))))
        return NULL;
    money->font = sfFont_createFromFile("include/data/arial.ttf");
    money->pos.x = 230;
    money->pos.y = 30;
    money->text = sfText_create();
    money->moula = 300;
    sfText_setString(money->text, int_to_str(money->moula));
    sfText_setFont(money->text, money->font);
    sfText_setCharacterSize(money->text, 40);
    sfText_setPosition(money->text, money->pos);
    sfText_setColor(money->text, sfWhite);
    return money;
}