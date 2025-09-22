/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrusli <nrusli@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:24:07 by nrusli            #+#    #+#             */
/*   Updated: 2025/09/21 00:24:07 by nrusli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int grid[4][4];
} Position;

int ft_atoi(const char *input_string, int *index_position)
{
    int number = 0;

    while (input_string[*index_position] == ' ')
    {
    (*index_position)++;
    }

    while (input_string[*index_position] >= '0' && input_string[*index_position] <= '9')
    {
        number = number * 10 + (input_string[*index_position] - '0');
        (*index_position)++;
    }

    return number;
}

void ft_fillgrid(char **argv, Position *position_pointer)
{
    int row;
    int column;
    int string_index;
    
    string_index = 0;
    row = 0;
    
    while (row <4)
    {
        column = 0;
        while (column <4)
        {
            (*position_pointer).grid[row][column] =
               ft_atoi(argv[1], &string_index);
            column++;
        }
        row++;
    }

}

int main(int argc, char **argv)
{
    Position position;

    if (argc != 2)
    {
        write(1, "Input format is incorrect", 26);
        return 1;
    }

    ft_fillgrid(argv, &position);

    return 0;
}