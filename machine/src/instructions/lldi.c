/*
** EPITECH PROJECT, 2022
** lldi
** File description:
** SOurce code of lldi
*/

#include <stdlib.h>
#include "machine.h"
#include "asm.h"

void lldi_func(vm_t *vm, process_t *process, ope_t *ope)
{
    int value = 0;
    int tmp = 0;
    int adress = process->pc + ope->real_args[0];

    load_to_ptr(&value, adress, vm, IND_SIZE);
    tmp = ope->real_args[1];
    tmp = tmp + value;
    adress = process->pc + tmp;
    load_to_ptr(&value, adress, vm, REG_SIZE);
    invert_endianess(&value, REG_SIZE);
    process->reg[ope->real_args[2] - 1] = value;
}
