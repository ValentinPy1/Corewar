/*
** EPITECH PROJECT, 2022
** error_handling_args_type
** File description:
** Source code to test if the type are goods 
*/
#include "asm_struct.h"
#include "asm.h"
#include "args_type.h"

int error_handling_args_type(buffer_t *buffer)
{
    return (type_test_live(buffer));
}