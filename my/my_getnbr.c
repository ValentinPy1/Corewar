/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** my_getnbr.c
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i;
    int len = my_strlen(str);
    int mult = 1;
    int number = 0;
    for (i = len - 1; i >= 0; i--) {
        number = number + (str[i] - 48) * mult;
        mult = mult * 10;
    }
    return (number);
}