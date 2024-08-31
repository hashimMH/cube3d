/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:14:22 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/22 21:37:04 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;	

	i = 0;
	tmp = (char *)haystack;
	if (!haystack && len == 0)
		return (NULL);
	if (needle[i] == '\0')
		return (tmp);
	while (tmp[i] != '\0')
	{
		j = 0;
		while (tmp[i + j] != '\0' && tmp[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (&tmp[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
