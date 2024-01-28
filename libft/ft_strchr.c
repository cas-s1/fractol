/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:14:30 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/28 22:44:55 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	while (*s != uc)
	{
		if (!(*s))
			return (0);
		s++;
	}
	return ((char *) s);
}
/*
int	main(void)
{
	char	teststr[] = "aabaaaaaaaaaaaabaaaa";
	char	*ptr;

	ptr = ft_strchr(teststr, 98);
	if (ptr)
		printf("%s\n", ptr);
	return (0);
}

*/
