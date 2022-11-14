/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 20:28:25 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/14 18:04:31 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int	hexi_deci(unsigned long inp, char p)
{
	const char	*a = "0123456789abcdef";

	if (p == 'X')
		a = "0123456789ABCDEF";
	if (p == 'p')
		return (write(1, "0x", 2) + hexi_deci(inp, 'x'));
	if (inp < 16)
		return (ft_putchar_fd(a[inp % 16], 1));
	return (hexi_deci(inp / 16, p) + ft_putchar_fd(a[inp % 16], 1));
}

int	cases(const char *str, va_list arg)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len = ft_putchar_fd(va_arg(arg, int), 1);
	else if (*str == 's')
		len = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (*str == 'd' || *str == 'i')
		len = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (*str == '%')
		len = ft_putchar_fd('%', 1);
	else if (*str == 'x' || *str == 'X')
		len = hexi_deci(va_arg(arg, unsigned int), *str);
	else if (*str == 'p')
		len = hexi_deci(va_arg(arg, unsigned long), *str);
	else if (*str == 'u')
		len = ft_putuns_fd(va_arg(arg, unsigned int), 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		out;
	int		len;

	out = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
			len = cases(++str, arg);
		else
			len = ft_putchar_fd(*str, 1);
		str++;
		if (len == -1)
			return (-1);
		out += len;
	}
	va_end(arg);
	return (out);
}
/*#include <limits.h>
int main() // null str, x, X
{
	int	i = 0, j = 0;
	i = printf("%X\n", -2);
	j = ft_printf("%X\n", -2);
	printf("or = %d\nmy = %d\n", i, j);
	//ft_printf("%i, %i, %i, %i, %i, %p\n", 0, 0, 0, 0, 0, (void *)0);
	//hexi_deci(3624783, 'X');
	return 0;
}*/
