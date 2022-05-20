/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** add.c
*/

#include <stdlib.h>
#include "machine.h"
#include "asm.h"

static void add_from_registers(int *r1, int *r2, int *r3, process_t *process)
{
    *r3 = *r1 + *r2;
    process->carry = (*((int *) r3) == 0);
}

void add_func(vm_t *vm, process_t *process, ope_t *ope)
{
    if (ope->real_args[0] <= 0 || ope->real_args[0] > REG_NUMBER
    || ope->real_args[1] <= 0 || ope->real_args[1] > REG_NUMBER
    || ope->real_args[2] <= 0 || ope->real_args[2] > REG_NUMBER)
        return;
    process->reg[ope->real_args[2] - 1] =
    process->reg[ope->real_args[1] - 1]
    + process->reg[ope->real_args[0] - 1];
}
