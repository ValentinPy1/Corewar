/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main.c
*/

#include "my.h"
#include <stdio.h>
// #include "op.h"

int get_data();

int main(int ac, char **av)
{
    FILE *fd = fopen("example.yolotron", "r");
    char *buffer = NULL;
    size_t len = 0;
    while (getline(&buffer, &len, fd) != -1) {
        printf("%s\n", buffer);
        calcule(buffer);
    }
    return 0;
}