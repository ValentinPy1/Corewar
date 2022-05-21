/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** create_cpu.c
*/

#include "machine.h"
#include "instruction.h"
#include "asm.h"

int *load_reg(int flag)
{
    int *reg = malloc(sizeof(int *) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++) {
        reg[i] = 0;
    }
    reg[0] = flag;
    return reg;
}

static int update_process2(vm_t *vm, process_t *proc)
{
    ope_t *ope = proc->current_ope;
    if (!ope) {
        proc->pc += 1;
        proc->pc %= MEM_SIZE;
        destroy_ope(proc->current_ope);
        proc->current_ope = get_ope(vm, proc->pc, proc);
        return 1;
    }
    if (proc->wait > 0) {
        proc->wait -= 1;
        return 1;
    }
    return 0;
}

void update_process(vm_t *vm, process_t *proc)
{
    int *option = NULL;
    ope_t *ope;
    if (proc == NULL)
        return;
    ope = proc->current_ope;
    if (update_process2(vm, proc)) return;
    if (ope && ope->code > 0 && ope->code <= 16
    && MNEMONIC[ope->code].func) {
        MNEMONIC[(int) ope->code].func(vm, proc, ope);
        proc->pc = (proc->pc + ope->size) % MEM_SIZE;
        destroy_ope(proc->current_ope);
        proc->current_ope = get_ope(vm, proc->pc, proc);
        if (proc->current_ope)
            proc->wait = proc->current_ope->nbr_cycles;
        return;
    }
    proc->pc += 1;
    proc->pc %= MEM_SIZE;
    destroy_ope(proc->current_ope);
    proc->current_ope = get_ope(vm, proc->pc, proc);
}
