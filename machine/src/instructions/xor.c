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
    int result = 0;

    if (ope->real_args[0] <= 0 || ope->real_args[0] > REG_NUMBER
    || ope->real_args[1] <= 0 || ope->real_args[1] > REG_NUMBER
    || ope->real_args[2] <= 0 || ope->real_args[2] > REG_NUMBER)
        return;
    result = ope->real_args[0] ^ ope->real_args[1];
    p->reg[ope->real_args[2] - 1] = result;
}
