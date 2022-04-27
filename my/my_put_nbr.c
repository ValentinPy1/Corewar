/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** nbr
*/

#include "my.h"
#include <unistd.h>

void my_put_nbr(int nb)
{
    int mod = 0;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9) {
        mod = (nb % 10);
        nb = (nb / 10);
        my_put_nbr(nb);
        my_putchar(48 + mod);
    } else {
        my_putchar(nb + 48);
    }
}
