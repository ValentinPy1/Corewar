/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** label_reference.c
*/

#include <stdlib.h>
#include "asm_struct.h"

void add_label_reference(exec_t *ex, int i, int delta_head, int param_n)
{
    int j = 0;

    ++(ex->labels[i].backward_ref_count);
    ex->labels[i].backward_refs = realloc(ex->labels[i].backward_refs,
    ex->labels[i].backward_ref_count * sizeof(ref_t));
    ex->labels[i].backward_refs[ex->labels[i].backward_ref_count - 1].head
    = ex->head;
    ex->labels[i].backward_refs[ex->labels[i].backward_ref_count - 1].size
    = delta_head;
    ex->labels[i].backward_refs[ex->labels[i].backward_ref_count - 1].arg_nbr
    = param_n;
    while (j < MAX_ARGS_NUMBER && ex->tmp_refs[j] == NULL)
        ++j;
    ex->tmp_refs[j]
    = &(ex->labels[i].backward_refs[ex->labels[i].backward_ref_count - 1]);
}
