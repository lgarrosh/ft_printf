/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:08:32 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:52:19 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	isachar(char c)
{
	return (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)));
}

int	isadigit(char c)
{
	return ((c >= 48) && (c <= 57));
}

t_flags	initflags(void)
{
	t_flags	f;

	f.minus = 0;
	f.sign = 0;
	f.zero = 0;
	f.spase = 0;
	f.width = 0;
	f.resh = 0;
	f.len = 0;
	f.negative = 0;
	f.precisen = -1;
	return (f);
}

void	updateflags(const char **src, t_flags *f)
{
	while (!isachar(**src) && !((**src > 48) && (**src <= 57))
		&& (**src != '.') && (**src != '%'))
	{
		if (**src == '+')
			f->sign = 1;
		else if (**src == '-')
			f->minus = 1;
		else if (**src == ' ')
			f->spase = 1;
		else if (**src == '#')
			f->resh = 1;
		else if (**src == '0')
			f->zero = 1;
		*src += 1;
	}
	f->width = ft_atoi(*src);
	while (isadigit(**src))
		*src += 1;
	if (**src != '.')
		return ;
	*src += 1;
	f->precisen = ft_atoi(*src);
	while (isadigit(**src))
		*src += 1;
}
