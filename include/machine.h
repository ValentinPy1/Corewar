/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** machine.h
*/

#ifndef __vmINE__
    #define __vmINE__
    #define loadarg(arg, i, size) \
    (load_op_arg(&arg, vm, (arginf_t) {ope, p, i, size}))
    #define lireg(data_ptr, data_size, reg_index) \
    load_data_in_reg(p->reg[ope->args[reg_index] - 1], data_ptr, data_size)
    #define ABS(x) (x < 0 ? -x : x)
    #define MAX_PLAYER_NBR 4

    #include "my.h"
    #include "op.h"
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include "math.h"

typedef struct process_s process_t;

typedef struct ope_s {
    char code;
    char type[MAX_ARGS_NUMBER];
    int size_type[MAX_ARGS_NUMBER];
    int args[MAX_ARGS_NUMBER];
    int size;
    int nbr_cycles;
    int real_args[MAX_ARGS_NUMBER];
} ope_t;

typedef struct arg_info_s {
    ope_t *ope;
    process_t *process;
    int argno;
    int arg_size;
} arginf_t;

typedef struct ram_s {
    char *mem;
    int size;
} ram_t;

struct process_s {
    int flag;
    int *reg;
    int pc;
    bool carry;
    int last_live;
    int player_id_alive;
    int wait;
    ope_t *current_ope;
    int prog_nbr;
    char *name;
    int initial_pc;
    int prog_size;
};

typedef struct player_s {
    int last_live;
    bool is_alive;
} player_t;

typedef struct vm_s {
    ram_t *ram;
    process_t **process;
    int proc_count;
    int cycle;
    int cycle_to_die;
    int live_count;
    int dump_cycle;
    player_t players[MAX_PLAYER_NBR];
} vm_t;

typedef struct instruct_s {
    void (*func)(vm_t *vm, process_t *process, ope_t *ope);
} instruct_t;


//SETUP MACHINE
int get_nbr_of_champ(char **av);
void my_get_option(vm_t *vm, int ac, char **av);
void display_memory(vm_t *vm);

//MACHINE MANAGEMENT
int launch_vm(int ac, char *av[]);
void setup_ram(vm_t *vm);
// char *load_battle_zone(vm_t *vm);
void load_battle_zone(ram_t *ram);
void load_prog(vm_t *vm, char *path, int adress, int prog_number);
bool battle_hasnt_ended(vm_t *vm);

//REGISTER READ / WRITE
void load_data_in_reg(int *reg, void *data, size_t data_size);
void load_data_from_reg(int *reg, void *data, size_t data_size);
void load_to_ptr(void *ptr, int adress, vm_t *vm, size_t size);
void load_data_to_mem(int adress, void *data, int data_size, vm_t *vm);

//PROCESS MANAGEMENT
// char **load_reg(void);
int *load_reg(int flag);
void update_process(vm_t *vm, process_t *proc);
void memcpy_size(void *dest, void *src, size_t size);

//OPERATIONS MANAGEMENT
int sum_char(char *size_type);
ope_t *get_ope(vm_t *vm, int adress, process_t *process);
void destroy_ope(ope_t *ope);
void get_op_real_args(vm_t *vm, ope_t *ope, int adress, process_t *process);
char *specific_type(char op_code);
void destroy_ope(ope_t *ope);
void get_args_type(ope_t *ope, int *adress, char *mem);
void load_op_arg(void *dest, vm_t *vm, arginf_t arginf);
void load_live(vm_t *vm, process_t *process, ope_t *ope, int adress);
void load_zjmp(vm_t *vm, process_t *process, ope_t *ope, int adress);
void load_ldi(vm_t *vm, process_t *process, ope_t *ope, int adress);
void load_sti(vm_t *vm, process_t *process, ope_t *ope, int adress);
void load_fork(vm_t *vm, process_t *process, ope_t *ope, int adress);

//OPERATIONS
void live_func(vm_t *vm, process_t *process, ope_t *ope);
void ld_func(vm_t *vm, process_t *process, ope_t *ope);
void st_func(vm_t *vm, process_t *process, ope_t *ope);
void add_func(vm_t *vm, process_t *process, ope_t *ope);
void sub_func(vm_t *vm, process_t *process, ope_t *ope);
void and_func(vm_t *vm, process_t *p, ope_t *ope);
void or_func(vm_t *vm, process_t *p, ope_t *ope);
void xor_func(vm_t *vm, process_t *p, ope_t *ope);
void zjmp_func(vm_t *vm, process_t *process, ope_t *ope);
void sti_func(vm_t *vm, process_t *p, ope_t *ope);
void fork_func(vm_t *vm, process_t *p, ope_t *ope);
void ldi_func(vm_t *vm, process_t *process, ope_t *ope);
void lld_func(vm_t *vm, process_t *process, ope_t *ope);


// static void copy_process_at(int adress, process_t *process, vm_t *vm);
#endif
