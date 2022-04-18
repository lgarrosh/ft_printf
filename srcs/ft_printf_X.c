/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:53 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:46:03 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_x(t_flags *f)
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

static void	ft_printrx(char *buff, t_flags f)
{
	if (!f.minus)
	{
		ft_put_n_char(' ', f.width);
		ft_put_n_char(48, f.precisen);
		if (f.resh)
			ft_putstr("0X");
		ft_putstr(buff);
	}
	else
	{
		ft_put_n_char(48, f.precisen);
		if (f.resh)
			ft_putstr("0X");
		ft_putstr(buff);
		ft_put_n_char(' ', f.width);
	}
}

int	ft_printsx(va_list *bp, t_flags f)
{
	unsigned int	i;
	char			*buff;

	i = va_arg(*bp, unsigned int);
	buff = ft_hexa(i, "0123456789ABCDEF", 16);
	f.len = ft_strlen(buff);
	init_x(&f);
	if (i == 0)
		f.resh = 0;
	if (f.zero)
	{
		ft_put_n_char(48, f.width);
		if (f.resh)
			ft_putstr("0X");
		ft_putstr(buff);
	}
	else
		ft_printrx(buff, f);
	ft_free((void **)&buff);
	return (f.width + f.precisen + f.len + f.resh);
}
