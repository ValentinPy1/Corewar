/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** continue_writting_line.c
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "asm_struct.h"

// int continue_writting_line(char **line, exec_t *ex)
// {
//     if (!((*line)[0]))
//         return 0;
//     return convert_line(line, ex);
// }

void write_label_backwards(char *label, exec_t *ex)
{
    for (size_t i = 0; i < ex->label_count; ++i) {
        if (my_strcmp(label, ex->labels[i].id) == 0
        && ex->labels[i].adress == -1) {
            ex->labels[i].adress = ex->head;
            return;
        }
    }
}

void declare_label(char **line, exec_t *ex)
{
    char *label = get_label_on_line(line);
    if (label == NULL)
        return;
    if (label_was_forward_declared(label, ex)) {
        write_label_backwards(label, ex);
    } else {
        register_label(label, ex);
    }
}
