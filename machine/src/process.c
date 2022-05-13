/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** create_cpu.c
*/

#include "machine.h"

static const instruct_t MNEMONIC[] = {
    {&live},
    {&ld_func},
    {&st_func},
    {&add_func},
    {&sub_func},
    {&and_func},
    {&xor_func}
};

char **load_reg(void)
{
    char **reg = malloc(sizeof(char *) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++) {
        reg[i] = malloc(sizeof(char) * REG_SIZE);
        for (int j = 0; j < REG_SIZE; j++)
            reg[i][j] = 0;
    }
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
    // read(fd, &tmp, sizeof(header_t));
    while (read(fd, &prog, 1)) count++;
    for (int i = 0; i < count; ++i)
        ram->mem[i + adress] = prog[i];
    close(fd);
    return 0;
}
// void load_prog(vm_t *vm, char **av)
void load_prog(vm_t *vm, char *path, int adress, int prog_number)
{
    process_t *proc = malloc(sizeof(process_t));
    int pn = vm->proc_nbr;
    printf("launch gang\n");
    get_prog(vm->ram, adress, path);
    printf("after \n");
    proc->carry = false;
    proc->prog_nbr = prog_number;
    proc->last_live = 0;
    proc->pc = adress;
    proc->reg = load_reg();
    proc->current_ope = get_ope(vm, adress);
    proc->wait = proc->current_ope->nbr_cycles;
    vm->proc_nbr = prog_number;
    vm->process = realloc(vm->process, pn + 2);
    vm->process[pn] = proc;
    vm->proc_nbr += 1; /// ??????????????????????????????????????????????????????????
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
    // destroy_ope(proc->current_ope); // TODO function for destroying operation
    proc->current_ope = get_ope(vm, proc->pc);
    proc->wait = proc->current_ope->nbr_cycles;
}
