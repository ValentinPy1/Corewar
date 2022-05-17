/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** display_memory.c
*/

#include "machine.h"

void my_put_nbr_base(int nbr, char *base)
{
    int len = my_strlen(base);
    int n = nbr;
    int i = 0;

    if (nbr < 0) {
        my_putchar('-');
        n = -nbr;
    }
    if (n == 0) {
        my_putchar('0');
    }
    while (n != 0) {
        i = n % len;
        my_putchar(base[i]);
        n = n / len;
    }
}

void dipslay_memory(vm_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0)
            my_putstr("\n");
        my_put_nbr_base(vm->ram->mem[i], "0123456789abcdef");
        my_putstr(" ");
    }
}