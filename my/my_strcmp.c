/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_strcmp.c
*/

#include "limits.h"

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] && str2[i] && str1[i] == str2[i])
        ++i;
    return str1[i] - str2[i];
}

int getnbr_until_non_digit(char **str)
{
    int nbr = 0;
    int sign = 1;

    if (**str && **str == '-') {
        sign = -1;
        ++*str;
    }
    if (**str > '9' || **str < '0')
        return INT_MIN;
    while (**str && **str >= '0' && **str <= '9') {
        nbr = nbr * 10 + **str - '0';
        ++*str;
    }
    return nbr * sign;
}

void my_strncpy(char *dest, char *str, int n)
{
    for (int i = 0; i < n; ++i) {
        dest[i] = str[i];
        if (!str[i])
            break;
    }
}
