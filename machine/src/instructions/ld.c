/*
** EPITECH PROJECT, 2022
** ld
** File description:
** Source code of ld intruction
*/

#include <stdlib.h>
#include "machine.h"
#include "asm.h"

void ld_func(vm_t *vm, process_t *process, ope_t *ope)
{
    int res = 0;
    int adress = process->pc + ope->real_args[0] % IDX_MOD;
    load_to_ptr(&res, adress, vm, ope->size_type[0]);
    process->reg[ope->real_args[1]] = res;
}

void lld_func(vm_t *vm, process_t *process, ope_t *ope)
{
    int res = 0;
    int adress = process->pc + ope->real_args[0];
    load_to_ptr(&res, adress, vm, ope->size_type[0]);
    process->reg[ope->real_args[1]] = res;
}