/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:15:43 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/16 18:57:47 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_spaces(char **av);
static int	gnl(t_stack **a, t_stack **b);
static int	do_ops(t_stack **a, t_stack **b, char *line);

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	if (ac > 2 && !av[1][0])
		return (ft_putstr_fd("Error\n", 2), -1);
	if (check_spaces(&av[1]) == 1 && ac == 2)
		return (ft_putstr_fd("Error\n", 2), -1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!av || !av[0])
		return (ft_putstr_fd("Error\n", 2), -1);
	a = init_stack_a(&a, av, ac);
	if (a)
		gnl(&a, &b);
	ft_free(&a, &b, av, ac);
	return (0);
}

static int	gnl(t_stack **a, t_stack **b)
{
	int		check;
	char	*line;

	check = 0;
	line = get_next_line(0);
	while (line)
	{
		check = do_ops(a, b, line);
		free(line);
		if (check == -1)
		{
			get_next_line(-1);
			return (ft_putstr_fd("Error\n", 2), -1);
		}
		line = get_next_line(0);
	}
	if (!ft_sorted(*a))
		return (ft_printf("KO\n"));
	else
		return (ft_printf("OK\n"));
	return (0);
}

static int	do_ops(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b, 0);
	else
		return (-1);
	return (0);
}

static int	check_spaces(char **av)
{
	int	i;
	int	j;

	if (!av)
		return (1);
	i = 0;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
