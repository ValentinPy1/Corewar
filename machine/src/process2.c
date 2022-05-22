/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** process2.c
*/

#include "machine.h"
#include "asm.h"

static int get_prog(ram_t *ram, int adress, char *path, process_t *process)
{
    int fd = open(path, O_RDONLY);
    header_t header;

    if (fd < 0)
        return 84;
    char *prog = malloc(sizeof(char) * MEM_SIZE);
    char *tmp = malloc(sizeof(char) * MEM_SIZE);
    int count = 0;
    read(fd, &header, sizeof(header_t));
    process->prog_size = header.prog_size;
    invert_endianess(&(process->prog_size), sizeof(int));
    while (read(fd, tmp, 1)) count++;
    close(fd);
    fd = open(path, O_RDONLY);
    read(fd, tmp, sizeof(header_t));
    read(fd, prog, count);
    for (int i = 0; i < count; ++i)
        ram->mem[(i + adress) % MEM_SIZE] = prog[i];
    close(fd);
    return 0;
}

void load_prog(vm_t *vm, char *path, int adress, int prog_number)
{
    process_t *proc = malloc(sizeof(process_t));

    adress += sizeof(header_t);
    get_prog(vm->ram, adress, path, proc);
    proc->name = path;
    proc->carry = false;
    proc->prog_nbr = prog_number;
    proc->last_live = 0;
    proc->pc = adress;
    proc->initial_pc = adress;
    proc->reg = load_reg(prog_number);
    proc->wait = 0;
    proc->player_id_alive = -1;
    proc->current_ope = get_ope(vm, adress, proc);
    vm->process = realloc(vm->process, ++(vm->proc_count)
    * sizeof(process_t *));
    vm->process[vm->proc_count - 1] = proc;
}
