/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:42:34 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/29 15:59:53 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	move(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

void	move_reverse(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	d = dest;
	s = src;
	i = n;
	while (i > 0)
	{
		i--;
		d[i] = s[i];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!src && !dest)
		return (0);
	if (src < dest)
	{
		move_reverse(dest, src, n);
	}
	else
	{
		move(dest, src, n);
	}
	return (dest);
}
/*
int	main(void)
{
	char	testStr[50] = "aabbccdd";

	printf("testStr before memmove:\n%s\n", testStr);
	memcpy(testStr+2, testStr, 4);
	printf("testStr after memmove:\n%s\n", testStr);
	return (0);
}
*/
