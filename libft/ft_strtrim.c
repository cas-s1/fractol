/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:42:17 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/30 13:12:05 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	len;

	len = ft_strlen(s1);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = 0;
	while (len > start + end && ft_strchr(set, s1[len - end - 1]) != NULL)
		end++;
	trim = (char *) malloc(len - start - end + 1);
	if (!trim)
		return (0);
	ft_memcpy(trim, s1 + start, len - start - end);
	trim[len - start - end] = '\0';
	return (trim);
}
