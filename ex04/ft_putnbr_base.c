#include <unistd.h>
#include <ctype.h>
#include <limits.h>

static int	is_valid_base(char *base)
{
	int	len;
	int	i;

	len = 0;
	if (base == NULL || base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[len])
	{
		i = 0;
		while (i < len)
		{
			if (base[i] == base[len])
				return (0);
			i++;
		}
		if (!isalnum(base[len]))
			return (0);
		len++;
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = is_valid_base(base);
	if (base_len < 2)
		return ;
	if (nbr == INT_MIN)
	{
		write(1, "-", 1);
		ft_putnbr_base(-(nbr / base_len), base);
		write(1, &base[-(nbr % base_len)], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	write(1, &base[nbr % base_len], 1);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	base[50];
	int		n;

	printf("Enter a int number and the string of base: ");
	scanf("%i %s", &n, base);
	if (!is_valid_base(base))
	{
		printf("Error of base.\n");
		return (1);
	}
	printf("Your number in base-%li system is number\n", strlen(base));
	ft_putnbr_base(n, base);
	printf("\n");
	return (0);
}
