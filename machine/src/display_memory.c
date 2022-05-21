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

void display_memory(vm_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0)
            my_putstr("\n");
        my_put_nbr_base(vm->ram->mem[i % MEM_SIZE], "0123456789abcdef");
        my_putstr(" ");
    }
    my_putstr("\n");
}

void dump_display_memory(vm_t *vm)
{
    static int i = 0;

    if (i == vm->dump_cycle) {
        display_memory(vm);
        i = 0;
    }
    i++;
}
