void print_error(void)
{
	ft_printf("Error");
	exit(1);
}
int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if (result < INT_MIN || result > INT_MAX)
		print_error();
	return (sign * result);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}
void check_sign_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				print_error();
			j++;
		}
		j = 0;
		i++;
	}
}
void check_dup(int *arr)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[j])
		{
			if (arr[i] == arr[j])
				print_error();
			j++;
		}
		i++;
	}
}
int *ft_check_arg(int argc, char **argv)
{
	int	i;
	int	*arr;

	i = 1;
	check_sign_digit(argv);
	arr = (int *)malloc(sizeof(int *) * (argc - 1));
	if (!arr)
		return (NULL);
	while (argv[i])
		arr[i - 1] = ft_atoi(argv[i]);
	check_dup(arr);
	return (arr);
}
