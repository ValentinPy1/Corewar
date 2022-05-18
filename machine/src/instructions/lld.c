/*
** EPITECH PROJECT, 2022
** lld
** File description:
** Source code of lld func
*/
#include "machine.h"

void lld_func(vm_t *vm, process_t *process, ope_t *ope)
{
    int res = 0;
    int adress = process->pc + ope->real_args[0];
    load_to_ptr(&res, adress, vm, ope->size_type[0]);
    process->reg[ope->real_args[1]] = res;
}
