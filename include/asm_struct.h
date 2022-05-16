/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm_struct.h
*/

#ifndef A32242A8_6430_4F6E_A907_E7FA25EA563F
    #define A32242A8_6430_4F6E_A907_E7FA25EA563F
    #include <stddef.h>
    #include <stdbool.h>
    #include "op.h"

typedef struct ref_s ref_t;
struct ref_s {
    int head;
    int size;
    int arg_nbr;
};

typedef struct label_s label_t;
struct label_s {
    char *id;
    int adress;
    ref_t *backward_refs;
    int backward_ref_count;
};

typedef struct param_s param_t;
struct param_s {
    int size;
    bool is_label;
    int value;
};

typedef struct buffer_s buffer_t;
struct buffer_s {
    int instruct_code;
    int param_nbr;
    param_t params[MAX_ARGS_NUMBER];
};

typedef struct exec_s exec_t;
struct exec_s {
    char *binary;
    int head;
    int prev_head;
    int tmp_head;
    size_t size;
    size_t label_count;
    label_t *labels;
    ref_t *tmp_refs[MAX_ARGS_NUMBER];

    buffer_t *buffer;
    int buffer_count;
    int head_last_instruct;

};

exec_t *new_exec(void);
void destroy_exec(exec_t *exec);
void wexec(void *data, size_t data_size, exec_t *dest);
void write_exec_to_file(exec_t *exec, char *filepath, header_t *header);

#endif
