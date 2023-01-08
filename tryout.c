#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;
    char **str;
    str = malloc(ac * sizeof(char *));
    i = 0;
    while (i < ac)
    {
        str[i] = malloc(strlen(av[i]) * sizeof(char));
        j = 0;
        while (av[i][j])
        {
            str[i][j] = av[i][j];
            j++;
        }
        i++;
    }

    i = 0;
    while (i < ac)
    {
        printf("%s\n", str[i]);
        i++;
    }
    return 0;
}