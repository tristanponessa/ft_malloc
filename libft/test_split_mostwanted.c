/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split_mostwanted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:27:27 by trponess          #+#    #+#             */
/*   Updated: 2018/07/26 19:39:47 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int    main(int ac, char **av)
{
	ft_use_args(ac, av, NULL);

	//char *z;
	char *s;
	char *clean_s;
	char **sep;
	char **tab;
	char rep;
	char single_sep;
	char *safe;
	char *save;



	s = ft_strnew(100);
	ft_strcpy(s, "echo \"hi there\" my friend \"here it is\"");
	save = ft_strdup(s); // s is modified in str most 

	safe = ft_strnew(5);
	safe[0] = '\"';
	safe[1] = '\"';

	rep = '*';

	single_sep = '*';
	sep = ft_dstrnew(5,50);
	ft_strcpy(sep[0], "PATH=");
	ft_strcpy(sep[1], ":");
	ft_strcpy(sep[2], " ");


ft_printf("---------------TEST MOST WANTED-----------\n\n");
	ft_printf("<s:%s>\n<s1:(%s) s2:(%s) s3:(%s)>\n<rep:%c>\n<safe1:%c safe2:%c>\n", s, sep[0], sep[1], sep[2], rep, safe[0], safe[1]);
	ft_printf("\n|%s|\n", s);
	clean_s = str_most_wanted_protect(s, sep, rep, safe);
	//clean_s = str_most_wanted_protect(s, sep, rep, safe);
	ft_printf("|%s|\n", clean_s);


 ft_printf("\n\n----------TEST split------------\n\n");
		ft_printf("single_rep :%c\n", single_sep);
		ft_printf("|%s|\n\n", clean_s);
		tab = ft_split_spaces(clean_s, single_sep);
		ft_putdstr(tab);

ft_printf("\n\n--------TEST split_most_wanted(fusion)----------\n\n");
		ft_printf("<s:%s>\n<s1:(%s) s2:(%s) s3:(%s)>\n<rep:%c>\n<safe1:%c safe2:%c>\n", save, sep[0], sep[1], sep[2], rep, safe[0], safe[1]);
		ft_printf("\n|%s|\n", save);
		tab = ft_split_most_wanted(save, sep, rep, safe);
		ft_putdstr(tab);


ft_printf("\n\n--------TEST split most wanted GET ARGUMENT LINE----------\n\n");
		
		char *line;
		line = NULL;
		get_next_line(0, &line);//much more harders
		ft_printf("LINE > |%s|\n", line);
		char **args;
		args = NULL;
		args = ft_split_most_wanted(line, ft_split_spaces(" ", 'n'), '*', "\"\"");
		ft_putdstr(args);

ft_printf("\n\n--------TEST dstrjoin && dstrlen----------\n\n");
	ft_printf("dstr1 :<size:%d>\n", ft_dstrlen(tab));
	ft_putdstr(tab);
	char **new;
	new = ft_split_spaces("Going to the united stateS", ' ');
	ft_printf("\ndstr2 :<size:%d>\n", ft_dstrlen(new));
	ft_putdstr(new);
	ft_printf("\n\n");
	char **fusion;
	fusion = ft_dstrjoin(tab, new);
	ft_printf("\nfusion :<size:%d>\n", ft_dstrlen(fusion));
	ft_putdstr(fusion);

	//ft_leak_collector(NULL, "show");
	ft_leak_collector(NULL, "free");
    return (0);
}



//------------------------------


