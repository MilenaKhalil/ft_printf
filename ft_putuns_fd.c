/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putuns_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 16:18:09 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/14 17:51:07 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_putuns_fd(unsigned int n, int fd)
{
	char	c;

	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	c = n % 10 + '0';
	return (ft_putuns_fd(n / 10, fd) + ft_putchar_fd(c, fd));
}
