/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** fork.c
*/

#include "machine.h"
#include "asm.h"

void copy_process_at(int new_pc, process_t *process, vm_t *vm, int adress)
{
    process_t *new = malloc(sizeof(process_t));
    if (!new)
        return;
    *new = *process;
    new->current_ope = malloc(sizeof(ope_t));
    *(new->current_ope) = *(process->current_ope);
    new->pc = new_pc + adress + process->current_ope->size;
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

int there_is_enough_space_here(int i, vm_t *vm, int size)
{
    for (int j = 0; j < size; ++j) {
        if (vm->ram->mem[(i + j) % MEM_SIZE] != 0)
            return 0;
    }
    return 1;
}

int get_adress_with_space(vm_t *vm, int size)
{
    for (int i = 0; i < MEM_SIZE - size; ++i) {
        if (there_is_enough_space_here(i, vm, size))
            return i;
    }
    return -1;
}

void fork_func(vm_t *vm, process_t *p, ope_t *ope)
{
    int new_pc = p->pc - p->initial_pc;
    int adress = (p->pc + ope->real_args[0] % IDX_MOD) % MEM_SIZE;

    if (adress < 0)
        adress = MEM_SIZE - adress;
    new_pc %= MEM_SIZE;
    if (new_pc < 0)
        new_pc = MEM_SIZE - new_pc;
    copy_process_at(new_pc, p, vm, adress);
}
