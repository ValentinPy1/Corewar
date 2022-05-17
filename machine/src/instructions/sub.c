/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** sub.c
*/

#include <stdlib.h>
#include "machine.h"

static void sub_from_registers(int *r1, int *r2, int *r3, process_t *process)
{
    *r3 = *r1 - *r2;
    process->carry = (*((int *) r3) == 0);
}

void sub_func(vm_t *vm, process_t *process, ope_t *ope)
{
    int *r1 = malloc(REG_SIZE);
    int *r2 = malloc(REG_SIZE);
    int *r3 = malloc(REG_SIZE);

    if (!r1 || !r2 || !r3) {
        if (r1)
            free(r1);
        if (r2)
            free(r2);
        if (r3)
            free(r3);
        return;
    }
    load_data_from_reg(&process->reg[ope->args[0]], r1, REG_SIZE);
    load_data_from_reg(&process->reg[ope->args[0]], r2, REG_SIZE);
    sub_from_registers(r1, r2, r3, process);
    load_data_in_reg(&process->reg[ope->args[2]], r3, REG_SIZE);
    free(r1);
    free(r2);
    free(r3);
}
