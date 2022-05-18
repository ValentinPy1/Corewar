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
    for (int i = 0; i < count; ++i) {
        ram->mem[(i + adress) % MEM_SIZE] = prog[i];
    }
    close(fd);
    for (int i = 0; i < count; ++i) {
        // printf("[%x]", *((char *) ram->mem + adress + i));
    }
    // printf("\n");
    return 0;
}

void load_prog(vm_t *vm, char *path, int adress, int prog_number)
{
    // printf("adress : %d\n", adress);
    process_t *proc = malloc(sizeof(process_t));
    adress += sizeof(header_t);
    get_prog(vm->ram, adress, path);
    proc->name = path;
    proc->carry = false;
    proc->prog_nbr = prog_number;
    proc->last_live = 0;
    proc->pc = adress;
    proc->reg = load_reg(prog_number); // get the flag from the input
    proc->wait = 0;// = proc->current_ope->nbr_cycles;
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

    // printf("%d pc : %d\n", proc->flag, proc->pc);
    // printf("\n\n");
    // dipslay_memory(vm);
    if (proc == NULL)
        return;
    ope = proc->current_ope;
    if (!ope) {
        proc->pc += 1;
        proc->pc %= MEM_SIZE;
        destroy_ope(proc->current_ope);
        proc->current_ope = get_ope(vm, proc->pc, proc);
        return;
    }
    if (proc->wait > 0) {
        proc->wait -= 1;
        return;
    }
    printf("ope memo : %s\n", op_tab[ope->code - 1].mnemonique);
    if (MNEMONIC[ope->code].func) {
        MNEMONIC[(int) ope->code].func(vm, proc, ope);
    }
    proc->pc = (proc->pc + ope->size) % MEM_SIZE;
    destroy_ope(proc->current_ope);
    proc->current_ope = get_ope(vm, proc->pc, proc);
    if (proc->current_ope)
        proc->wait = proc->current_ope->nbr_cycles;
}
