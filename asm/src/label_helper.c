/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** label_helper.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "asm.h"
#include "asm_struct.h"

void register_forward_label(char *op, exec_t *exec, int delta_head)
{
    ++(exec->label_count);
    exec->labels = realloc(exec->labels, exec->label_count * sizeof(label_t));
    exec->labels[exec->label_count - 1].adress = -1;
    add_label_reference(exec, exec->label_count - 1, delta_head);
    if (op == NULL) {
        exec->labels[exec->label_count - 1].id = NULL;
        return;
    }
    exec->labels[exec->label_count - 1].id = my_strdup(op);
}

bool label_was_forward_declared(char *op, exec_t *ex)
{
    bool error = false;
    bool exit_status = false;

    for (size_t i = 0; i < ex->label_count; ++i) {
        if (my_strcmp(op, ex->labels[i].id) == 0) {
            error = (ex->labels[i].adress != -1);
            ex->labels[i].adress = ex->head;
            exit_status = true;
            break;
        }
    }
    if (error)
        exit(84);
    return exit_status;
}

bool there_are_undeclared_labels(exec_t *exec)
{
    for (size_t i = 0; i < exec->label_count; ++i) {
        if (exec->labels[i].adress == -1)
            return true;
    }
    return false;
}

int get_label_adress(char *label, exec_t *exec)
{
    for (size_t i = 0; i < exec->label_count; ++i) {
        if (my_strcmp(label, exec->labels[i].id) == 0)
            return exec->labels[i].adress;
    }
    return -1;
}

char *get_label_on_line(char **str)
{
    int i = 0;
    char *label = NULL;
    while ((*str)[i] && get_char_index_in_str(LABEL_CHARS, (*str)[i]) != -1)
        ++i;
    label = malloc(sizeof(char) * (i + 1));
    if (label == NULL)
        return NULL;
    my_strncpy(label, *str, i);
    label[i] = '\0';
    if (label[i - 1] == ':')
        label[i - 1] = 0;
    *str = *str + i;
    while (**str && **str != ' ' && **str != '\t')
        ++(*str);
    return label;
}
