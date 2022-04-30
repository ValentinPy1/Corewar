/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main.c
*/

#include "my.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"
#include <unistd.h>

static void writer(char *filename, char *str)
{
    int fd = open(filename, O_CREAT | O_WRONLY, 0666); // | O_APPEND
    write(fd, &str, sizeof(char));
}

int main(int ac, char **av)
{
    get_data();
    return 0;
}


