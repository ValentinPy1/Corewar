/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** virtual_vmine.c
*/

#include "machine.h"

vm_t *setup_vm(void)
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
    // TODO reapeat for each file in args with right player flag

    for (int i = 0; i < vm->proc_nbr; ++i)
        update_process(vm, vm->process[i]);
    vm->cycle += 1;
    if (vm->live_count > NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->live_count -= NBR_LIVE;
    }
    // TODO destroy each process that have a last live printed more than cycle_to_cie cyles
}
