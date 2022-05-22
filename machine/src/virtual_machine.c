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
    vm->last_champ_live = 0;
    for (int i = 0; i < MAX_PLAYER_NBR; i++) {
        vm->players[i].last_live = 0;
        vm->players[i].is_alive = true;
    }
    return vm;
}

void victory_msg(vm_t *vm)
{
    my_putstr("The player ");
    my_put_nbr(vm->last_champ_live);
    my_putstr(" won !\n");
}

int launch_vm(int ac, char *av[])
{
    vm_t *vm = setup_vm(av);
    if (get_nbr_of_champ(av) < 2 || vm->dump_cycle == -1)
        return 84;
    my_get_option(vm, ac, av);
    display_memory(vm);
    while (kill_processes(vm)) {
        for (int i = 0; i < vm->proc_count; ++i) {
            if (vm->process[i])
                update_process(vm, vm->process[i]);
        }
        vm->cycle += 1;
        if (vm->live_count >= NBR_LIVE) {
            vm->cycle_to_die -= CYCLE_DELTA;
            vm->live_count -= NBR_LIVE;
        }
        dump_display_memory(vm);
    }
    victory_msg(vm);
    return 0;
}
