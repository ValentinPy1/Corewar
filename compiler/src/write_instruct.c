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

int write_instruct(char **line, int fd)
{
    char *op = get_substr(line, ' ');
    int index = 0;

    if (!op)
        return -1;
    index = get_op_index(op);
    if (index < 0) {
        free(op);
        return -1;
    }
    write(fd, &op_tab[index].code, sizeof(char));
    return 0;
}
