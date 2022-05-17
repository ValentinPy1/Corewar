/*
** EPITECH PROJECT, 2022
** ld
** File description:
** Source code of ld intruction
*/

#include <stdlib.h>
#include "machine.h"

void ld_func(vm_t *vm, process_t *process, ope_t *ope)
{
    ope->args[1] = ope->args[0];
    process->carry += ope->size;
}

void lld_func(vm_t *vm, process_t *process, ope_t *ope)
{
    ope->args[1] = ope->args[0];
    process->carry += ope->size;
}