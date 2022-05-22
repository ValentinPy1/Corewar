/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** tools.c
*/

#include "machine.h"

int sum_char(char *size_type)
{
    int total = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; ++i)
        total += size_type[i];
    return total;
}
