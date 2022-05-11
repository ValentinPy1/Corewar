/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** write_exec_at.c
*/

#include <unistd.h>
#include "asm_struct.h"
#include "asm.h"

void wexec_at(void *data, int index, size_t size, exec_t *ex)
{
    int backup = ex->head;

    ex->head = index;
    wexec(data, size, ex);
    ex->head = backup;
}
