/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** live.c
*/

#include <stdlib.h>
#include "machine.h"

void live_func(vm_t *vm, process_t *process, ope_t *ope)
{
    my_putstr("The player ");
    my_put_nbr(ope->real_args[0]);
    my_putstr(" (");
    my_putstr(process->name);
    my_putstr(") is alive..\n");
    process->player_id_alive = ope->real_args[1];
    process->last_live = vm->cycle;
    vm->players[(ope->real_args[0]) % MAX_PLAYER_NBR].last_live = vm->cycle;
    vm->live_count += 1;
    vm->last_champ_live = ope->real_args[0];
}
