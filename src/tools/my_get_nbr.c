/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_get_nbr
*/

#include <unistd.h>

int my_getnbr(char const *str)
{
    int var = 0;
    int inv = 1;
    int i = 0;

    if (str == NULL)
        return (0);
    while ((*str < '0' || *str > '9') && *str != 0) {
        str++;
        i++;
    }
    if (i > 0 && *(str - 1) == '-')
        inv = -1;
    while (*str != 0 && *str >= '0' && *str <= '9') {
        var = var * 10;
        var = var + *str - 48;
        str++;
    }
    var = var * inv;
    return (var);
}