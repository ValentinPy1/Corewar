/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** aff.c
*/

#include "machine.h"
#include "asm.h"

void aff_func(vm_t *vm, process_t *p, ope_t *ope)
{
    char c = (ope->real_args[0]) % 256;

    write(1, &c, 1);
}
