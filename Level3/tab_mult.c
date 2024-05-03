#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr(char *str)
{
    while (*str)
        ft_putchar(*(str++));
}

void ft_putnbr(int number)
{
    long nbr;

    nbr = number;
    if (nbr < 10)
        ft_putchar(nbr + '0');
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putchar(nbr % 10 + '0');
    }
}

int main(int ac, char **av)
{
    int i = 1;
    int num;
    if (ac == 2)
    {
        num = atoi(av[1]);
        while (i <= 9)
        {
            ft_putnbr(i);
            ft_putstr(" x ");
            ft_putnbr(num);
            ft_putstr(" = ");
            ft_putnbr(i * num);
            ft_putchar('\n');
            i++;
        }
    }
    else
        ft_putchar('\n');
}