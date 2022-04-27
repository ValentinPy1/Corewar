/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** dispays one by one the characters
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != 0) {
        my_putchar(str[i]);
        i = i + 1;
    }
}