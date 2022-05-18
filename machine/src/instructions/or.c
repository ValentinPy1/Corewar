/*
** EPITECH PROJECT, 2022
** or
** File description:
** Source code of or instruction
*/

#include <stdlib.h>
#include "machine.h"
#include "asm.h"

void or_func(vm_t *vm, process_t *p, ope_t *ope)
{
    int arg1 = ope->real_args[0];
    int arg2 = ope->real_args[1];
    int result = 0;

    result = arg1 | arg2;
    invert_endianess(&result, REG_SIZE);
    lireg(&result, REG_SIZE, ope->real_args[2]);
}
