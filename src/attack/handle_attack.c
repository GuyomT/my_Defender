/*
** EPITECH PROJECT, 2021
** my_defender_final
** File description:
** handle_attack
*/

#include "defender.h"

game_menu_t *in_range_tower(GameObject_t *obj, game_menu_t *play)
{
    for (int i = 0; play->tower[i]; i++) {
        if (play->tower[i]->created == true && \
        take_dammage(play->tower[i], obj) == true) {
            obj->pv -= play->tower[i]->dammage;
        }
        if (obj->pv <= 0) {
            obj->is_destroy = true;
            play->money->moula += 2;
        }
    }
    return play;
}

game_menu_t *handle_attack_wolf(game_menu_t *play)
{
    for (int i = 0; play->wolf[i]; i++) {
        if (play->wolf[i]->has_spawned == true && \
        play->wolf[i]->is_destroy == false) {
            play = in_range_tower(play->wolf[i], play);
        }
    }
    return play;
}

game_menu_t *handle_attack_dino(game_menu_t *play)
{
    for (int i = 0; play->dino[i]; i++) {
        if (play->dino[i]->has_spawned == true && \
        play->dino[i]->is_destroy == false) {
            play = in_range_tower(play->dino[i], play);
        }
    }
    return play;
}

game_menu_t *handle_attack_golem(game_menu_t *play)
{
    for (int i = 0; play->golem[i]; i++) {
        if (play->golem[i]->has_spawned == true && \
        play->golem[i]->is_destroy == false) {
            play = in_range_tower(play->golem[i], play);
        }
    }
    return play;
}

game_menu_t *handle_attack(game_menu_t *play)
{
    play = handle_attack_golem(play);
    play = handle_attack_dino(play);
    play = handle_attack_wolf(play);
    play = next_wave(play);
    return play;
}