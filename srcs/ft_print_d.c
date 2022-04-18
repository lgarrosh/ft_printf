/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:33 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:23:23 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_flags_d(t_flags *f)
{
	if (f->minus || f->precisen != -1)
		f->zero = 0;
	if (f->sign || f->negative)
		f->spase = 0;
	if (f->precisen <= f->len + f->spase)
		f->precisen = 0;
	else
		f->precisen -= f->len + f->spase;
	if (f->width < f->precisen + f->negative + f->len + f->sign + f->spase)
		f->width = 0;
	else
		f->width -= (f->precisen + f->negative + f->len + f->sign + f->spase);
	if (f->negative || f->sign)
	{
		if (f->negative)
			f->sign = 45;
		else
			f->sign = 43;
	}
}

static void	ft_print_d3(long long int nb, t_flags f)
{
	if (f.spase && !f.negative)
		ft_putchar(' ');
	if (f.sign)
		ft_putchar(f.sign);
	ft_put_n_char(48, f.precisen);
	if (f.negative)
		ft_putnbr(-nb);
	else
		ft_putnbr(nb);
	ft_put_n_char(' ', f.width);
}

static void	ft_print_d2(long long int nb, t_flags f)
{
	if (!f.minus)
	{
		ft_put_n_char(' ', f.width);
		if (f.spase && !f.negative)
			ft_putchar(' ');
		if (f.sign)
			ft_putchar(f.sign);
		ft_put_n_char(48, f.precisen);
		if (f.negative)
			ft_putnbr(-nb);
		else
			ft_putnbr(nb);
	}
	else
		ft_print_d3(nb, f);
}

int	ft_print_d(va_list *bp, t_flags f)
{
	long long int	nb;

	nb = va_arg(*bp, int);
	f.len = ft_nbrlen(nb, 10);
	if (nb < 0)
		f.negative = 1;
	init_flags_d(&f);
	if (f.zero)
	{
		if (f.spase && !f.negative)
			ft_putchar(' ');
		if (f.sign)
			ft_putchar(f.sign);
		ft_put_n_char(48, f.width);
		if (f.negative)
			ft_putnbr(-nb);
		else
			ft_putnbr(nb);
	}
	else
		ft_print_d2(nb, f);
	if (f.sign > 0)
		f.sign = 1;
	return (f.width + f.sign + f.precisen + f.len + f.spase);
}
