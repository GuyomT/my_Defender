/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** $
*/

#include "defender.h"

tower_t **create_basic_tower(tower_t **tower, sfRectangleShape *place, \
game_t *settings)
{
    int i = next_tower(tower);
    sfVector2f pos = sfRectangleShape_getPosition(place);
    sfVector2u t_siz;

    tower[i] = create_params_tower(tower[i], BASIC_T, 15, \
    "include/data/basic_tower.png");
    tower[i]->shoot_speed = 500;
    t_siz = sfTexture_getSize(tower[i]->texture);
    pos.x += 30;
    pos.y -= 70;
    tower[i] = create_rect_shape(tower[i], t_siz, pos);
    tower[i]->radius = 175;
    pos.x -= tower[i]->radius / 2 + 50;
    pos.y -= tower[i]->radius / 2;
    tower[i] = create_range(tower[i], pos);
    settings->play->money->moula -= 75;
    return tower;
}

tower_t **create_freeze_tower(tower_t **tower, sfRectangleShape *place, \
game_t *settings)
{
    int i = next_tower(tower);
    sfVector2f pos = sfRectangleShape_getPosition(place);
    sfVector2u t_siz;

    tower[i] = create_params_tower(tower[i], FREEZE_T, 15, \
    "include/data/freeze.png");
    tower[i]->shoot_speed = 1000;
    t_siz = sfTexture_getSize(tower[i]->texture);
    pos.x += 30;
    pos.y -= 55;
    tower[i] = create_rect_shape(tower[i], t_siz, pos);
    tower[i]->radius = 190;
    pos.x -= tower[i]->radius / 2 + 60;
    pos.y -= tower[i]->radius / 2 + 25;
    tower[i] = create_range(tower[i], pos);
    settings->play->money->moula -= 125;
    return tower;
}

tower_t **create_mortar_tower(tower_t **tower, sfRectangleShape *place, \
game_t *settings)
{
    int i = next_tower(tower);
    sfVector2f pos = sfRectangleShape_getPosition(place);
    sfVector2u t_siz;

    tower[i] = create_params_tower(tower[i], MORTAR_T, 40, \
    "include/data/mortar.png");
    tower[i]->shoot_speed = 2000;
    pos.x += 33;
    pos.y -= 45;
    t_siz = sfTexture_getSize(tower[i]->texture);
    tower[i] = create_rect_shape(tower[i], t_siz, pos);
    tower[i]->radius = 190;
    pos.x -= tower[i]->radius / 2 + 60;
    pos.y -= tower[i]->radius / 2 + 25;
    tower[i] = create_range(tower[i], pos);
    settings->play->money->moula -= 175;
    return tower;
}

tower_t **create_sniper_tower(tower_t **tower, sfRectangleShape *place, \
game_t *settings)
{
    int i = next_tower(tower);
    sfVector2f pos = sfRectangleShape_getPosition(place);
    sfVector2u t_siz;

    tower[i]->shoot_speed = 1000;
    tower[i] = create_params_tower(tower[i], BASIC_T, 10, \
    "include/data/sniper.png");
    t_siz = sfTexture_getSize(tower[i]->texture);
    pos.x += 25;
    pos.y -= 50;
    tower[i] = create_rect_shape(tower[i], t_siz, pos);
    tower[i]->radius = 400;
    pos.x -= tower[i]->radius / 2 + 175;
    pos.y -= tower[i]->radius / 2 + 100;
    tower[i] = create_range(tower[i], pos);
    settings->play->money->moula -= 50;
    return tower;
}

game_menu_t *create_tower(game_menu_t *play, int nb_rect, game_t *settings)
{
    if (play->tower_value == BASIC_T && settings->play->money->moula >= 75) {
        play->tower = create_basic_tower(play->tower, \
        play->tower_place[nb_rect], settings);
    }
    if (play->tower_value == FREEZE_T && settings->play->money->moula >= 125) {
        play->tower = create_freeze_tower(play->tower, \
        play->tower_place[nb_rect], settings);
    }
    if (play->tower_value == MORTAR_T && settings->play->money->moula >= 175) {
        play->tower = create_mortar_tower(play->tower, \
        play->tower_place[nb_rect], settings);
    }
    if (play->tower_value == SNIPER_T && settings->play->money->moula >= 50) {
        play->tower = create_sniper_tower(play->tower, \
        play->tower_place[nb_rect], settings);
    }
    play->tower_value = 0;
    return play;
}