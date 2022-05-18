/*
** EPITECH PROJECT, 2022
** lfork
** File description:
** Source code of lfork
*/
#include "machine.h"
#include "asm.h"

void lfork_func(vm_t *vm, process_t *p, ope_t *ope)
{
    int adress = p->pc + ope->real_args[0];

    copy_process_at(adress, p, vm);
}