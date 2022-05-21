/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** load_arg.c
*/

#include "machine.h"
#include "asm.h"
#include "special_loaders.h"


int load_real_arg_special(vm_t *vm,
ope_t *ope, int adress, process_t *process)
{
    if (special_loaders[ope->code - 1]) {
        special_loaders[ope->code - 1](vm, process, ope, adress);
        return 1;
    }
    return 0;
}

void get_op_real_args(vm_t *vm, ope_t *ope, int adress, process_t *process)
{
    int arg_nbr = op_tab[ope->code - 1].nbr_args;
    if (load_real_arg_special(vm, ope, adress, process))
        return;
    for (int i = 0; i < arg_nbr; ++i) {
            ope->real_args[i] = load_arg(vm, adress, i, ope);
        adress += ope->size_type[i];
    }
}