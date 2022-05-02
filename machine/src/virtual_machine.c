/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** virtual_machine.c
*/

#include "op.h"
#include "machine.h"
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
    ram_t *ram = constructor_ram();
    process_t **process = constructor_process(2);
    int fd = open("oui.cor", O_RDONLY);

    read(fd, &data, sizeof(char));
    data -= 1;
    printf("data : %d\n", data);
    // if (data > 16 || data < 1)
    //     write(1, "Naah invalid index\n", 20);
    // else {
        option = get_args(data, fd);
        MNEMONIC[data].func(option, ram, process);
    // }
}
