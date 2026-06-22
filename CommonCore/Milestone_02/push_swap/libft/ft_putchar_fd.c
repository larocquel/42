/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:46:28 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/05 19:19:39 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <fcntl.h> // to use open()

int main(void)
{
    // Test 1: Writing to standard output (stdout)
    ft_putchar_fd('A', 1);

    // Test 2: Writing to standard error (stderr)
    ft_putchar_fd('B', 2);

    // Test 3: Writing to a file
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    ft_putchar_fd('C', fd); // Writes 'C' on "output.txt" file

    close(fd);
}
*/
