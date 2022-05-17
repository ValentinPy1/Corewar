/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** virtual_vmine.c
*/

#include "machine.h"

int get_dump(char **av)
{
    int dump = 0;
    for (int i = 0; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-dump") == 0) {
            dump = my_getnbr(av[i + 1]);
            return dump;
        }
    }
    return -1;
}

vm_t *setup_vm(char **av)
{
    vm_t *vm = malloc(sizeof(vm_t));
    setup_ram(vm);
    vm->process = malloc(sizeof(process_t));
    vm->proc_count = 0;
    vm->cycle = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->dump_cycle = get_dump(av);
    vm->live_count = 0;
    for (int i = 0; i < MAX_PLAYER_NBR; i++) { //////////////////////////////////////WTF
        vm->players[i].last_live = 0;
        vm->players[i].is_alive = true;
    }
    return vm;
}

int launch_vm(int ac, char *av[])
{
    vm_t *vm = setup_vm(av);
    if (get_nbr_of_champ(av) < 2 || vm->dump_cycle == -1)
        return 84;
    my_get_opt(vm, ac, av);
    while (battle_hasnt_ended(vm)) { // end condition
        for (int i = 0; i < vm->proc_count; ++i) {
            // printf("accessing process n°%d. cycle to wait = %d\n", i, vm->process[i]->wait);
            if (vm->process[i] == NULL)
                continue;
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
