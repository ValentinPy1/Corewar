/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** create_cpu.c
*/

#include "machine.h"
#include "instruction.h"

int *load_reg(int flag)
{
    int *reg = malloc(sizeof(int *) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++) {
        reg[i] = 0;
    }
    reg[0] = flag;
    return reg;
}

int get_prog(ram_t *ram, int adress, char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd < 0)
        return 84;
    char *prog = malloc(sizeof(char) * MEM_SIZE);
    char *tmp = malloc(sizeof(char) * MEM_SIZE);
    int count = 0;
    read(fd, tmp, sizeof(header_t));
    while (read(fd, tmp, 1)) count++;
    close(fd);
    fd = open(path, O_RDONLY);
    read(fd, tmp, sizeof(header_t));
    read(fd, prog, count);
    for (int i = 0; i + adress < count; ++i) {
        ram->mem[i + adress] = prog[i];
    }
    close(fd);
    return 0;
}

void load_prog(vm_t *vm, char *path, int adress, int prog_number)
{
    process_t *proc = malloc(sizeof(process_t));

    get_prog(vm->ram, adress, path);
    proc->name = path;
    proc->carry = false;
    proc->prog_nbr = prog_number;
    proc->last_live = 0;
    proc->pc = adress;
    proc->reg = load_reg(prog_number); // get the flag from the input
    // proc->wait = proc->current_ope->nbr_cycles;
    proc->player_id_alive = -1;
    proc->current_ope = get_ope(vm, adress, proc);
    vm->process = realloc(vm->process, ++(vm->proc_count)
    * sizeof(process_t *));
    vm->process[vm->proc_count - 1] = proc;
}

void update_process(vm_t *vm, process_t *proc)
{
    int *option = NULL;
    ope_t *ope;

    if (proc == NULL)
        return;
    ope = proc->current_ope;
    if (proc->wait > 0) {
        proc->wait -= 1;
        return;
    }
    if ((int) ope->code > 0 && (int) ope->code < sizeof(MNEMONIC)
    / sizeof(MNEMONIC[0])
    && MNEMONIC[(int) ope->code].func)
        MNEMONIC[(int) ope->code].func(vm, proc, ope);
    proc->pc = (proc->pc + ope->size) % MEM_SIZE;
    // destroy_ope(proc->current_ope); // TODO function for destroying operation
    proc->current_ope = get_ope(vm, proc->pc, proc);
    proc->wait = proc->current_ope->nbr_cycles;
}
