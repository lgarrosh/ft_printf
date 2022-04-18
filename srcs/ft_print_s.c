/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:42 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:28:07 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putnstr(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_putchar(s[i++]);
	return (i);
}

static void	init_flag_s(t_flags *f)
{
	if ((f->precisen >= f->len) || (f->precisen == -1))
		f->precisen = f->len;
	if (f->width < f->precisen)
		f->width = 0;
	else
		f->width -= f->precisen;
}

static void	ft_print_s2(char *ch, t_flags f)
{
	if (!f.minus)
	{
		ft_put_n_char(' ', f.width);
		if (!ch)
			ft_putstr("(null)");
		else
			ft_putnstr(ch, f.precisen);
	}
	else
	{
		if (!ch)
			ft_putstr("(null)");
		else
			ft_putnstr(ch, f.precisen);
		ft_put_n_char(' ', f.width);
	}
}

int	ft_print_s(va_list *bp, t_flags f)
{
	char	*ch;

	ch = va_arg(*bp, char *);
	f.len = ft_strlen(ch);
	init_flag_s(&f);
	if (ch)
	{
		if (*ch == 0)
		{
			ft_put_n_char(' ', f.width);
			return (f.width);
		}
	}
	if (f.precisen == 0)
		return (0);
	ft_print_s2(ch, f);
	return (f.width + f.precisen);
}
