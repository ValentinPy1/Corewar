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

void invert_endianess(void *var, size_t size);
int get_param_value(param_t param, exec_t *ex);
int get_param_size_from_type(int type, int param_index, int instruct_code);
int get_param_size_from_type(int type, int param_index, int instruct_code);
void write_header(header_t *header, exec_t *exec, int fd);
char get_type_code_from_size(int size);

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