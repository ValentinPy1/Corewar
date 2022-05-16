/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** function_cpu.c
*/

#include <stdlib.h>
#include "machine.h"

void live(vm_t *vm, process_t *process, ope_t *ope)
{
    my_putstr("The player ");
    my_put_nbr(ope->args[0]);
    process->player_id_alive = ope->args[0];
    process->last_live = vm->cycle;
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

void st_func(vm_t *vm, process_t *process, ope_t *ope)
{
    int reg_index = ope->args[0];
    void *data = (ope->size_type[1] == T_REG) ? &process->reg[ope->args[1]]
    : vm->ram->mem + ope->args[1] % IDX_MOD;

    load_data_from_reg(&process->reg[reg_index], data, REG_SIZE);
}

