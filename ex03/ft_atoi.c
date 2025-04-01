#include <unistd.h>
#include <ctype.h>

int	ft_atoi(char *str)
{
	int	nb;
	int	is_negative;

	nb = 0;
	is_negative = 0;
	while (*str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = 1;
		str++;
	}
	while (isdigit(*str))
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	if (is_negative)
		return (-nb);
	return (nb);
}
