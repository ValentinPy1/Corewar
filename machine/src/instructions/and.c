/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** and.c
*/

#include <stdlib.h>
#include "machine.h"

void *load_var_from_adress(int adress, char *mem, size_t size)
{
    void *val = malloc(size);

    if (!val)
        return NULL;
    for (int i = 0; i < size; ++i)
        ((char *) val)[i] = (mem + adress)[i % MEM_SIZE];
    return val;
}

void load_op_arg(void *dest, vm_t *vm, arginf_t arginf)
{
    ope_t *ope = arginf.ope;
    int adress = arginf.process->pc + ope->args[0] % IDX_MOD;

    switch (ope->type[arginf.argno]) {
        case T_DIR:
            memcpy_size(dest, &(ope->args[arginf.argno]), arginf.arg_size);
            break;
        case T_IND:
            load_to_ptr(dest, adress, vm, sizeof(int));
            break;
        case T_REG:
            load_data_from_reg(&arginf.process->reg[ope->args[arginf.argno]],
            dest, sizeof(int));
    }
}

void and_func(vm_t *vm, process_t *p, ope_t *ope)
{
    int arg1 = 0;
    int arg2 = 0;
    int result = 0;

    loadarg(arg1, 0, sizeof(int));
    loadarg(arg2, 1, sizeof(int));
    result = arg1 & arg2;
    p->reg[ope->args[2]] = result;
}
