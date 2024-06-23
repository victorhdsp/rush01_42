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


int	coefBinomial(int n, int k)
{
	if (k == 0 || k == n)
	{
		return (1);
	}
	return coefBinomial(n - 1, k - 1) + coefBinomial(n - 1, k);
}

// substitua pela logica real da funcao
int g(int k, int x)
{
	// calculo para definir a quantidade de variaveis possiveis 
	k = k + x;
	return (1);
}

int fn(int n, int a, int b)
{
	int soma = 0;
	int k = 0;

	while ( k < n )
	{
		int binom = coefBinomial(n - 1, k);
		int g1 = g(k, a - 1);
		int g2 = g(n - k - 1, b -1);
		soma += binom * g1 * g2;
		k++;
	}
	return soma;
}







int	main(void)
{
	/*char	params[8] = "3212";
	int	matriz[4][4] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};*/
	int i = 0;
	int	n = 4;

	// n = quantidade de posicoes (ou 4)
	// a soma das laterais diretamente opostas deve ser entre 2 e n + 1 (ou 5)
	//
	while (i < 4)
	{
		int a = 3;
		int b = 4;

		int resultado = fn(n, a, b);
		printf("f_%d(%d, %d) = %d\n", n, a, b, resultado);
	}

	return (0);
}


