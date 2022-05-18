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
    if (ope->type[1] == T_REG)
        p->reg[ope->real_args[1]] = p->reg[reg_index];
    else
        load_data_to_mem(p->reg[reg_index], &(ope->real_args[1]),
        ope->size_type[1], vm);
}
