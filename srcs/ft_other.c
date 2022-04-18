/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:25 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:17:44 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_free(void **b)
{
	free(*b);
	*b = NULL;
}

char	*ft_hexa(unsigned long long int nb, const char *src, int n)
{
	char	*buff;
	int		i;

	if (n < 2 && n > 16)
		return (NULL);
	buff = (char *)ft_calloc(1, 20);
	if (!buff)
		return (NULL);
	i = 0;
	while (nb > (unsigned int)n - 1)
	{
		buff[i] = *(src + (nb % n));
		nb = nb / n;
		i++;
	}
	buff[i] = *(src + nb);
	buff = ft_fover(&buff, i);
	return (buff);
}

char	*ft_fover(char **buff, int l)
{
	char	*nbuff;
	int		i;

	nbuff = ft_calloc(1, l + 2);
	if (!nbuff)
	{
		ft_free((void **)buff);
		return (NULL);
	}
	i = 0;
	while (l >= 0)
	{
		nbuff[l] = (*buff)[i];
		l--;
		i++;
	}
	ft_free((void **)buff);
	return (nbuff);
}

int	ft_nbrlen(long long int n, int base)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		l++;
	}
	return (l);
}

void	ft_put_n_char(char c, int len)
{	
	while (len)
	{
		ft_putchar(c);
		len--;
	}
}
