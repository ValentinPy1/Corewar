/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** register_load.c
*/

#include "machine.h"

void load_data_in_reg(char *reg, void *data, size_t data_size)
{
    for (int i = 0; i < data_size; ++i) {
        reg[i] = ((char *) data)[i];
    }
}

void load_data_from_reg(char *reg, void *data, size_t data_size)
{
    for (int i = 0; i < data_size; ++i) {
        ((char *) data)[i] = reg[i];
    }
}
