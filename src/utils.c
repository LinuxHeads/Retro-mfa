/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:17:54 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/07 09:53:19 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfa.h"

bool	endswith(const char *str, const char *suffix)
{
	size_t	str_len;
	size_t	suffix_len;

	str_len = strlen(str);
	suffix_len = strlen(suffix);
	if (suffix_len > str_len)
		return (false);
	return (strcmp(str + str_len - suffix_len, suffix) == 0);
}
