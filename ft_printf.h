/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:08:59 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/04/14 15:46:16 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	width;
	int	precisen;
	int	minus;
	int	zero;
	int	sign;
	int	resh;
	int	spase;
	int	len;
	int	negative;
}			t_flags;

int		ft_printf(const char *src, ...);
int		ft_nbrlen(long long int n, int base);
void	ft_put_n_char(char c, int len);
void	ft_free(void **b);
int		ft_pow(int nb, int pow);
int		ft_putchar(char ch);
int		ft_putstr(char *s);
int		ft_putnbr(long long int nb);
char	*ft_hexa(unsigned long long int nb, const char *src, int n);
char	*ft_fover(char **buff, int l);
int		ft_print_c(va_list *bp, t_flags f);
int		ft_print_s(va_list *bp, t_flags f);
int		ft_print_d(va_list *bp, t_flags f);
int		ft_print_i(va_list *bp, t_flags f);
int		ft_print_p(va_list *bp, t_flags f);
int		ft_print_x(va_list *bp, t_flags f);
int		ft_print_u(va_list *bp, t_flags f);
int		ft_printsx(va_list *bp, t_flags f);
int		ft_print_proc(t_flags f);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(long long int n);
int		ft_print(const char **src, va_list *ap, t_flags f);
void	updateflags(const char **src, t_flags *f);
t_flags	initflags(void);

#endif