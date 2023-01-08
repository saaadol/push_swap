#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void	skip_space(char *nptr, int *i)
{
	while (nptr[*i] == 32 || (nptr[*i] >= 9 && nptr[*i] <= 13))
		(*i)++;
}

static void	result_sign(char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign *= -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

int	ft_atoi(char *nptr)
{
	int	x[2];
	int	result;
	int	temp;

	x[0] = 0;
	x[1] = 1;
	result = 0;
	skip_space(nptr, &x[0]);
	result_sign(nptr, &x[0], &x[1]);
	while ((nptr[x[0]] >= 48 && nptr[x[0]] <= 57))
	{
		temp = result;
		result = result * 10;
		if (result / 10 != temp && result)
		{
			if (x[1] == -1)
				return (0);
			return (-1);
		}
		result += nptr[x[0]] - 48;
		x[0]++;
	}
	return (result * x[1]);
}  

int main(int ac, char **av)
{
	
    int i = 0;
    int j = 0;
    int **str;
    str = malloc((ac-1) * sizeof(int));
    while (i < (ac-1))
    {
        str[i] = malloc(strlen(av[i+1]) * sizeof(int));
        j = 0;
        while (av[i+1][j])
        {
            str[i][j] = ft_atoi(&av[i+1][j]);
            j++;
        }
		str[i][j] = '\0';
        i++;
    }
	i = 0;
	j = 0;
	while(i < (ac - 1))
	{
		j = i+1;
		while(j < (ac -1))
		{
			if (*str[i] == *str[j])
			{
				printf("%c",'f');
				break;
			}
			j++;
		}
		i++;
	}
    return 0;
}