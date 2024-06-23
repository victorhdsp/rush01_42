/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:55:32 by vide-sou          #+#    #+#             */
/*   Updated: 2024/06/23 15:55:34 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    create_line(int size, int direction, int offset)
{
    int     position = 0;
    int     count;

    if (direction > 0)
        count = 1 + offset -1;
    else
        count = size - offset +1;

    while (position < size)
    {
        ft_putchar('0' + count);
        if (direction >= 0)
        {
            count++;
            if (count > size)
                count = 1;
        }
        else
        {
            count--;
            if (count < 1)
                count = size;
        }
        position++;
    }
}

void    create_table(int size, char input[16])
{
    int position = 0;
    while (input[position])
    {
        int direction = 1;
        if (position > 7 && position < 12)
        {
            int first_digit = (input[position] - 48);
            int last_digit = (input[position + 4] - 48);
            int value = (first_digit + last_digit) - first_digit;

            if (input[position - 1] == input[position + 4])
                direction = direction * -1;
            
            create_line(size, direction, value);
            ft_putchar('\n');
            
        }
        position++;
    }
    
    ft_putchar('\n');
    create_line(size, 1, 3);
    ft_putchar('\n');
    create_line(size, -1, 3);
    ft_putchar('\n');
    create_line(size, -1, 1);
    ft_putchar('\n');
    create_line(size, 1, 1);
}

int    main(void)
{
    char    input[16] = "2123232122142241";
    //char    output[16];

    //checker("1234432121433412");
    create_table(4, input);
}
