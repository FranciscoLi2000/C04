#include <unistd.h>
#include <ctype.h>

int ft_atoi(char *str)
{
    int         nb;
    int         is_negative;

    nb = 0;
    is_negative = 0;
    while (*str == 32)  // Saltar los espacios iniciales
        str++;
    if (*str == '-')    // Manejo del signo
    {
        is_negative = 1;
        str++;
    }
    else if (*str == '+')
        str++; // Se puede omitir el ajuste de is_negative porque es 0 por defecto
    while (isdigit(*str))   // Conversión de caracteres a número
    {
        nb = nb * 10 + (*str - '0'); // Simplificación de la operación
        str++;
    }
	if (is_negative)    // Si el número es negativo, lo convertimos a negativo
    	return (-nb);
	return (nb);
}
