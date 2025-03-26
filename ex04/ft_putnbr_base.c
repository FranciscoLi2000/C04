#include "exam_rank02.h"
/* 这道题需要了解：什么是进制？以及如何计算来实现在二八十十六进制间相互转换 */
static int	get_base(char *base)
{
	int	i;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == base[i + 1])
			return (0);
		else if (!ft_isdigit(base[i]))
			return (0);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	result;
	int	remainder;
	int	i;

	result = 0;
	i = 1;
	while (nbr != 0)
	{
		remainder = nbr % get_base(base);
		nbr = nbr / get_base(base);
		result += remainder * i;
		i *= get_base(base);
	}
	ft_putnbr(result);
}
