/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** itoa
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_revstr(char *str)
{
    int	num = 0;
    int	lenght = my_strlen(str) - 1;
    char opmet;

    while (num < lenght) {
        opmet = str[num];
        str[num] = str[lenght];
        str[lenght] = opmet;
        num++;
        lenght--;
    }
    return (str);
}

int nbr_len(int nb)
{
    int len = 1;
    while (nb > 9) {
        nb /= 10;
        len++;
    }
    return len;
}

char *int_to_str(int nb)
{
    char *str;
    int sign = 0;
    int i = 0;

    if (nb < 0) {
        nb *= -1;
        sign = -1;
    } if (nb == 0)
        return "0";
    str = malloc(sizeof(char) * (nbr_len(nb) + 1));
    if (!str)
        return NULL;
    while (nb > 0) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
        i++;
    } if (sign == -1)
        str[i] = '-';
    str[i] = 0;
    return my_revstr(str);
}