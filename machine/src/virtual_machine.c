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
    // TODO setup dump cycle in my_get_opt
    return vm;
}

void launch_vm(int ac, char *av[])
{
    vm_t *vm = setup_vm();
    if (get_nbr_of_champ(av) < 2)
        return;

    my_get_opt(vm, ac, av);
    for (int i = 0; i < vm->proc_nbr; ++i)
        update_process(vm, vm->process[i]);
    vm->cycle += 1;
    if (vm->live_count > NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->live_count -= NBR_LIVE;
    }
    // TODO destroy each process that have a last live printed more than cycle_to_cie cyles
    // TODO check for win ad loss condition
}

// -n optionnel