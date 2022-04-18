/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:44 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:30:04 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_flag_u(t_flags *f)
{
	if (f->minus || f->precisen != -1)
		f->zero = 0;
	if (f->precisen <= f->len)
		f->precisen = 0;
	else
		f->precisen -= f->len;
	if (f->width < f->precisen + f->len)
		f->width = 0;
	else
		f->width -= (f->precisen + f->len);
}

static void	ft_printf_u2(unsigned int i, t_flags f)
{
	if (!f.minus)
	{
		ft_put_n_char(' ', f.width);
		ft_put_n_char(48, f.precisen);
		ft_putnbr(i);
	}
	else
	{
		ft_put_n_char(48, f.precisen);
		ft_putnbr(i);
		ft_put_n_char(' ', f.width);
	}
}

int	ft_print_u(va_list *bp, t_flags f)
{
	unsigned int	i;

	i = va_arg(*bp, unsigned int);
	f.len = ft_nbrlen(i, 10);
	init_flag_u(&f);
	if (f.zero)
	{
		ft_put_n_char(48, f.width);
		ft_putnbr(i);
	}
	else
		ft_printf_u2(i, f);
	return (f.precisen + f.width + f.len);
}
