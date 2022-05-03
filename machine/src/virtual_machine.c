/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** virtual_vmine.c
*/

#include "machine.h"

static const event_t MNEMONIC[2] = {
    {&live},
    {&ld_func}
};

vm_t *setup_vmine(void)
{
    vm_t *vm = malloc(sizeof(vm_t));
    vm->ram = setup_ram();
    vm->process = NULL;
    vm->proc_nbr = 0;
    vm->cycle = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    return vm;
}

void launch_vm(int ac, char *av[])
{
    vm_t *vm = setup_vm();

    load_prog(vm, av[1], atoi(av[2]), atoi(av[3]));
}


// void get_data(char *path)
// {
//     int data = 0;
//     int *option;
//     int fd = open(path, O_RDONLY);

//     read(fd, &data, sizeof(char));
//     data -= 1;
//     printf("data : %d\n", data);
//     // if (data > 16 || data < 1)
//     //     write(1, "Naah invalid index\n", 20);
//     // else {
//         option = get_args(data, fd);
//         MNEMONIC[data].func(option, ram, process);
//     // }
// }
