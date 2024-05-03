#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_number(int number)
{
    long nbr;

    nbr = number;

    if (nbr < 10)
        ft_putchar(nbr + '0');
    
    else if (nbr > 9)
    {
        print_number(nbr / 10);
        ft_putchar(nbr % 10 + '0');
    }
}
int main(void)
{
    int i;
    i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else 
            print_number(i);
        write(1, "\n", 1);
        i++;
    }
}