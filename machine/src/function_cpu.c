/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** function_cpu.c
*/

#include "my.h"
#include "machine.h"
#include "op.h"
#include <unistd.h>

int *get_args(int index, int fd)
{
    int nb_arg = op_tab[index].nbr_args;
    int *data = malloc(sizeof(int) * (nb_arg + 1));

    for (int args = 0; args < nb_arg; args++) {
        read(fd, &op_tab[index].type[args], sizeof(char));
    }
    for (int i = 0; i < nb_arg; i++) {
        read(fd, &data[i], sizeof(&op_tab[index].type[i]));
    }
    return data;
}

void live(int *option)
{
    my_putstr("The player ");
    my_put_nbr((int)option[0]);
    my_putstr(" is alive..\n");
}

//display array of int

void ld_func(int *option, ram_t *ram, process_t *process)
{
    display_int(option);
    process->reg[option[2]] = option[0];
    process->reg[option[1]] = ram->mem[process->pc + option[2] % IDX_MOD];
}