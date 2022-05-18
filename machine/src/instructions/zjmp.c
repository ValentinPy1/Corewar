/*
** EPITECH PROJECT, 2022
** zjmp
** File description:
** Source code of jump intruction
*/

#include "machine.h"
#include "asm.h"

void zjmp_func(vm_t *vm, process_t *process, ope_t *ope)
{
    printf("zjmp %d\n", ope->real_args[0]);
    if (process->carry == 1)
        process->pc = (process->pc + ope->real_args[0]) % MEM_SIZE;
}