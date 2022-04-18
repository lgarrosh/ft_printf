/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:11:25 by lgarrosh          #+#    #+#             */
/*   Updated: 2021/12/29 18:10:08 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_arr(long long int t, int s)
{
	char			*ch;
	size_t			len;
	long long int	i;

	i = t;
	len = 0;
	if (t == 0)
		len = 1;
	while (i)
	{
		i /= 10;
		len++;
	}
	ch = (char *)ft_calloc(len + 1 + s, sizeof(char));
	if (!ch)
		return (0);
	while (len)
	{
		ch[len - 1 + s] = (t % 10) + 48;
		t /= 10;
		len--;
	}
	return (ch);
}

char	*ft_itoa(long long int n)
{
	long long int	i;
	int				s;
	char			*ch;

	s = 0;
	if (n < 0)
	{
		s = 1;
		i = -1 * n;
	}
	else
		i = n;
	ch = ft_arr(i, s);
	if (!ch)
		return (0);
	if (s)
		ch[0] = '-';
	return (ch);
}
