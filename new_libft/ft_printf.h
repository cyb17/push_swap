/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:20:58 by yachen            #+#    #+#             */
/*   Updated: 2023/06/20 11:16:58 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf_char(char c);
int		ft_printf_str(char *str);
int		ft_printf_nbr(int n);
int		ft_printf_hexa(unsigned int nbr, int indice);
int		ft_printf_unsi(unsigned int nb);
int		ft_printf_ptr(unsigned long long ptr);
int		ft_printf(const char *format, ...);

#endif
