/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** compile_file.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"
#include "op.h"
#include "my.h"


char *get_exec_name(char *filename)
{
    int len = my_strlen(filename);
    char *exec_name;
    int i = 0;

    len += (len > 2 && filename[len - 2] == '.' && filename[len - 1] == 's') ?
    2 : 4;
    exec_name = malloc(sizeof(char) * (len + 1));
    if (exec_name == NULL)
        return (NULL);
    while (filename[i] && filename[i] != '.') {
        exec_name[i] = filename[i];
        ++i;
    }
    exec_name[i++] = '.';
    exec_name[i++] = 'c';
    exec_name[i++] = 'o';
    exec_name[i++] = 'r';
    exec_name[i++] = '\0';
    return exec_name;
}

int convert_line(char **line, int fd)
{
    int index = write_instruct(line, fd);

    return 0;
}

int write_executable(int fd, char *filename)
{
    size_t len = 0;
    char *line = NULL;
    FILE *src = fopen(filename, "r");

    if (!src)
        return 84;
    while (getline(&line, &len, src) != -1) {
        if (*line == '\n' || *line == '#')
            continue;
        line[len - 1]  = '\0';
        if (convert_line(&line, fd)) {
            free(line);
            fclose(src);
            return 84;
        }
    }
    fclose(src);
    return 0;
}

int compile_file(char *filename)
{
    char *exec_file = get_exec_name(filename);
    int fd;

    if (!exec_file)
        return 84;
    fd = open(exec_file, O_RDWR | O_CREAT, 0771);
    if (fd < 0 || write_executable(fd, filename)) {
        free(exec_file);
        if (fd <= 0)
            close(fd);
        return 84;
    }
    free(exec_file);
    close(fd);
    return 0;
}
