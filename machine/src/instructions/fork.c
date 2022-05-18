/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** fork.c
*/

#include "machine.h"
#include "asm.h"

static void copy_process_at(int adress, process_t *process, vm_t *vm)
{
    process_t *new = malloc(sizeof(process_t));

    if (!new)
        return;
    *new = *process;
    new->current_ope = malloc(sizeof(ope_t));
    *(new->current_ope) = *(process->current_ope);
    new->pc = adress + (process->pc - process->initial_pc);
    for (int i = 0; i < process->prog_size; ++i) {
        (vm->ram->mem)[(adress + i) % MEM_SIZE]
        = (vm->ram->mem)[(process->initial_pc + i) % MEM_SIZE];
    }
    new->reg = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; ++i) {
        new->reg[i] = process->reg[i];
    }
    vm->process = realloc(vm->process, ++(vm->proc_count)
    * sizeof(process_t *));
    vm->process[vm->proc_count - 1] = new;
}

void fork_func(vm_t *vm, process_t *p, ope_t *ope)
{
    int adress = p->pc + ope->real_args[0] % IDX_MOD;

    copy_process_at(adress, p, vm);
}
