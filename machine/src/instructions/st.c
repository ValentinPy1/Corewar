/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** st.c
*/

#include <stdlib.h>
#include "machine.h"

void st_func(vm_t *vm, process_t *process, ope_t *ope)
{
    int reg_index = ope->args[0];
    void *data = (ope->size_type[1] == T_REG) ? &process->reg[ope->args[1]]
    : vm->ram->mem + ope->args[1] % IDX_MOD;

    load_data_from_reg(&process->reg[reg_index], data, REG_SIZE);
}

