/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:50:04 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/29 16:07:08 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *) malloc(len * sizeof(char));
	if (!s)
		return (0);
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	ft_strlcpy(s + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	s[len - 1] = 0;
	return (s);
}
/*
int	main(void)
{
	char *text[10];

	text[0] = "i";
	text[1] = "am";
	text[2] = "a";
	text[3] = "silly";
	text[4] = "litle";
	text[5] = "man";
	text[6] = "writing";
	text[7] = "some";
	text[8] = "silly";
	text[9] = "code";

	printf("%s\n", ft_strjoin(10, text, "\n"));
}
*/
