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

void remove_ending_char(char *str, char c)
{
    int i = my_strlen(str);

    while (i > 0 && str[i] != c)
        --i;
    if (str[i] == c)
        str[i] = '\0';
}

void register_new_label(char *label, exec_t *ex)
{
    int out = -1;
    printf("register_new_label: [%s]\n", label);
    remove_ending_char(label, ':');
    printf("label is [%s], label count is %zu\n", label, ex->label_count);
    for (size_t i = 0; i < ex->label_count; ++i) {
        printf("comparing new label [%s] to existing [%s]\n", label, ex->labels[i].id);
        if (my_strcmp(label, ex->labels[i].id) == 0) {
            out = ex->labels[i].adress != -1;
            ex->labels[i].adress = ex->tmp_head;
            printf("labels adress = %d\n", ex->tmp_head);
            break;
        }
    }
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
    printf("label [%s] adress is [%d]\n", label, ex->labels[ex->label_count - 1].adress);
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

void get_param(exec_t *ex, buffer_t *buffer, char **line, int i)
{
    char *param = get_substr(line, ',');
    printf("getting param [%s]\n", param);
    if (!param)
        return;
    while (*param && *param == ' ')
         ++param;
    switch (param[0]) {
        case 'r':
            ++param;
            buffer->params[i].size = T_REG;
            break;
        case DIRECT_CHAR:
            ++param;
            buffer->params[i].size = T_DIR;
            break;
        default:
            buffer->params[i].size = T_IND;
    }
    if (is_param_label(ex, buffer, param, i))
        return;
    ex->tmp_head += get_param_size_from_type(buffer->params[i].size, i,
    buffer->instruct_code);
    printf("--------------------------head += %d\n", get_param_size_from_type(buffer->params[i].size, i, buffer->instruct_code));
    buffer->params[i].value = my_getnbr(param);
}

void put_params_in_buffer(exec_t *ex, buffer_t *buffer, char **line)
{
    for (int i = 0; i < buffer->param_nbr; ++i) {
        get_param(ex, buffer, line, i);
    }
}

int get_head_delta_from_func(int instruct_code)
{
    printf("instruct code is %d, [%s]\n", instruct_code, op_tab[instruct_code - 1].mnemonique);
    if ((instruct_code == 1 || instruct_code == 9
    || instruct_code == 12 || instruct_code == 15)) {
        printf("delta is 1\n");
        return 1;
    }
    printf("detla is 2\n");
    return 2;
}

int fill_buffer(exec_t *ex, buffer_t *buffer, char **line, int op_index)
{
    buffer->instruct_code = op_tab[op_index].code;
    ex->tmp_head += get_head_delta_from_func(buffer->instruct_code);
    printf("---------------code is %d---------head(instruct and encoding) += %d\n",buffer->instruct_code, get_head_delta_from_func(buffer->instruct_code));
    buffer->param_nbr = op_tab[op_index].nbr_args;
    put_params_in_buffer(ex, buffer, line);
    return 0;
}

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

int get_sum_param_len(buffer_t buffer)
{
    int sum = 0;

    for (int i = 0; i < buffer.param_nbr; ++i) {
        sum += buffer.params[i].size;
    }
    return sum;
}

int get_param_value(param_t param, exec_t *ex)
{
    if (!(param.is_label)) {
        return param.value;
    }
    printf("value is a label\n");
    // printf("param is a label, label index = [%d], adress [%d], id [%s]\n", param.value, ex->labels[param.value].adress, ex->labels[param.value].id);
    return ex->labels[param.value].adress - ex->head_last_instruct;
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

void write_encoding_byte(buffer_t buffer, exec_t *ex)
{
    char byte = 0;
    char tmp = 0;
    int i = 0;

    for (; i < buffer.param_nbr; ++i) {
        tmp = get_type_code_from_size(buffer.params[i].size);
        byte <<= 2;
        byte |= tmp;
    }
    while (i++ < 4)
        byte <<= 2;
    printf("--->byte : %x\n", byte);
    wexec(&byte, sizeof(char), ex);
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


void write_buffer_to_bin(exec_t *ex, buffer_t buffer)
{
    int value = 0;
    int size = 0;
    printf("------\n");
    printf("instruct code is %d, [%s]\n", buffer.instruct_code, op_tab[buffer.instruct_code - 1].mnemonique);

    ex->head_last_instruct = ex->head;
    wexec(&(buffer.instruct_code), sizeof(char), ex);
    if (!(buffer.instruct_code == 1 || buffer.instruct_code == 9
    || buffer.instruct_code == 12 || buffer.instruct_code == 15))
        write_encoding_byte(buffer, ex);
    for (int i = 0; i < buffer.param_nbr; ++i) {
        value = get_param_value(buffer.params[i], ex);
        size = get_param_size_from_type(buffer.params[i].size, i,
        buffer.instruct_code);
        printf("value: %d, size %d\n", value, get_param_size_from_type(buffer.params[i].size, i, buffer.instruct_code));
        invert_endianess(&value, size);
        wexec(&value, size, ex);
    }
}

void write_exec_binary(exec_t *ex)
{
    printf("before converting to binary, here are the labels:\n");
    for (size_t i = 0; i < ex->label_count; ++i) {
        printf("[%s][%d]\n", ex->labels[i].id, ex->labels[i].adress);
    }
    printf("\nconverting buffer to binary...\n");
    for (int i = 0; i < ex->buffer_count; ++i) {
        write_buffer_to_bin(ex, ex->buffer[i]);
    }
}

void output_binary_to_file(char *filepath, exec_t *ex, header_t *header)
{
    int fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    printf("----\nwritting output\n");
    if (fd < 0) {
        printf("error fd\n");
        exit(84);
    }
    printf("sizeof(header) = %zu\n", sizeof(header_t));
    write_header(header, ex, fd);
    write(fd, ex->binary, ex->head);
    close(fd);
}
