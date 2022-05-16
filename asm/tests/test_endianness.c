/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** test_endianness.c
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(invert_endianess, both_directions)
{
    int var = 0xff000000;

    invert_endianess(&var, sizeof(int));
    cr_assert_eq(var, 0xff);
    invert_endianess(&var, sizeof(int));
    cr_assert_eq(var, 0xff000000);
    var = 1;
    invert_endianess(&var, sizeof(int));
    cr_assert_eq(var, 0x01000000);
}
