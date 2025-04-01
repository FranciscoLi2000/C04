#include <unistd.h>
#include <stdio.h>

#define INT_MIN -2147483647

void	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		write(1, "-2147483647", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	else if (nb > 9)
		ft_putnbr(nb / 10);
	else
		putchar(nb % 10 + '0');
}
