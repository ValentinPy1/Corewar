/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** function_cpu.c
*/

#include "machine.h"

void live(vm_t *vm, process_t *process, ope_t *ope)
{
    my_putstr("The player ");
    my_put_nbr(ope->args[0]);
    my_putstr(" is alive..\n");
}

//display array of int

void ld_func(vm_t *vm, process_t *process, ope_t *ope)
{
    // TODO update old code with new arguments
    // display_int(option);
    // process->reg[option[2]] = option[0];
    // process->reg[option[1]] = ram->mem[process->pc + option[2] % IDX_MOD];
}

// TODO all reamaining instructions