/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:45:56 by briffard          #+#    #+#             */
/*   Updated: 2022/02/01 18:20:49 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*readfile and store in a linked list*/
tetri_list	create_tetri_list(int fd)
{
	tetri_list	li;
	int			ret;
	char		pieces[MAX_SIZE + 1];

	li = newlist();
	ret = read (fd, pieces, MAX_SIZE);
	while (ret > 0)
	{
		pieces[ret] = '\0';
		if (is_valid(pieces))
		{
			li = push_back_list(li, pieces);
			if (!li)
				return (NULL);
		}
		else
		{
			clearList(li);
			return (li);
		}
		ret = read(fd, pieces, MAX_SIZE);
	}
	return (li);
}