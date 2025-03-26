#include "exam_rank02.h"
/* 先类型转换，再进制转换 */
static int	get_base(char *base)
{
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == base[i + 1])
			return (0);
		else if (base[i] <= 32)
			return (0);
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	is_negative;

	is_negative = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
	{
		is_negative = 0;
		str++;
	}
	else if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	nb = 0;
	while (ft_isdigit(*str))
	{
		nb *= get_base(base);
		nb += *str - '0';
		str++;
	}
	if (is_negative == 0)
		return (-nb);
	return (nb);
}
