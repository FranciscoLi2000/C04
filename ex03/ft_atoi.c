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

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	str[50];

	printf("Enter a string: ");
	scanf("%s", str);
	printf("Original %i\n", atoi(str));
	printf("Mine %i\n", ft_atoi(str));
	return (0);
}
