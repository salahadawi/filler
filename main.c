/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:44:39 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/04 20:03:23 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		main(void)
{
	char *line;

	//ft_fprintf(0, "3 5\n");
	while (get_next_line(0, &line) > -1)
	{
		//ft_printf("%s", line);
		//ft_printf("3 5\n");
		free(line);
	}
	ft_printf("3 5\n");
	return (0);
}
