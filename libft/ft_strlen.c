/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:34:23 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/13 18:02:48 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *ch)
{
	int	i;

	i = 0;
	if (!ch)
		return (6);
	while (ch[i] != '\0')
		i++;
	return (i);
}
