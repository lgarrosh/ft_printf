/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:47 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:32:21 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_flag_x(t_flags *f)
{
	if (f->resh)
		f->resh = 2;
	if (f->minus || f->precisen != -1)
		f->zero = 0;
	if (f->precisen <= f->len + f->resh)
		f->precisen = 0;
	else
		f->precisen -= f->len + f->resh;
	if (f->width < f->precisen + f->len + f->resh)
		f->width = 0;
	else
		f->width -= f->precisen + f->len + f->resh;
}

static void	ft_print_x2(char *buff, t_flags f)
{
	if (!f.minus)
	{
		ft_put_n_char(' ', f.width);
		ft_put_n_char(48, f.precisen);
		if (f.resh)
			ft_putstr("0x");
		ft_putstr(buff);
	}
	else
	{
		ft_put_n_char(48, f.precisen);
		if (f.resh)
			ft_putstr("0x");
		ft_putstr(buff);
		ft_put_n_char(' ', f.width);
	}
}

int	ft_print_x(va_list *bp, t_flags f)
{
	unsigned int	i;
	char			*buff;

	i = va_arg(*bp, unsigned int);
	buff = ft_hexa(i, "0123456789abcdef", 16);
	f.len = ft_strlen(buff);
	init_flag_x(&f);
	if (i == 0)
		f.resh = 0;
	if (f.zero)
	{
		ft_put_n_char(48, f.width);
		if (f.resh)
			ft_putstr("0x");
		ft_putstr(buff);
	}
	else
		ft_print_x2(buff, f);
	ft_free((void **)&buff);
	return (f.width + f.precisen + f.len + f.resh);
}
