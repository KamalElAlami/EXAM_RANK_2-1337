#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
    int i = 0;
    while (s2[i] && i < n)
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

int count_words(char *str){
    int i = 0;
    int count = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i])
            count++;
        while (str[i] && (str[i] != ' ' && str[i] != '\t'))
            i++;
    }
    return (count);
}

char    **ft_split(char *str)
{
    char **strs;
    int len;
    int i;
    int start;
    int end;
    int pro = 0;
    
    len = count_words(str);
    strs = malloc(sizeof(char *) * len + 1);
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i])
            start = i;
        while (str[i] && (str[i] != ' ' && str[i] != '\t'))
            i++;
        if (i > start)
        {
            strs[pro] = malloc(sizeof(char) * (i - start) + 1);
            ft_strncpy(strs[pro++], &str[start], i - start );
        }
    }
    strs[pro] = NULL;
    return (strs);
}

int main(void)
{
    int j = 0;
    char **siko;
    siko = ft_split("kamal el alami is the best");
    while (siko[j])
        printf("%s\n", siko[j++]);


    // char *str = "kamal";
    // char *dest;

    // ft_strncpy(dest, str, 5);
    // printf("%s\n", dest);
}