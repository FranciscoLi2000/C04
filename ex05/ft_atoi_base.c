#include <unistd.h>
#include <limits.h>

static int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int	ft_char_to_digit(char c, char *base, int base_len)
{
	int	i;

	i = 0;
	while (i < base_len)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	base_len;
	int	digit;

	sign = 1;
	result = 0;
	base_len = ft_is_valid_base(base);
	if (base_len < 2)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		digit = ft_char_to_digit(*str, base, base_len);
		if (digit == -1)
			break ;
		if (result > (INT_MAX - digit) / base_len)
			return ((sign == 1) ? INT_MAX : INT_MIN);
		result = result * base_len + digit;
		str++;
	}
	return (result * sign);
}

#include <stdio.h>

int	main(void)
{
	printf("Test 1 (10 to 10): %d\n", ft_atoi_base("123", "0123456789"));
	printf("Test 2 (16 to 10): %d\n", ft_atoi_base("FF", "0123456789ABCDEF"));
	printf("Test 3 (2 to 10): %d\n", ft_atoi_base("1010", "01"));
	printf("Test 4 (invalid base): %d\n", ft_atoi_base("123", "012"));
	printf("Test 5 (negative): %d\n", ft_atoi_base("-1010", "01"));
	printf("Test 6 (invalid char): %d\n", ft_atoi_base("12A34", "0123456789"));
	return (0);
}
