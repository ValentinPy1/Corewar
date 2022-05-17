/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** label
*/
#include "asm_struct.h"
#include <stdio.h>
#include "my.h"
#include <stdlib.h>
#include "asm.h"

static void compare_label(char *label, exec_t *ex, int *out)
{
    for (size_t i = 0; i < ex->label_count; ++i) {
        printf("comparing new label [%s] to existing [%s]\n", label, ex->labels[i].id);
        if (my_strcmp(label, ex->labels[i].id) == 0) {
            *out = ex->labels[i].adress != -1;
            ex->labels[i].adress = ex->tmp_head;
            printf("labels adress = %d\n", ex->tmp_head);
            break;
        }
    }
}

void register_new_label(char *label, exec_t *ex)
{
    int out = -1;
    printf("register_new_label: [%s]\n", label);
    remove_ending_char(label, ':');
    printf("label is [%s], label count is %zu\n", label, ex->label_count);
    
    compare_label(label, ex, &out);
    if (out == 1)
        exit(84);
    else if (out == 0)
        return;
    ++(ex->label_count);
    ex->labels = realloc(ex->labels, ex->label_count * sizeof(label_t));
    ex->labels[ex->label_count - 1].id = my_strdup(label);
    ex->labels[ex->label_count - 1].adress = ex->tmp_head;
    ex->labels[ex->label_count - 1].backward_ref_count = 0;
    ex->labels[ex->label_count - 1].backward_refs = NULL;
}


int register_new_label_forward(char *label, exec_t *ex)
{
    size_t i = 0;
    printf("registering label forward\n");
    for (; i < ex->label_count; i++) {
        printf("comparing this label [%s] to existing [%s]\n", label, ex->labels[i].id);
        if (my_strcmp(ex->labels[i].id, label) == 0) {
            printf("found that this label [%s] existed at index [%zu]\n", label, i);
            break;
        }
    }
    if (i == ex->label_count) {
        ex->labels = realloc(ex->labels, ++(ex->label_count)
        * sizeof(label_t));
    }
    ex->labels[i].id = my_strdup(label);
    ex->labels[i].adress = -1;
    return (int) i;
}

void buffer_set_as_label(buffer_t *buffer, exec_t *ex, char *label, int i)
{
    int index = get_label_index(label, ex);

    if (index == -1)
        index = register_new_label_forward(label, ex);
    buffer->params[i].value = index;
}

bool is_param_label(exec_t *ex, buffer_t *buffer, char *param, int i)
{
    char *label = NULL;

    buffer->params[i].is_label = false;
    if (param[0] != LABEL_CHAR)
        return false;
    buffer->params[i].is_label = true;
    label = get_label_from_param(++param);
    buffer_set_as_label(buffer, ex, label, i);
    printf("param is label\n");
    ex->tmp_head += get_param_size_from_type(buffer->params[i].size, i,
    buffer->instruct_code);
    return true;
}