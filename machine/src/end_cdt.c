/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** end_cdt.c
*/

#include <stdbool.h>
#include "machine.h"

void destroy_process(process_t *process)
{
    free(process->reg);
    free(process->current_ope);
    free(process);
}

static bool players_are_different(process_t *process, int prev_id)
{
    if (prev_id != -1 && prev_id == process->player_id_alive)
        return false;
    return true;
}

static void kill_process(int i, vm_t *vm)
{
    destroy_process(vm->process[i]);
    vm->process[i] = NULL;
}

static bool kill_dead_processes(vm_t *vm)
{
    for (int i = 0; i < vm->proc_count; ++i) {
        if (vm->process[i] == NULL)
            continue;
        if (ABS(vm->process[i]->last_live - vm->cycle) > CYCLE_TO_DIE) {
            kill_process(i, vm);
        }
    }
    for (int i = 0; i < vm->proc_count; ++i) {
        if (vm->process[i] != NULL)
            return false;
    }
    return true;
}

bool battle_hasnt_ended(vm_t *vm)
{
    int prev_id = -1;

    if (kill_dead_processes(vm))
        return false;
    for (int i = 0; i < vm->proc_count; i++) {
        if (players_are_different(vm->process[i], prev_id)) {
            return true;
        }
        if (vm->process[i]->player_id_alive != -1)
            prev_id = vm->process[i]->player_id_alive;
    }
    return false;
}
