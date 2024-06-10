#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int     *ft_range(int start, int end)
{
    int *arr;
    int len = abs((end - start)) + 1;
    int i  = 0;

    arr = malloc(sizeof(int) * len);
    while (i < len)
    {
        if (start <= end)
        {
            arr[i] = start;
            start++;
        }
        else
        {
            arr[i] = start;
            start--;
        }
        i++;
    }
    return (arr);
}
