/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:16:08 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/14 12:06:51 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_env_path(char **env, char **flags)
{
	char	**path;
	char	*cmd;
	int		i;

	path = ft_path_split(env);
	i = 0;
	while (path[i])
	{
		cmd = strdup(path[i]);
		ft_strlcat(cmd, "/", ft_strlen(cmd) + 2);
		ft_strlcat(cmd, flags[0], ft_strlen(cmd) + ft_strlen(flags[0]) + 1);
		if (access(cmd, X_OK | R_OK) == 0)
			break ;//si no lo encuentra
		free(cmd);
		i++;
	}
	ft_free_matrix(path);
	return (cmd);
}

char	**ft_path_split(char **env)
{
	char	**path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i] != NULL)
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			path = ft_split(env[i], ':');
			break ;
		}
		i++;
	}
	return (path);
}
