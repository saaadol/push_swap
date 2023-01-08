static void	skip_space(const char *nptr, int *i)
{
	while (nptr[*i] == 32 || (nptr[*i] >= 9 && nptr[*i] <= 13))
		(*i)++;
}

static void	result_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign *= -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

int	ft_atoi(const char *nptr)
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