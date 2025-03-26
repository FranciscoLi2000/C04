#include "exam_rank02.h"

int	ft_atoi(char *str)
{
	/* 两个变量：转换完成后存放在int型变量nb中 */
	int	nb;
	int	is_negative; /* 这个变量用来代替bool型变量，1 为真，0 为假 */

	is_negative = 0;
	/* 如果字符串前面有空格 则需要跳过这些空格 */
	while (ft_isspace(*str)) /* 众所周知，指针是可以运算的，我们来用指针来遍历字符串 */
		str++;
	if (*str == '+')
	{
		is_negative = 0; /* 跳过空格后，如果数字前面还有正号，说明是正数，is_negative为假 */
		str++;
	}
	else if (*str == '-') /* 负数的话，条件自然和上面相反 */
	{
		is_negative = 1;
		str++;
	}
	nb = 0;
	while (ft_isdigit(*str)) /* 符号处理完了，我们可以调用一下ft_isdigit函数确保处理input的每一位数字 */
	{
		nb *= 10; /* 或者写 nb = nb * 10 将字符按照数学十进制运算的逻辑进行转换 */
		nb += *str - '0'; /* 单字符转换为数字的逻辑 */
		str++;
	}
	if (is_negative == 1)
		return (-nb);
	return (nb);
}
