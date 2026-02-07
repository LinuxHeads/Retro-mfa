/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfa_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:13:54 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/07 09:53:02 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfa.h"

t_mfa	*load_mfa(FILE *input)
{
	t_mfa	*mfa;
	long	file_size;

	mfa = malloc(sizeof(t_mfa));
	if (mfa == NULL)
	{
		write(2, "Error: Failed to load MFA file\n", 31);
		fclose(input);
		exit(1);
	}
	// memory allocation for the whole size of the file
	file_size = getFileSize(input);
	mfa->data = malloc(file_size);
	if (mfa->data == NULL)
	{
		free(mfa);
		write(2, "Error: Failed to load MFA file\n", 31);
		fclose(input);
		exit(1);
	}
	mfa->size = file_size;
	// read into mfa->data
	fread(mfa->data, 1, file_size, input);
	return (mfa);
}

void	free_mfa(t_mfa *mfa)
{
	if (mfa)
	{
		free(mfa->data);
		free(mfa);
	}
}
