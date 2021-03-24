/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:16:29 by fcivetta          #+#    #+#             */
/*   Updated: 2021/03/24 16:32:28 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **list_to_array(t_env   *env)
{
    t_env   *tmp;
    char    **tab;
    int     i;

    i = 0;
    tmp = env;
    len = ft_lstsize(tmp);
    if(!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
        error(MEM_ERR);
    while (tmp != NULL)
    {
        tab[i] = tmp->var;
        i++;
        tmp = tmp->next;
    }
    return (tab);
}