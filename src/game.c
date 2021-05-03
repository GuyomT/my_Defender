/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-nathan.rousseau
** File description:
** setup_window
*/

#include "defender.h"

bool closed_windows(game_t *settings)
{
    if (settings->start_menu == false && \
    settings->game == false && settings->pause == false && \
    settings->how_to_play == false) {
        return true;
    }
    if (settings->play->life->life <= 0) {
        return true;
    }
    return false;
}

int handle_events(game_t *settings)
{
    while (sfRenderWindow_pollEvent(settings->set_w->window, \
    &settings->set_w->event)) {
        if (settings->set_w->event.type == sfEvtClosed)
            return (-1);
        else if (sfKeyboard_isKeyPressed(sfKeyEscape) && \
            settings->game == true)
            pause(settings);
        else if (settings->set_w->event.type == sfEvtMouseButtonPressed)
            check_click_events(settings);
        else if (settings->set_w->event.type == sfEvtMouseButtonReleased)
            check_released_events(settings);
        else
            original_state(settings);
    }
    if (settings->game == true)
        settings->play = handle_attack(settings->play);
    if (closed_windows(settings) == true)
        return (-1);
    return (0);
}

void free_struct(game_t *settings)
{
    free_start_menu(settings->start);
    free_game_menu(settings->play);
    free_pause_menu(settings->pause_menu);
    free_window(settings->set_w);
    free(settings);
}

int open_window(game_t *settings)
{
    sfMusic_play(settings->start->music);
    while (sfRenderWindow_isOpen(settings->set_w->window)) {
        if (handle_events(settings) == -1) {
            break;
        }
        display_background(settings);
        if (settings->start_menu == true)
            display_start_menu(settings);
        else if (settings->how_to_play == true)
            display_how_to_play(settings);
        else if (settings->game == true)
            display_game(settings);
        else if (settings->pause == true)
            display_pause_menu(settings);
        sfRenderWindow_display(settings->set_w->window);
    }
    free_struct(settings);
    return EXIT_SUCCESS;
}