/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get_real_args.c
*/

#include "machine.h"
#include "asm.h"
#include "special_loaders.h"

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
    if (size == IND_SIZE) {
        *((int *) ptr) = 0;
        *((int *) ptr) = get_index_value(vm, adress);
        return;
    }
    for (int i = 0; i < size; ++i)
        ((char *) ptr)[i] = (vm->ram->mem + adress)[i];
}

int load_arg(vm_t *vm, int adress, int i, ope_t *ope, process_t *process)
{
    int tmp = 0;

    load_to_ptr(&tmp, adress, vm, ope->size_type[i]);
    invert_endianess(&tmp, ope->size_type[i]);
    return tmp;
}

int load_real_arg_special(vm_t *vm,
ope_t *ope, int adress, process_t *process)
{
    if (special_loaders[ope->code - 1]) {
        special_loaders[ope->code - 1](vm, process, ope, adress);
        return 1;
    }
    return 0;
}

void get_op_real_args(vm_t *vm, ope_t *ope, int adress, process_t *process)
{
    int arg_nbr = op_tab[ope->code - 1].nbr_args;
    if (load_real_arg_special(vm, ope, adress, process))
        return;
    for (int i = 0; i < arg_nbr; ++i) {
        for (int j = 0; j < ope->size_type[i]; ++j)
            ope->real_args[i] = load_arg(vm, adress, i, ope, process);
        adress += ope->size_type[i];
    }
}
