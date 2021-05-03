/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-nathan.rousseau
** File description:
** waves
*/

#include "defender.h"

waves_t *create_waves(waves_t *waves)
{
    if (!(waves = malloc(sizeof(waves_t))))
        return NULL;
    waves->font = sfFont_createFromFile("include/data/arial.ttf");
    waves->pos.x = 230;
    waves->pos.y = 77;
    waves->text = sfText_create();
    waves->wave = 1;
    sfText_setString(waves->text, int_to_str(waves->wave));
    sfText_setFont(waves->text, waves->font);
    sfText_setCharacterSize(waves->text, 38);
    sfText_setPosition(waves->text, waves->pos);
    sfText_setColor(waves->text, sfWhite);
    return waves;
}

bool all_entities_dead(game_menu_t *play, int *nbr_mobs)
{
    int golem_dead = 0;
    int dino_dead = 0;
    int wolf_dead = 0;
    for (int i = 0; play->golem[i]; i++) {
        if (play->golem[i]->is_destroy == true)
            golem_dead++;
    }
    for (int i = 0; play->wolf[i]; i++) {
        if (play->wolf[i]->is_destroy == true)
            wolf_dead++;
    }
    for (int i = 0; play->wolf[i]; i++) {
        if (play->dino[i]->is_destroy == true)
            dino_dead++;
    }
    if (golem_dead == nbr_mobs[0] && wolf_dead == nbr_mobs[1] && \
        dino_dead == nbr_mobs[2])
        return true;
    return false;
}

game_menu_t *next_wave(game_menu_t *play)
{
    if (all_entities_dead(play, play->waves[play->wave->wave -1]) == true) {
        for (int i = 0; play->golem[i]; i++)
            free_game_object(play->golem[i]);
        for (int i = 0; play->wolf[i]; i++)
            free_game_object(play->wolf[i]);
        for (int i = 0; play->dino[i]; i++)
            free_game_object(play->dino[i]);
        sfClock_destroy(play->clock_golem);
        sfClock_destroy(play->clock_wolf);
        sfClock_destroy(play->clock_dino);
        play->wave->wave++;
        play->golem = init_golem(play->golem, \
        play->waves[play->wave->wave - 1][0]);
        play->wolf = init_wolf(play->wolf, \
        play->waves[play->wave->wave - 1][1]);
        play->dino = init_dino(play->dino, \
        play->waves[play->wave->wave - 1][2]);
    } return play;
}