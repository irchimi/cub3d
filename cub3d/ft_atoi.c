int		ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] <= '9' && str[i] >= '0')
		number = number * 10 + (str[i++] - '0');
	if (number > 9223372036854775807)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (number * sign);
}