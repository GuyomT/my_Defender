/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** check_clicks
*/

#include "defender.h"

bool all_tower_are_created(tower_t **tower)
{
    int nb_tower = 0;
    for (int i = 0; i < 8; i++) {
        if (tower[i]->created == true) {
            nb_tower++;
        }
    }
    if (nb_tower == 8)
        return true;
    return false;
}

void check_released_events(game_t *settings)
{
    sfVector2i mouse_pos;
    mouse_pos = sfMouse_getPositionRenderWindow(settings->set_w->window);
    if (settings->start_menu == true) {
        check_released_start_menu_button(settings->start, settings, mouse_pos);
    }
    else if (settings->game == true) {
        check_released_pause_button(settings->play->pause_button, \
        settings, mouse_pos);
    }
    else if (settings->pause == true) {
        check_released_pause_menu_button(settings->pause_menu, \
        settings, mouse_pos);
    }
    else if (settings->how_to_play == true) {
        check_released_go_back_button(settings->how_menu, settings, mouse_pos);
    }
}

void check_click_events(game_t *settings)
{
    sfVector2i m_pos;
    m_pos = sfMouse_getPositionRenderWindow(settings->set_w->window);
    if (settings->start_menu == true) {
        check_clicked_start_menu_button(settings->start, m_pos);
    }
    else if (settings->game == true) {
        check_click_pause_button(settings->play->pause_button, m_pos);
        if (all_tower_are_created(settings->play->tower) == false) {
            settings->play = is_click_for_tower(settings->play, m_pos, \
            settings);
        } else {
            settings->play = outline_unselected(settings->play);
        }
    }
    else if (settings->pause == true) {
        check_click_pause_menu_button(settings->pause_menu, m_pos);
    }
    else if (settings->how_to_play == true) {
        check_click_go_back_button(settings->how_menu, m_pos);
    }
}