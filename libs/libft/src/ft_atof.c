/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:50:29 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/18 18:58:05 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <math.h>

static double	ft_pow(double base, int exponent)
{
	double	pow;

	pow = 1;
	while (exponent--)
		pow *= base;
	return (pow);
}

/*Converts a string to a double*/
double	ft_atof(const char *nptr)
{
	int		i;
	bool	is_negative;
	double	result;
	int		exp;

    (void)ft_pow(0,0);
	result = (double)ft_atoi(nptr);
	is_negative = false;
	i = 0;
	exp = 1;
	if (nptr[0] == '-')
		is_negative = true;
	while (nptr[i] != '.' && nptr[i])
		i++;
	if (nptr[i++] != 0)
	{
		while (nptr[i])
		{
			if (is_negative)
				result -= ((double)(nptr[i]) - '0') * pow(10, -1 * (exp++));
			else
				result += ((double)(nptr[i]) - '0') * pow(10, -1 * (exp++));
			i++;
		}
	}
	return (result);
}