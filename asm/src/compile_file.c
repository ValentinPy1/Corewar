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
#include "asm_struct.h"

static int file_doesnt_exist(const char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd < 0) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

static char *get_exec_name(char *path)
{
    int len = my_strlen(path);
    char *exec_name;
    int i = 0;

    if (file_doesnt_exist(path))
        exit(84);
    len += (len > 2 && path[len - 2] == '.' && path[len - 1] == 's') ? 2 : 4;
    exec_name = malloc(sizeof(char) * (len + 1));
    if (exec_name == NULL)
        return (NULL);
    while (path[i] && path[i] != '.') {
        exec_name[i] = path[i];
        ++i;
    }
    exec_name[i++] = '.';
    exec_name[i++] = 'c';
    exec_name[i++] = 'o';
    exec_name[i++] = 'r';
    exec_name[i++] = '\0';
    return exec_name;
}

static int write_line_executable(FILE *src, exec_t *ex)
{
    size_t len = 0;
    char *line = NULL;

    while (getline(&line, &len, src) != -1) {
        if (*line == '\n' || *line == COMMENT_CHAR || *line == '\0')
            continue;
        remove_final_newline(line);
        line[len - 1]  = '\0';
        process_line(ex, &line);
        len = 0;
    }
    return (0);
}

static int write_executable(char *filename, char *exec_file)
{
    FILE *src = fopen(filename, "r");
    exec_t *ex = new_exec();
    header_t *header = get_header(src);

    if (!src)
        return 84;
    write_line_executable(src, ex);
    fclose(src);
    write_exec_binary(ex);
    output_binary_to_file(exec_file, ex, header);
    return 0;
}

int compile_file(char *filename)
{
    char *exec_file = get_exec_name(filename);

    if (!exec_file)
        return 84;
    if (write_executable(filename, exec_file))
        return 84;
    free(exec_file);
    return 0;
}
