/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** xor.c
*/

#include <stdlib.h>
#include "machine.h"

void xor_func(vm_t *vm, process_t *p, ope_t *ope)
{
    int arg1 = 0;
    int arg2 = 0;
    int result = 0;

    loadarg(arg1, 0, sizeof(int));
    loadarg(arg2, 1, sizeof(int));
    result = arg1 ^ arg2;
    lireg(&result, sizeof(int), 2);
}