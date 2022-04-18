/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:55 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:52:29 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *src, ...)
{
	t_flags	f;
	va_list	ap;
	int		l;

	f = initflags();
	va_start(ap, src);
	l = 0;
	while (*src != 0)
	{
		if (*src != '%')
			l += ft_putchar(*src);
		else
			l += ft_print(&src, &ap, f);
		src += 1;
	}
	va_end(ap);
	return (l);
}

static int	zapusk(const char **src, va_list *ap, t_flags f)
{
	int	l;

	l = 0;
	if (**src == 'c')
		l += ft_print_c(ap, f);
	else if (**src == 's')
		l += ft_print_s(ap, f);
	else if (**src == 'p')
		l += ft_print_p(ap, f);
	else if (**src == 'd')
		l += ft_print_d(ap, f);
	else if (**src == 'i')
		l += ft_print_i(ap, f);
	else if (**src == 'u')
		l += ft_print_u(ap, f);
	else if (**src == 'x')
		l += ft_print_x(ap, f);
	else if (**src == 'X')
		l += ft_printsx(ap, f);
	else if (**src == '%')
		l += ft_print_proc(f);
	else
		*src -= 1;
	return (l);
}

int	ft_print(const char **src, va_list *ap, t_flags f)
{
	int	l;

	l = 0;
	*src += 1;
	f = initflags();
	updateflags(src, &f);
	l = zapusk(src, ap, f);
	return (l);
}
