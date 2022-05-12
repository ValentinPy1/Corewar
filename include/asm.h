/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm.h
*/

#ifndef D65B1F03_6566_4A0A_AC5E_1E78CE3A97B0
    #define D65B1F03_6566_4A0A_AC5E_1E78CE3A97B0
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include "asm_struct.h"
    #define OP_NBR 23

int compile_file(char *filename);
int get_op_index(char *op);
int write_instruct(char **line, exec_t *exec);
void invert_endianess(void *var, size_t size);
int count_char_in_str(char *str, char c);
int write_parameters(char **line, exec_t *exec, int index);
void handle_param(char *param, char *p_sizes, int *p_values, exec_t *ex);
header_t *get_header(FILE *file);
void write_header(header_t *header, exec_t *exec, int fd);
void register_label(char *op, exec_t *ex);
int get_label_index(char *op, exec_t *ex);
bool label_was_forward_declared(char *op, exec_t *ex);
void register_forward_label(char *op, exec_t *exec, int delta_head);
int get_label_adress(char *label, exec_t *exec);
bool there_are_undeclared_labels(exec_t *exec);
void remove_final_newline(char *line);
char *get_label_on_line(char **str);
int convert_line(char **line, exec_t *exec);
int continue_writting_line(char **line, exec_t *ex);
void declare_label(char **line, exec_t *ex);
void wexec_at(void *data, int index, size_t size, exec_t *ex);
void add_label_reference(exec_t *ex, int i, int delta_head);

int process_line(exec_t *ex, char **line);
char *get_label_from_param(char *param);
int my_getnbr(char *str);
int op_is_label(char *op);
void write_exec_binary(exec_t *ex);
void output_binary_to_file(char *filepath, exec_t *ex, header_t *header);

#endif
