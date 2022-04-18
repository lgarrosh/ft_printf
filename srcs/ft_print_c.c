/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:29 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:18:40 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_flag_c(t_flags *f)
{
	if (f->width < f->len)
		f->width = 0;
	else
		f->width -= f->len;
}

int	ft_print_c(va_list *bp, t_flags f)
{
	char	ch;

	ch = va_arg(*bp, unsigned int);
	f.len = 1;
	init_flag_c(&f);
	if (!f.minus)
	{
		ft_put_n_char(' ', f.width);
		ft_putchar(ch);
	}
	else
	{
		ft_putchar(ch);
		ft_put_n_char(' ', f.width);
	}
	return (f.width + f.len);
}

int	ft_print_proc(t_flags f)
{
	f.len = 1;
	init_flag_c(&f);
	if (f.zero)
	{
		ft_put_n_char(48, f.width);
		ft_putchar('%');
	}
	else if (!f.minus)
	{
		ft_put_n_char(' ', f.width);
		ft_putchar('%');
	}
	else
	{
		ft_putchar('%');
		ft_put_n_char(' ', f.width);
	}
	return (f.width + f.len);
}
