/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main.c
*/

#include "machine.h"

static void writer(char *filename, char *str)
{
    int fd = open(filename, O_CREAT | O_WRONLY, 0666); // | O_APPEND

    write(fd, &str, sizeof(char));
}

int main(int ac, char **av)
{
    if (launch_vm(ac, av) == 84)
        return 84;
    return 0;
}
