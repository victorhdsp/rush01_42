/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 09:40:18 by vide-sou          #+#    #+#             */
/*   Updated: 2024/06/22 17:28:06 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	write_string(int *word, int size)
{
	int	letter;
	int	breakline;

	letter = 0;
	breakline = 1;
	while(letter < (size*size))
	{
		printf("%d", word[letter]);	
		if (breakline >= size)
		{
			breakline = 0;
			printf("\n");
		}
		letter++;
		breakline++;
	}
}

int	main(void)
{
	char	params[8] = "3212";
	int	matriz[4][4] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	int position = 0;
	while (params[position])
	{
		// visão de cima
		if (position < 4)
		{
			int	line = 0;
			int count = 4 - (params[position] - 48);
			while (line < 4)
			{
				if (count >= 4)
					count = 0;

				matriz[line][position] = count  + 1;
				line++;
				count++;
			}
		}
		position++;
	}

	/*
	int position = 0;
	while (params[position] != '\0')
	{
		int column = 0;
		while (column < 4)
		{
			int	line = 0;
			while (line < 4)
			{
				matriz[line][column] = 1;
				line++;
			}
			column++;
		}
		position++;
	}*/

	write_string(&matriz[0][0], 4);
}
