/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 18:52:14 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/23 19:22:07 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(int *stack)
{
	int tmp;

	tmp = 0;
	tmp = *stack;
	*stack = *(stack + 1);
	*(stack + 1) = tmp;
}

void	swap_both(int *stack_a, int *stack_b)
{
	
}