/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** create_cpu.c
*/

#include "machine.h"

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

    //TODO

    return prog;
}

void load_prog(vm_t *vm, char *path, int adress, int flag)
{
    process_t *proc = malloc(sizeof(process_t));
    char *prog = get_prog(path);
    int pn = vm->proc_nbr;

    for (int i = 0; prog[i]; ++i) {
        vm->ram->mem[i + adress] = prog[i];
    }
    proc->carry = false;
    proc->flag = flag;
    proc->last_live = 0;
    proc->pc = adress;
    proc->reg = load_reg();
    vm->process = realloc(vm->process, pn + 2);
    vm->process[pn] = proc;
    vm->proc_nbr += 1;
    vm->process[pn + 1] = NULL;
}