/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:49 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/13 15:26:49 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char ch)
{
	return (write(1, &ch, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i] != 0)
	{
		l += ft_putchar(s[i]);
		i++;
	}
	return (l);
}

int	ft_putnbr(long long int nb)
{
	int		i;
	char	*buff;

	buff = ft_itoa(nb);
	i = ft_putstr(buff);
	ft_free((void **)&buff);
	return (i);
}
