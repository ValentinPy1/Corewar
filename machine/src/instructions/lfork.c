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
    int new_pc = p->pc + ope->real_args[0];
    int adress = get_adress_with_space(vm, p->prog_size);

    if (adress < 0)
        return;
    copy_process_at(new_pc, p, vm, adress);
}
