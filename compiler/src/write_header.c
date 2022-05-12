/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** write_header.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"
#include "asm_struct.h"
#include "op.h"

void remove_final_double_quotes(char *str)
{
    int len = my_strlen(str);

    while (len > 1) {
        if (str[len] == '"' && str[len - 1] != '\\') {
            str[len] = '\0';
            break;
        }
        --len;
    }
}

void get_comment_and_name(header_t *header, char *line)
{
    while (*line && *line == ' ')
        ++line;
    if (line[0] != '.')
        return;
    switch (line[1]) {
        case 'c':
            my_strcpy(header->comment, line +
            get_char_index_in_str(line, '"') + 1);
            remove_final_double_quotes(header->comment);
            break;
        case 'n':
            my_strcpy(header->prog_name, line +
            get_char_index_in_str(line, '"') + 1);
            remove_final_double_quotes(header->prog_name);
            break;
        default:
            break;
    }
}

header_t *get_header(FILE *file)
{
    header_t *header = malloc(sizeof(header_t));
    size_t len = 0;
    char *line = NULL;

    if (!header)
        return NULL;
    while (getline(&line, &len, file) != -1) {
        if (line[0] != '#' && line[0] != '\n')
            break;
    }
    get_comment_and_name(header, line);
    while (getline(&line, &len, file) != -1) {
        if (line[0] != '#' && line[0] != '\n')
            break;
    }
    get_comment_and_name(header, line);
    return header;
}

void write_header(header_t *header, exec_t *exec, int fd)
{
    header->prog_size = my_strlen(exec->binary);
    write(fd, header, sizeof(header_t));
}
