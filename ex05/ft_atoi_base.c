#include <unistd.h>
#include <ctype.h>

static int get_base(char *base)
{
    int i;
    int j;

    i = 0;
    while (base[i] != '\0')
    {
        if (base[i] <= 32 || base[i] == '+' || base[i] == '-' || base[i] == ' ' || base[i] == '\t')
            return (0);  // Caracteres no válidos.
        j = i + 1;
        while (base[j] != '\0')
        {
            if (base[i] == base[j])
                return (0);  // Caracteres repetidos en la base.
            j++;
        }
        i++;
    }
    return (i);  // Devuelve el tamaño de la base (número de caracteres únicos).
}

int ft_atoi_base(char *str, char *base)
{
    int         nb;
    int         sign;
    int         base_len;

    nb = 0;
    sign = 1;
    base_len = get_base(base);
    if (base_len < 2)
        return (0);
    while (isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str++ == '-')
            sign = -1;
        sign = 1;
    }
    while (*str)
    {
        while (*base != '\0' && *base != *str)
            base++;
        if (!*base)
            break ;
        nb = nb * base_len + *base;
        str++;
    }
    return (nb * sign);
}