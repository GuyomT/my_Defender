/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** display_monsters
*/

#include "defender.h"

bool is_at_castle(GameObject_t *monster, game_t *settings)
{
    sfVector2f pos = sfSprite_getPosition(monster->sprite);
    if (pos.x == 1440 && pos.y == 720) {
        if (monster->is_destroy == false) {
            monster->is_destroy = true;
            settings->play->life->life -= monster->pv;
        }
        return true;
    }
    return false;
}

void display_golem(game_t *settings)
{
    int i = 0;
    settings->play = make_golem_alive(settings->play);
    while (settings->play->golem[i]) {
        if (settings->play->golem[i]->has_spawned == true && \
        is_at_castle(settings->play->golem[i], settings) == false && \
        settings->play->golem[i]->is_destroy == false) {
            update_game_object(settings->play->golem[i]);
            sfRenderWindow_drawSprite(settings->set_w->window, \
            settings->play->golem[i]->sprite, NULL);
        }
        i++;
    }
}

void display_wolf(game_t *settings)
{
    int i = 0;
    settings->play = make_wolf_alive(settings->play);
    while (settings->play->wolf[i]) {
        if (settings->play->wolf[i]->has_spawned == true && \
        is_at_castle(settings->play->wolf[i], settings) == false && \
        settings->play->wolf[i]->is_destroy == false) {
            update_game_object(settings->play->wolf[i]);
            sfRenderWindow_drawSprite(settings->set_w->window, \
            settings->play->wolf[i]->sprite, NULL);
        }
        i++;
    }
}

void display_dino(game_t *settings)
{
    int i = 0;
    settings->play = make_dino_alive(settings->play);
    while (settings->play->dino[i]) {
        if (settings->play->dino[i]->has_spawned == true &&
        is_at_castle(settings->play->dino[i], settings) == false && \
        settings->play->dino[i]->is_destroy == false) {
            update_game_object(settings->play->dino[i]);
            sfRenderWindow_drawSprite(settings->set_w->window, \
            settings->play->dino[i]->sprite, NULL);
        }
        i++;
    }
}