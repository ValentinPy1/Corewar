/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** register_load.c
*/

#include "machine.h"

void load_data_in_reg(int *reg, void *data, size_t data_size)
{
    for (int i = 0; i < data_size; ++i) {
        reg[i] = ((int *) data)[i];
    }
}

void load_data_from_reg(int *reg, void *data, size_t data_size)
{
    for (int i = 0; i < data_size; ++i) {
        ((int *) data)[i] = reg[i];
    }
}

void load_data_to_mem(int adress, void *data, int data_size, vm_t *vm)
{
    adress %= MEM_SIZE;
    if (adress < 0)
        adress = MEM_SIZE - adress;
    for (int i = 0; i < data_size; ++i) {
        (vm->ram->mem)[(adress + i) % MEM_SIZE] = ((char *) data)[i];
    }
}
