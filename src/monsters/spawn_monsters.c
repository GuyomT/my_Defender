/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** spawn_monsters
*/

#include "defender.h"

game_menu_t *make_dino_alive(game_menu_t *play)
{
    int laps = 2;
    int i = 0;
    sfTime elapsed_time = sfClock_getElapsedTime(play->clock_dino);
    float time = (sfTime_asMilliseconds(elapsed_time) / 1000);
    if (time > (float)laps) {
        while (play->dino[i] && play->dino[i]->has_spawned == true) {
            i++;
        }
        if (play->dino[i])
            play->dino[i]->has_spawned = true;
        sfClock_restart(play->clock_dino);
    }
    return play;
}

game_menu_t *make_golem_alive(game_menu_t *play)
{
    int laps = 5;
    int i = 0;
    sfTime elapsed_time = sfClock_getElapsedTime(play->clock_golem);
    float time = (sfTime_asMilliseconds(elapsed_time) / 1000);
    if (time > (float)laps) {
        while (play->golem[i] && play->golem[i]->has_spawned == true) {
            i++;
        }
        if (play->golem[i])
            play->golem[i]->has_spawned = true;
        sfClock_restart(play->clock_golem);
    }
    return play;
}

game_menu_t *make_wolf_alive(game_menu_t *play)
{
    int laps = 3;
    int i = 0;
    sfTime elapsed_time = sfClock_getElapsedTime(play->clock_wolf);
    float time = (sfTime_asMilliseconds(elapsed_time) / 1000);
    if (time > (float)laps) {
        while (play->wolf[i] && play->wolf[i]->has_spawned == true) {
            i++;
        }
        if (play->wolf[i]) {
            play->wolf[i]->has_spawned = true;
        }
        sfClock_restart(play->clock_wolf);
    }
    return play;
}