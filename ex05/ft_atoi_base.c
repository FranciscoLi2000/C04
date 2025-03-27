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
    int nb;
    int is_negative;
    int base_len;
    int i;

    base_len = get_base(base);
    if (base_len < 2)
        return (0);  // Base no válida.

    // Salta los espacios en blanco
    while (isspace(*str))
        str++;

    // Maneja el signo
    is_negative = 0;
    if (*str == '-')
    {
        is_negative = 1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    nb = 0;
    while (*str)
    {
        // Buscar el valor correspondiente del carácter en la base
        i = 0;
        while (base[i] != '\0' && base[i] != *str)
            i++;

        if (base[i] == '\0')  // Carácter no válido para la base.
            break;

        nb = nb * base_len + i;
        str++;
    }

    if (is_negative)
        return (-nb);  // Si es negativo, devolver el valor negativo.

    return (nb);  // Retorna el número calculado.
}