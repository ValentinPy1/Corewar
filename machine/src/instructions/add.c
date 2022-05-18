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
    invert_endianess(&r1, sizeof(int));
    invert_endianess(&r2, sizeof(int));
    add_from_registers(r1, r2, r3, process);
    invert_endianess(&r3, sizeof(int));
    load_data_in_reg(&process->reg[ope->args[2]], r3, REG_SIZE);
    free(r1);
    free(r2);
    free(r3);
}