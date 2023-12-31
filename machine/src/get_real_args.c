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
    int mod_adress = 0;

    if (size == IND_SIZE) {
        *((int *) ptr) = 0;
        *((int *) ptr) = get_index_value(vm, adress);
        return;
    }
    for (int i = 0; i < size; ++i) {
        mod_adress = (adress + i) % MEM_SIZE;
        if (mod_adress < 0)
            mod_adress = MEM_SIZE - mod_adress;
        ((char *) ptr)[i] = (vm->ram->mem)[mod_adress];
    }
}

int load_arg(vm_t *vm, int adress, int i, ope_t *ope)
{
    int tmp = 0;
    switch (ope->size_type[i]) {
        case 1:
            set_val(tmp, char, vm, adress);
            break;
        case 2:
            set_val(tmp, short, vm, adress);
            break;
        case 4:
            set_val(tmp, int, vm, adress);
            break;
        default:
            tmp = 1;
    }
    invert_endianess(&tmp, ope->size_type[i]);
    return tmp;
}