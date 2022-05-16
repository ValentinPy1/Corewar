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
