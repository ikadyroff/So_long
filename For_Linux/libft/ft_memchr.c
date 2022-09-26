/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:24:39 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/15 16:49:09 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	sym;

	i = 0;
	str = (unsigned char *)s;
	sym = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == sym)
			return (str + i);
		i++;
	}
	return (NULL);
}
