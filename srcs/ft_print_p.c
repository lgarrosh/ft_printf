/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:39 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:25:14 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_flag_p(t_flags *f)
{
	if (f->width < f->len)
		f->width = 0;
	else
		f->width -= f->len;
}

int	ft_print_p(va_list *bp, t_flags f)
{
	unsigned long long int	i;
	char					*buff;

	i = va_arg(*bp, unsigned long long int);
	buff = ft_hexa(i, "0123456789abcdef", 16);
	f.len = ft_strlen(buff) + 2;
	init_flag_p(&f);
	if (!f.minus)
	{
		ft_put_n_char(' ', f.width);
		ft_putchar(48);
		ft_putchar('x');
		ft_putstr(buff);
	}
	else
	{
		ft_putchar(48);
		ft_putchar('x');
		ft_putstr(buff);
		ft_put_n_char(' ', f.width);
	}
	ft_free((void **)&buff);
	return (f.width + f.len);
}
