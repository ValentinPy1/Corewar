/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** remove_final_new_line.c
*/

#include "my.h"

void remove_final_newline(char *line)
{
    int i = my_strlen(line);

    while (i > 0) {
        if (line[i] == '\n') {
            line[i] = '\0';
            break;
        }
        --i;
    }
}
