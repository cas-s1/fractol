/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:07:54 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/27 16:29:53 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		slen;
	size_t		i;

	slen = ft_strlen(s);
	if (start > slen || s[0] == '\0')
		return (ft_strdup(""));
	slen -= start;
	if (len < slen)
		slen = len;
	str = (char *) malloc(sizeof(*s) * (slen + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (i < slen)
			str[i] = s[start + i];
		i++;
	}
	str[slen] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	testStr1[] = "42";
	char	*testStr2;
	testStr2 = ft_substr(testStr1, 0, 0);
	if (strcmp(testStr2, "") == 0)
		printf("SUCCESS");
	printf("%s\n", testStr2);
	return (0);
}
*/
