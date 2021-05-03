/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** is_in_rectangle
*/

#include "defender.h"

bool click_on_rectangle(sfRectangleShape *tower_place, sfVector2i mouse_pos)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(tower_place);
    sfVector2f size = sfRectangleShape_getSize(tower_place);

    if (mouse_pos.x > rect_pos.x &&
        mouse_pos.x < (rect_pos.x + size.x) &&
        mouse_pos.y > rect_pos.y &&
        mouse_pos.y < (rect_pos.y + size.y))
        return true;
    return false;
}

game_menu_t *is_click_for_tower(game_menu_t *play, sfVector2i mouse_pos, \
game_t *settings)
{
    int i = 0;
    while (i < 12) {
        if (click_on_rectangle(play->tower_place[i], mouse_pos) == true)
            break;
        i++;
    }
    if (i < 8 && play->tower_value != 0) {
        play = create_tower(play, i, settings);
    }
    else if (i > 7 && i != 12) {
        play = select_tower(play, i);
    }
    else if (i == 12 && play->tower_value != 0) {
        play = warning_wrong_zone(play, settings);
    } else {
        play = outline_unselected(play);
    }
    return play;
}