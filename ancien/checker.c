/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:16:43 by yachen            #+#    #+#             */
/*   Updated: 2023/07/10 14:31:11 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*read_instruc(int fd)
{
	char	*string;
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	tmp = line;
	while (1)
	{
		string = get_next_line(fd);
		line = ft_strjoin(line, string);
		if (!line)
			return (NULL);
		free(tmp);
		if (string == NULL)
			break ;
		free(string);
	}
	return (line);
}

static int	ft_compare(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s2 == *s1)
		{
			while (*s1 && *s2 == *s1)
			{
				s1++;
				s2++;
			}
			if (*s1 == '\0')
				return (1);
			s1 = s1 + 0;
		}
		s2++;
	}
	return (0);
}

static int	sub_parsing(char **ptrstr, char *inst)
{
	while (*ptrstr)
	{
		if (ft_compare(*ptrstr, inst + 0) == 0)
			return (0);
		ptrstr++;
	}
	return (1);
}

static void	parsing_instruct(char *line)
{
	char	**ptrstr;
	char	*inst;

	inst = "sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n";
	ptrstr = ft_split(line, '\n');
	if (!ptrstr || sub_parsing(ptrstr, inst) == 0)
	{
		free_tab(ptrstr);
		free(line);
		ft_error();
	}
}

int	main(int argc, char **argv)
{
	char	*instruct;

	parsing(argc, argv);
	instruct = read_instruc(0);
	parsing_instruct(instruct);
}
