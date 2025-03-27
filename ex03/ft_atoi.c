#include <unistd.h>
#include <ctype.h>

int ft_atoi(char *str)
{
    int nb = 0;
    int is_negative = 0;

    // Saltar los espacios iniciales
    while (*str == 32)
        str++;

    // Manejo del signo
    if (*str == '-')
    {
        is_negative = 1;
        str++;
    }
    else if (*str == '+')
    {
        str++; // Se puede omitir el ajuste de is_negative porque es 0 por defecto
    }

    // Conversión de caracteres a número
    while (isdigit(*str))
    {
        nb = nb * 10 + (*str - '0'); // Simplificación de la operación
        str++;
    }

    // Si el número es negativo, lo convertimos a negativo
	if (is_negative)
    	return (-nb);
	return (nb);
}
