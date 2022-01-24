/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:57:42 by briffard          #+#    #+#             */
/*   Updated: 2022/01/24 16:33:54 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fillit.h"

/*newlist creation*/
List	newlist(void)
{
	return (NULL);
}

/*=============================================================================*/
/*REOMOVE ALL DOTS UNECESSARY*/

char	**ft_strtrim_dots(char **arr)
{
	if (!ft_strchr(arr[i], EMPTY))
		while(arr[i])
		{
			ft_bzero(arr[i], ft_strlen(arr[i]));
			arr[i] = ft_strdup

/*=============================================================================*/
/*COPY SHAPE IN A DOUBLE ARR AND REMOVING UNECESSARY CHAR*/
char	**cpy_to_double_arr(char *str, char **arr)
{
	int		line;
	int		column;
	int i = 0;

	line = 0;
	column = 0;

	while (str[i] != '\0')
	{
		if (str[i] == NEWLINE)
		{
			line++;
			i++;
			arr[line][column] = '\0';
			column = 0;
		}
		arr[line][column] = str[i];
		i++;
		column++;
	}
	arr[line][column] = '\0';
	return (arr);
}

/*=============================================================================*/
/*Created a new element and put at the end of the list*/
List	push_back_list(List li, char *shape)
{
	int				i;
	t_tetri_list	*element;
	t_tetri_list	*temp;
	

	i = 0;
	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_putstr_fd("Error: problem with dynamic allocation memory\n", 2);
		exit(EXIT_FAILURE);
	}
	element->tetriminos = (char **)ft_memalloc((sizeof(char *) * 4) + 1);
	while (i < 5)
	{
		element->tetriminos[i] = (char *)ft_memalloc((sizeof(char) * 4) + 1);
		i++;
	}
	element->tetriminos = cpy_to_double_arr(shape, element->tetriminos);
	element->next = NULL;
	if (!li)
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return (li);
}

/*============================================================================*/
/*PRINT LIST*/
/*void	print_list(List li)
{
	if (!li)
	{
		ft_putstr("Nothing to print, the list is empty.\n");
		return;
	}
	while (li != NULL)
	{
		ft_putstr(li->tetriminos);
		li = li->next;
	}
	ft_putchar('\n');
}
*/
/*============================================================================*/
/*REMOVE AN ELEMENT FROM THE BEGINING OF THE LIST*/
List	pop_front_list(List li)
{
	t_tetri_list	*element;
	
	element = malloc(sizeof(*element));
	if (!element)
	{
		ft_putstr_fd("Error: problem dynamic allocation memory\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!li)
		return (li);
	element = li->next;
	free(li);
	li = NULL;
	return (element);
}

/*===========================================================================*/
/*CLEAR ALL THE LIST*/

List	clear_list(List li)
{
	if (!li)
		return (li);
	while (li->next != NULL)
		li = pop_front_list(li);
	return (li);
}
 /*==========================================================================*/

int	main(int argc, char **argv)
{
	List			tetriminos;
	char			pieces[MAX_SIZE + 1];
	int				fd;
	int				ret;

	tetriminos = newlist();
	if (argc != 2)
		ft_putstr("Error// print usage message\n");
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_putstr("Error: open file.\n");
	while((ret = read(fd, pieces, MAX_SIZE)))
		{
			pieces[ret] = '\0';
			if (is_valid(pieces))
				tetriminos = push_back_list(tetriminos, pieces);
			else
			{
				ft_putstr_fd("Error: Not a valid tetriminos.\nEnd of the programm\n", 2);
				clear_list(tetriminos);
				break;
			}
		}
	close(fd);
//	print_list(tetriminos);
}