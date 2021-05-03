/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** game_objects
*/

#include "defender.h"

void update_sprite(GameObject_t *obj, float move_x)
{
    if (move_x < 0.0)
        sfSprite_setScale(obj->sprite, (sfVector2f){-0.75, 0.75});
    else
        sfSprite_setScale(obj->sprite, (sfVector2f){0.75, 0.75});
}

GameObject_t *center_origin(GameObject_t *obj)
{
    sfVector2f size;
    sfVector2u texture_size;
    sfVector2f scale = sfSprite_getScale(obj->sprite);
    sfVector2f origin;
    texture_size = sfTexture_getSize(obj->texture);
    size.x = texture_size.x * scale.x;
    size.y = texture_size.y * scale.y;
    origin.x = size.x / (2 * obj->nb_frames);
    origin.y = size.y / (2 * obj->nb_frames);
    sfSprite_setOrigin(obj->sprite, origin);
    return obj;
}

void move_game_object(GameObject_t *obj, sfVector2f obj_speed)
{
    sfVector2f pos = sfSprite_getPosition(obj->sprite);
    sfVector2f move;
    if (obj->paths[obj->nb_paths].x == pos.x && \
        obj->paths[obj->nb_paths].y == pos.y && \
        obj->paths[obj->nb_paths + 1].x > 0)
        obj->nb_paths++;
    move.x = obj->paths[obj->nb_paths].x - obj->paths[obj->nb_paths - 1].x;
    move.y = obj->paths[obj->nb_paths].y - obj->paths[obj->nb_paths - 1].y;
    update_sprite(obj, move.x);
    if (move.x < 0.0)
        obj_speed.x *= -1.0;
    if (move.y < 0.0)
        obj_speed.y *= -1.0;
    if (obj->paths[obj->nb_paths].x != pos.x)
        sfSprite_move(obj->sprite, (sfVector2f){obj_speed.x, 0});
    if (obj->paths[obj->nb_paths].y != pos.y)
        sfSprite_move(obj->sprite, (sfVector2f){0, obj_speed.y});
}

void update_game_object(GameObject_t *obj)
{
    sfTime elapsed_time = sfClock_getElapsedTime(obj->clock);
    float time = sfTime_asMilliseconds(elapsed_time);
    int actual_frame = 0;

    if (time > obj->frame_speed) {
        obj->mask.left += obj->mask.width;
        actual_frame = obj->mask.left / obj->mask.width;
        if (actual_frame >= obj->nb_frames) {
            obj->mask.left = 0;
        }
        move_game_object(obj, obj->obj_speed);
        sfSprite_setTextureRect(obj->sprite, obj->mask);
        sfClock_restart(obj->clock);
    }
}

GameObject_t *create_game_object(char *filepath_to_img, int nb_frames, \
sfVector2f pos, float speed)
{
    GameObject_t *obj = malloc(sizeof(GameObject_t));
    sfVector2u texture_size;
    if (!obj)
        return NULL;
    obj->texture = sfTexture_createFromFile(filepath_to_img, NULL);
    obj->sprite = sfSprite_create();
    texture_size = sfTexture_getSize(obj->texture);
    obj->mask.top = 0;
    obj->mask.left = 0;
    obj->mask.height = texture_size.y;
    obj->mask.width = texture_size.x / nb_frames;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->mask);
    obj->nb_frames = nb_frames;
    obj->frame_speed = speed;
    obj->clock = sfClock_create();
    obj->pos = pos;
    sfSprite_setPosition(obj->sprite, pos);
    return obj;
}