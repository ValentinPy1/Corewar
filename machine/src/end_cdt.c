/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** end_cdt.c
*/

#include <stdbool.h>
#include "machine.h"

bool kill_process(vm_t *vm, process_t *process)
{
    if (vm->cycle - process->last_live < vm->cycle_to_die)
        return true;
    free(process);
    return false;
}

bool kill_processes(vm_t *vm)
{
    bool is_proc_alive = false;
    for (int i = 0; i < vm->proc_count; ++i) {
        if (vm->process[i])
            is_proc_alive |= kill_process(vm, vm->process[i]);
    }
    return is_proc_alive;
}
