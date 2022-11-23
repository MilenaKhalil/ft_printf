/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 20:28:25 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/23 12:35:02 by mikhalil      ########   odam.nl         */
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
	if (*str == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	else if (*str == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	else if (*str == '%')
		return (ft_putchar_fd('%', 1));
	else if (*str == 'x' || *str == 'X')
		return (hexi_deci(va_arg(arg, unsigned int), *str));
	else if (*str == 'p')
		return (hexi_deci(va_arg(arg, unsigned long), *str));
	else if (*str == 'u')
		return (ft_putuns_fd(va_arg(arg, unsigned int), 1));
	return (-1);
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
		{
			str++;
			if (*str == '\0')
				return (out);
			len = cases(str, arg);
		}
		else
			len = ft_putchar_fd(*str, 1);
		if (len == -1)
			out += ft_putchar_fd(*str, 1);
		else
			out += len;
		str++;
	}
	va_end(arg);
	return (out);
}
/*#include <limits.h>
int main() // null str, x, X
{
	int	i = 0, j = 0;
	i = printf("%%\n");
	j = ft_printf("%%\n");
	printf("or = %d\nmy = %d\n", i, j);
	//ft_printf("%i, %i, %i, %i, %i, %p\n", 0, 0, 0, 0, 0, (void *)0);
	//hexi_deci(3624783, 'X');
	return 0;
}*/
