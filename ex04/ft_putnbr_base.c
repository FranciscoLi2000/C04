#include <unistd.h>
#include <ctype.h>
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

void ft_putnbr_base(int nbr, char *base)
{
    int			base_len;

    base_len = get_base(base);
    if (base_len < 2)
        return ;
    if (nbr < 0)
    {
        write(1, "-", 1);
        nbr = -nbr;
    }
    if (nbr >= base_len)
        ft_putnbr_base(nbr / base_len, base);
    write(1, &base[nbr % base_len], 1);
}