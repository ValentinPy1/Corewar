/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** sti.c
*/

#include "machine.h"
#include "asm.h"

void sti_func(vm_t *vm, process_t *p, ope_t *ope)
{
    int reg_index = ope->real_args[0];
    int adress = p->pc + (ope->real_args[1] + ope->real_args[2])
    % IDX_MOD;
    // invert_endianess(&(p->reg[reg_index - 1]), sizeof(int));
    // invert_endianess(&(p->reg[reg_index - 1]), sizeof(int));
    load_data_to_mem(adress, &(p->reg[reg_index - 1]), REG_SIZE, vm);
}
