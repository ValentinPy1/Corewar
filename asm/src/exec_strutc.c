/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** exec_strutc.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "asm.h"
#include "asm_struct.h"

exec_t *new_exec(void)
{
    exec_t *new = malloc(sizeof(exec_t));

    if (!new)
        return NULL;
    new->binary = NULL;
    new->size = 0;
    new->head = 0;
    new->prev_head = 0;
    new->labels = NULL;
    new->label_count = 0;
    new->buffer = NULL;
    new->buffer_count = 0;
    new->head_last_instruct = 0;
    return new;
}

void destroy_exec(exec_t *exec)
{
    if (!exec)
        return;
    free(exec->binary);
    free(exec);
}

void wexec(void *data, size_t data_size, exec_t *dest)
{
    size_t new_size = dest->size;

    if (new_size == 0) {
        new_size = 1;
        dest->binary = malloc(sizeof(char));
        if (!dest->binary)
            return;
    }
    while (dest->head + data_size >= new_size)
        new_size *= 2;
    if (new_size != dest->size) {
        dest->binary = realloc(dest->binary, new_size);
        dest->size = new_size;
    }
    dest->prev_head = dest->head;
    for (size_t i = 0; i < data_size; ++i) {
        dest->binary[(dest->head)++] = ((char *) data)[i];
    }
}

static void synch_label_backward_refs(exec_t *ex)
{
    for (size_t i = 0; i < ex->label_count; ++i) {
        if (ex->labels[i].backward_ref_count == 0)
            continue;
        for (int j = 0; j < ex->labels[i].backward_ref_count; ++j) {
            wexec_at(&(ex->labels[i].adress),
            ex->labels[i].backward_refs[j].head,
            ex->labels[i].backward_refs[j].size, ex);
        }
    }
}

void write_exec_to_file(exec_t *exec, char *filepath, header_t *header)
{
    int fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC, 0777);

    if (fd == -1)
        return;
    if (there_are_undeclared_labels(exec)) {
        close(fd);
        return;
    }
    synch_label_backward_refs(exec);
    write_header(header, exec, fd);
    write(fd, exec->binary, exec->head);
    close(fd);
}

