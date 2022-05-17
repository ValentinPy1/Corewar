/*
** EPITECH PROJECT, 2022
** instruction
** File description:
** Header
*/

#ifndef INSTRUCTION_H_
    #define INSTRUCTION_H_
    #include "machine.h"

static const instruct_t MNEMONIC[] = {
    {&live_func},
    {&ld_func},
    {&st_func},
    {&add_func},
    {&sub_func},
    {&and_func},
    {&or_func},
    {&xor_func}
};

#endif /* !INSTRUCTION_H_ */
