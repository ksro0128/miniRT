/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:58:39 by surkim            #+#    #+#             */
/*   Updated: 2024/01/08 13:52:45 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_error("인자의 개수가 올바르지 않습니다.");
	init(&data);
	parsing(&data, argv[1]);
	draw(&data);
	control(&data);
	exit(0);
}
