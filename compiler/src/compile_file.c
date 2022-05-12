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

static char *get_exec_name(char *filename)
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

// int convert_line(char **line, exec_t *ex)
// {
//     char *tmp = my_strdup(*line);
//     int index = write_instruct(line, ex);

//     if (index == -2) {
//         declare_label(&tmp, ex);
//         return continue_writting_line(line, ex);
//     }
//     free(tmp);
//     if (index < 0 || write_parameters(line, ex, index))
//         return -1;
//     return 0;
// }

static int write_executable(char *filename, char *exec_file)
{
    size_t len = 0;
    char *line = NULL;
    FILE *src = fopen(filename, "r");
    exec_t *ex = new_exec();
    header_t *header = get_header(src); //TODO: KEEP THIS LINE FOR LATER, WORKS FINE

    if (!src)
        return 84;
    while (getline(&line, &len, src) != -1) {
        if (*line == '\n' || *line == COMMENT_CHAR || *line == '\0')
            continue;
        remove_final_newline(line);
        line[len - 1]  = '\0';
        //process_this_line
        if (process_line(ex, &line)) {

        }
        len = 0;
    }
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
