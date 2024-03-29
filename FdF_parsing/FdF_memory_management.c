/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_memory_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:51 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/25 18:29:36 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	free_and_quit_program(char *line, char **tokens, t_data *data)
{
	free_map_struct(data->map_data);
	ft_free_array(tokens);
	free(line);
	exit (0);
}

void	free_map_struct(t_map *map_data)
{
	t_map	*current;
	t_map	*next;

	current = map_data;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return ;
}

void	free_all(t_data *data)
{
	free_map_struct(data->map_data);
	free(data->mlx->mlx_ptr);
	free(data->mlx->win_ptr);
	free(data->mlx);
}
