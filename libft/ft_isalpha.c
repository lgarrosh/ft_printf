/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:50:45 by lgarrosh          #+#    #+#             */
/*   Updated: 2021/10/13 15:50:47 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int ch)
{
	if (((64 < ch) && (ch < 91)) \
			|| ((96 < ch) && (ch < 123)))
	{
		return (1);
	}
	return (0);
}