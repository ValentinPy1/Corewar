/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** my_putchar.c
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}