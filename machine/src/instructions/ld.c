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
    process->reg[ope->real_args[1]] = ope->real_args[0];
    process->carry = !ope->real_args[0];
    invert_endianess(&(process->reg[ope->real_args[1]]), REG_SIZE);
}
