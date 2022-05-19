/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get_index_value.c
*/

#include "machine.h"

int get_index_value(vm_t *vm, int adress)
{
    short int chain = 0;
    int value = 0;

    ((char *) &chain)[0] = BYTE(1);
    ((char *) &chain)[1] = BYTE(0);
    value = chain;
    return value;
}
