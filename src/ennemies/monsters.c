/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** golem
*/

#include "defender.h"

GameObject_t *init_path(GameObject_t *obj)
{
    obj->paths = malloc(sizeof(sfVector2f) * (12));
    if (!obj->paths)
        return NULL;
    obj->paths[0] = (sfVector2f){760, 40};
    obj->paths[1] = (sfVector2f){720, 400};
    obj->paths[2] = (sfVector2f){460, 500};
    obj->paths[3] = (sfVector2f){360, 600};
    obj->paths[4] = (sfVector2f){380, 800};
    obj->paths[5] = (sfVector2f){440, 860};
    obj->paths[6] = (sfVector2f){900, 860};
    obj->paths[7] = (sfVector2f){1040, 920};
    obj->paths[8] = (sfVector2f){1140, 860};
    obj->paths[9] = (sfVector2f){1240, 800};
    obj->paths[10] = (sfVector2f){1440, 720};
    obj->paths[11] = (sfVector2f){-1, -1};
    obj->nb_paths = 1;
    return obj;
}

GameObject_t **init_golem(GameObject_t **golem, int nb_golem)
{
    sfVector2f start_pos = {760, 40};
    if (!(golem = malloc(sizeof(GameObject_t) * (nb_golem + 1))))
        return NULL;
    golem[nb_golem] = NULL;
    for (int i = 0; i < nb_golem; i++) {
        golem[i] = create_game_object("include/data/golem.png", \
        5, start_pos, 150);
        if (!golem[i])
            return NULL;
        sfSprite_setScale(golem[i]->sprite, (sfVector2f){0.75, 0.75});
        golem[i] = center_origin(golem[i]);
        golem[i] = init_path(golem[i]);
        if (!golem[i]->paths)
            return NULL;
        golem[i]->obj_speed.x = 5.0;
        golem[i]->obj_speed.y = 5.0;
        golem[i]->pv = 200;
        golem[i]->is_destroy = false;
        golem[i]->has_spawned = false;
    } return golem;
}

GameObject_t **init_wolf(GameObject_t **wolf, int nb_wolf)
{
    sfVector2f start_pos = {760, 40};
    if (!(wolf = malloc(sizeof(GameObject_t) * (nb_wolf + 1))))
        return NULL;
    wolf[nb_wolf] = NULL;
    for (int i = 0; i < nb_wolf; i++) {
        wolf[i] = create_game_object("include/data/wolf.png", \
        5, start_pos, 75);
        if (!wolf[i])
            return NULL;
        wolf[i] = center_origin(wolf[i]);
        wolf[i] = init_path(wolf[i]);
        if (!wolf[i]->paths)
            return NULL;
        wolf[i]->obj_speed.x = 20.0;
        wolf[i]->obj_speed.y = 20.0;
        wolf[i]->pv = 50;
        wolf[i]->is_destroy = false;
        wolf[i]->has_spawned = false;
    } return wolf;
}

GameObject_t **init_dino(GameObject_t **dino, int nb_dino)
{
    sfVector2f start_pos = {760, 40};
    if (!(dino = malloc(sizeof(GameObject_t) * (nb_dino + 1))))
        return NULL;
    dino[nb_dino] = NULL;
    for (int i = 0; i < nb_dino; i++) {
        dino[i] = create_game_object("include/data/dino.png", \
        5, start_pos, 50);
        if (!dino[i])
            return NULL;
        dino[i] = center_origin(dino[i]);
        dino[i] = init_path(dino[i]);
        if (!dino[i]->paths)
            return NULL;
        dino[i]->obj_speed.x = 10.0;
        dino[i]->obj_speed.y = 10.0;
        dino[i]->has_spawned = false;
        dino[i]->is_destroy = false;
        dino[i]->pv = 100;
    } return dino;
}