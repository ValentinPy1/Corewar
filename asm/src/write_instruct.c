/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** write_instruct.c
*/

#include <unistd.h>
#include "endianness.h"
#include "op.h"
#include "asm.h"
#include "my.h"
#include "asm_struct.h"

void invert_endianess(void *var, size_t size)
{
    char *var_c = (char *) var;
    char tmp = 0;

    for (size_t i = 0; i < size / 2; ++i) {
        tmp = var_c[i];
        var_c[i] = var_c[size - i - 1];
        var_c[size - i - 1] = tmp;
    }
}

void register_label(char *op, exec_t *ex)
{
    int len = my_strlen(op);

    if (label_was_forward_declared(op, ex))
        return;
    if (op[len - 1] == ':')
        op[len - 1] = '\0';
    ++(ex->label_count);
    ex->labels = realloc(ex->labels, sizeof(label_t) * ex->label_count);
    ex->labels[ex->label_count - 1].adress = (ex->head);
    ex->labels[ex->label_count - 1].id = my_strdup(op);
    ex->labels[ex->label_count - 1].backward_ref_count = 0;
    ex->labels[ex->label_count - 1].backward_refs = NULL;
}

int get_label_index(char *op, exec_t *ex)
{
    for (size_t i = 0; i < ex->label_count; ++i) {
        if (my_strcmp(op, ex->labels[i].id) == 0)
            return i;
    }
    return -1;
}

int op_is_label(char *op)
{
    printf("in op_is_label\n");
    if (op[my_strlen(op) - 1] != LABEL_CHAR) {
        free(op);
        return 0;
    }
    free(op);
    return 1;
}

int write_instruct(char **line, exec_t *ex)
{
    char *op = get_substr(line, ' ');
    int index = 0;

    if (!op)
        return -1;
    if (op_is_label(op)) {
        free(op);
        return -2;
    }
    index = get_op_index(op);
    if (index < 0) {
        free(op);
        return -1;
    }
    free(op);
    wexec((&op_tab[index].code), sizeof(char), ex);
    return index;
}
