/*
** EPITECH PROJECT, 2022
** write_binary
** File description:
** source code to write binarty
*/
#include "asm_struct.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "asm.h"

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
    wexec(&byte, sizeof(char), ex);
}

void write_buffer_to_bin(exec_t *ex, buffer_t buffer)
{
    int value = 0;
    int size = 0;

    ex->head_last_instruct = ex->head;
    wexec(&(buffer.instruct_code), sizeof(char), ex);
    if (!(buffer.instruct_code == 1 || buffer.instruct_code == 9
    || buffer.instruct_code == 12 || buffer.instruct_code == 15))
        write_encoding_byte(buffer, ex);
    for (int i = 0; i < buffer.param_nbr; ++i) {
        value = get_param_value(buffer.params[i], ex);
        size = get_param_size_from_type(buffer.params[i].size, i,
        buffer.instruct_code);
        invert_endianess(&value, size);
        wexec(&value, size, ex);
    }
}

void write_exec_binary(exec_t *ex)
{
    for (size_t i = 0; i < ex->label_count; ++i) {
    }
    for (int i = 0; i < ex->buffer_count; ++i) {
        write_buffer_to_bin(ex, ex->buffer[i]);
    }
}

void output_binary_to_file(char *filepath, exec_t *ex, header_t *header)
{
    int fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (fd < 0) {
        exit(84);
    }
    write_header(header, ex, fd);
    write(fd, ex->binary, ex->head);
    close(fd);
}