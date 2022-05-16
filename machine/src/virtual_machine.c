/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** virtual_vmine.c
*/

#include "machine.h"

int get_dump(char *str, char *nbr)
{
    int dump = 0;
    if (my_strcmp(str, "-dump") == 0) {
        dump = my_getnbr(nbr);
    } else {
        dump = -1;
    }
    return dump;
}

vm_t *setup_vm(char **av)
{
    vm_t *vm = malloc(sizeof(vm_t));
    setup_ram(vm);
    vm->process = malloc(sizeof(process_t));
    vm->proc_count = 0;
    vm->cycle = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->dump_cycle = get_dump(av[1], av[2]);
    return vm;
}

int launch_vm(int ac, char *av[])
{
    vm_t *vm = setup_vm(av);

    if (get_nbr_of_champ(av) < 2 || vm->dump_cycle == -1)
        return 84;
    vm->dump_cycle = 1000;
    my_get_opt(vm, ac, av);
    while (1) { // end condition
        for (int i = 0; i < vm->proc_count; ++i) {
            // printf("vm->process[i] : %p\n", vm->process[i]);
            update_process(vm, vm->process[i]);
        }
        vm->cycle += 1;
        if (vm->live_count > NBR_LIVE) {
            vm->cycle_to_die -= CYCLE_DELTA;
            vm->live_count -= NBR_LIVE;
        }
    }
    return 0;
    // TODO destroy each process that have a last live printed more than cycle_to_cie cyles
    // TODO check for win ad loss condition
}
