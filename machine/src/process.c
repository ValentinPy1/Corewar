/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** create_cpu.c
*/

#include "machine.h"

static const instruct_t MNEMONIC[2] = {
    {&live},
    {&ld_func}
};

char **load_reg(void)
{
    char **reg = malloc(sizeof(char *) * REG_NUMBER);
    for(int i = 0; i < REG_NUMBER; i++) {
        reg[i] = malloc(sizeof(char) * REG_SIZE);
        for (int j = 0; j < REG_SIZE; j++)
            reg[i][j] = 0;
    }
    return reg;
}

char *get_prog(char *path)
{
    int fd = open(path, O_RDONLY);
    char *prog = NULL;

    // TODO

    return prog;
}

void load_prog(vm_t *vm, char *path, int adress, int flag)
{
    process_t *proc = malloc(sizeof(process_t));
    char *prog = get_prog(path);
    int pn = vm->proc_nbr;

    for (int i = 0; prog[i]; ++i)
        vm->ram->mem[i + adress] = prog[i];
    proc->carry = false;
    proc->flag = flag;
    proc->last_live = 0;
    proc->pc = adress;
    proc->reg = load_reg();
    proc->current_ope = get_ope(vm, adress);
    proc->wait = proc->current_ope->nbr_cycles;
    vm->process = realloc(vm->process, pn + 2);
    vm->process[pn] = proc;
    vm->proc_nbr += 1;
    vm->process[pn + 1] = NULL;
}

void update_process(vm_t *vm, process_t *proc)
{
    int *option = NULL;
    ope_t *ope = proc->current_ope;

    if (proc->wait > 0) {
        proc->wait -= 1;
        return;
    }
    MNEMONIC[ope->code].func(vm, proc, ope);
    proc->pc += ope->size;
    // destroy_ope(proc->current_ope);
    proc->current_ope = get_ope(vm, proc->pc);
    proc->wait = proc->current_ope->nbr_cycles;
}