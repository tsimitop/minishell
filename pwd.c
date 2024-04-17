/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:18:23 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/17 13:25:22 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printpwd(void)
{
	char			cwd[1024];

	ft_printf("%s\n", getcwd(cwd, sizeof(cwd)));
}
