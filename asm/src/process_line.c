/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** process_line.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "asm.h"
#include "asm_struct.h"
#include "my.h"

typedef void (*size_adjuster_t)(int *, int);
static const size_adjuster_t adjust_size[] = {
    &adjust_live,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    &adjust_zjmp,
    &adjust_ldi,
    &adjust_sti,
    &adjust_fork,
    NULL,
    &adjust_ldi,
    &adjust_fork,
    NULL
};

int write_buffer_from_line(exec_t *ex, buffer_t *buffer, char **line)
{
    char *op;
    int index = 0;

    while (**line == ' ' || **line == '\t')
        ++(*line);
    op = get_substr(line, ' ');
    if (!op[0])
        return 0;
    printf("before op is label, [%s]\n", op);
    if (op_is_label(my_strdup(op))) {
        printf("---> label [%s]\n", op);
        register_new_label(op, ex);
        return write_buffer_from_line(ex, buffer, line);
    }
    printf("--->regular [%s]\n", *line);
    if (!(*line)[0])
        return 0;
    index = get_op_index(op);
    if (index == -1) {
        printf("error index\n");
        exit(84);
    }
    fill_buffer(ex, buffer, line, index);
    printf("buffer: code %d, param_nbr %d\n", buffer->instruct_code, buffer->param_nbr);
    return 1;
}

int process_line(exec_t *ex, char **line)
{
    static int alloc = 1;
    if (alloc) {
        ++(ex->buffer_count);
        ex->buffer = realloc(ex->buffer, sizeof(buffer_t) * (ex->buffer_count));
    }
    printf("\nwritting line: [%s]\n", *line);
    printf("buffer count: %d\n", ex->buffer_count);
    alloc = write_buffer_from_line(ex, &(ex->buffer[ex->buffer_count - 1]),
    line);
    return alloc;
}

char get_type_code_from_size(int size)
{
    switch (size) {
        case T_REG:
            return 0b01;
        case T_DIR:
            return 0b10;
        default:
            return 0b11;
    }
    return 0;
}

void adjust_param_size(int *size, int instruct_code, int param_index)
{
    if (adjust_size[instruct_code - 1])
        adjust_size[instruct_code - 1](size, param_index);
}

int get_param_size_from_type(int type, int param_index, int instruct_code)
{
    int value = 0;

    switch (type) {
        case T_REG:
            value = 1;
            break;
        case T_DIR:
            value = DIR_SIZE;
            break;
        default:
            value = IND_SIZE;
    }
    adjust_param_size(&value, instruct_code, param_index);
    return value;
}
