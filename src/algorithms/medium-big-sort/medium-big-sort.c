/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium-big-sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 12:20:39 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/26 11:34:37 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_game *game, int total)
{
	int		max_pos;
	t_final	*final;

	final = (t_final *)ft_calloc(1, sizeof(t_final));
	total = game->size_b;
	get_max(game, final);
	push_max_to_top(final, total, game);
	free(final);
}

void	push_chunks_to_b(t_game *game, t_info *info, int total, int max)
{
	t_stack	*ptr;

	ptr = game->stack_a;
	if (game->size_a == 1)
		pb(game);
	else if (game->size_a == 2)
	{
		if (game->stack_a->number < game->stack_a->next->number)
			ra(game);
		pb(game);
	}
	else
	{
		calculate_chunk(info, max);
		while (get_first_second(ptr, info, game))
		{
			push_min_to_top(info, total, game);
			push_correct_position(game);
		}
	}
}

void	set_num_of_chunks(t_game *game, t_info *info)
{
	if (game->size_a < 301)
		info->num_of_chunks = 5;
	else if (game->size_a < 401)
		info->num_of_chunks = 15;
	else
		info->num_of_chunks = 11;
}

void	medium_big_sort(t_game *game)
{
	int		total;
	int		min;
	int		max;
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	init_info(info);
	set_num_of_chunks(game, info);
	get_min_max(game->stack_a, &min, &max, game->size_a);
	total = game->size_a;
	while (game->stack_a)
		push_chunks_to_b(game, info, total, max);
	while (game->stack_b)
		push_back_to_a(game, total);
	free(info);
}