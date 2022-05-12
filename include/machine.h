/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** machine.h
*/

#ifndef __MACHINE__
    #define __MACHINE__

    #include "my.h"
    #include "op.h"
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include "math.h"

typedef struct ope_s {
    char code;
    char *type;
    char *size_type;
    int *args;
    int size;
    int nbr_cycles;
} ope_t;

typedef struct ram_s {
    char *mem;
    int size;
} ram_t;

typedef struct process_s {
    int flag;
    char **reg;
    int pc;
    bool carry;
    int last_live;
    int wait;
    ope_t *current_ope;
} process_t;

typedef struct vm_s {
    ram_t *ram;
    process_t **process;
    int proc_nbr;
    int cycle;
    int cycle_to_die;
    int live_count;
} vm_t;

typedef struct instruct_s {
    void (*func)(vm_t *vm, process_t *process, ope_t *ope);
} instruct_t;

//MACHINE MANAGEMENT
void launch_vm(int ac, char *av[]);
ram_t *setup_ram(void);
char *load_battle_zone(void);
void load_prog(vm_t *vm, char *path, int adress, int flag);

//PROCESS MANAGEMENT
char **load_reg(void);
void update_process(vm_t *vm, process_t *proc);

//OPERATIONS MANAGEMENT
int sum_char(char *size_type);
ope_t *get_ope(vm_t *vm, int adress);
void destroy_ope(ope_t *ope);

//OPERATIONS
void live(vm_t *vm, process_t *process, ope_t *ope);
void ld_func(vm_t *vm, process_t *process, ope_t *ope);

#endif