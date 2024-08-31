/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:06:18 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/22 21:37:23 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trm;
	int		i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	i = ft_strlen(s1);
	while (i >= 0 && ft_strchr(set, s1[i]))
		i--;
	trm = ft_substr(s1, 0, i + 1);
	if (!trm)
		return (NULL);
	return (trm);
}
