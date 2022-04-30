/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** virtual_machine.c
*/

#include "op.h"
#include "my.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

static const event_t MNEMONIC[2] = {
    {&live},
    {&ld_func}
};

void get_data(void)
{
    int data = 0;
    int *option;
    cpu_t *cpu = constructor();
    int fd = open("42.cor", O_RDONLY);

    read(fd, &data, sizeof(char));
    data -= 1;
    if (data > 16 || data < 1)
        printf("%i: Naah invalid index\n", data);
    else {
        option = get_args(data, fd);
        MNEMONIC[data].func(option);
    }
}
