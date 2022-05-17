/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get_real_args.c
*/

#include "machine.h"
#include "asm.h"

void invert_endianess(void *var, size_t size)
{
    char *var_c = (char *) var;
    char tmp = 0;

    for (size_t i = 0; i < size / 2; ++i) {
        tmp = var_c[i];
        var_c[i] = var_c[size - i - 1];
        var_c[size - i - 1] = tmp;
    }
}

void memcpy_size(void *dest, void *src, size_t size)
{
    for (int i = 0; i < size; ++i) {
        ((char *) dest)[i] = ((char *) src)[i];
    }
}

void load_to_ptr(void *ptr, int adress, vm_t *vm, size_t size)
{
    for (int i = 0; i < size; ++i)
        ((char *) ptr)[i] = (vm->ram->mem + adress)[i];
}

int load_arg(vm_t *vm, int adress, int i, ope_t *ope, process_t *process)
{
    int argv = 0;

    switch(ope->type[i]) {
        case T_DIR:
            memcpy_size(&argv,
            vm->ram->mem + ope->args[i] % MEM_SIZE, DIR_SIZE);
            break;
        case T_IND:
            load_to_ptr(&argv, (ope->args[i] + process->pc) % MEM_SIZE, vm,
            sizeof(int));
            break;
        case T_REG:
            argv = process->reg[ope->args[i]];
            break;
    }
    return argv;
}

void get_op_real_args(vm_t *vm, ope_t *ope, int adress, process_t *process)
{
    int arg_nbr = op_tab[ope->code - 1].nbr_args;

    for (int i = 0; i < arg_nbr; ++i) {
        ope->real_args[i] = load_arg(vm, adress, i, ope, process);
        invert_endianess(&(ope->real_args[i]), sizeof(int));
        adress += ope->size_type[i];
    }
}
