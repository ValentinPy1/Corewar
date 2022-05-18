/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** st.c
*/

#include <stdlib.h>
#include "machine.h"

void st_func(vm_t *vm, process_t *p, ope_t *ope)
{
    int reg_index = ope->real_args[0];
    // void *data = (ope->size_type[1] == T_REG)
    // ? &process->reg[ope->real_args[1]]
    // : vm->ram->mem + ope->real_args[1] % IDX_MOD;

    // load_data_from_reg(&process->reg[reg_index], data, REG_SIZE);
    if (ope->type[1] == T_REG)
        lireg(&(p->reg[reg_index]), REG_SIZE, ope->real_args[1]);
    else
        load_data_to_mem(p->reg[reg_index], ope->real_args[1],
        ope->size_type[1], vm);
}

void sti_func(vm_t *vm, process_t *process, ope_t *ope)
{
    int reg_index = ope->real_args[0];
    int adress = process->pc + ope->real_args[1] % IDX_MOD;
    void *data = (ope->size_type[1] == T_REG) ? &process->reg[ope->real_args[1]]
    : vm->ram->mem + ope->real_args[1] % IDX_MOD;
    load_data_from_reg(&process->reg[reg_index], data, REG_SIZE);
    load_data_in_reg(&process->reg[reg_index], vm->ram->mem + adress, REG_SIZE);
}
