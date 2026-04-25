/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:56:54 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/26 12:52:16 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_put_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_put_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_put_digit(va_arg(ap, int), 10, specifier);
	else if (specifier == 'u')
		count += ft_put_digit(va_arg(ap, unsigned int), 10, specifier);
	else if (specifier == 'x' || specifier == 'X')
		count += ft_put_digit(va_arg(ap, unsigned int), 16, specifier);
	else if (specifier == 'p')
		count += ft_put_ptr((unsigned long)va_arg(ap, void *));
	else
		count += ft_put_char(specifier);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
			len += ft_type(*(++format), ap);
		else
			len += ft_put_char(*format);
		format++;
	}
	va_end(ap);
	return (len);
}

/* int	main()
{
	int	count_mine = 0;
	int	count_original = 0;

	// Test 1: c
	printf("Test 1: %%c CHAR\n");

	char	ch = 'A';
	ft_printf("Mine    : ");
	count_mine = ft_printf("%c", ch);
	ft_printf(" | count = %d\n", count_mine);

	printf("Original: ");
	count_original = printf("%c", ch);
	printf(" | count = %d\n", count_original);
	printf("----------------------------------------\n");

	// Test 2: s
	printf("Test 2: %%s STRING\n");
	char	*str = "Hello, World!";
	ft_printf("Mine    : ");
	count_mine = ft_printf("%s", str);
	ft_printf(" | count = %d\n", count_mine);

	printf("Original: ");
	count_original = printf("%s", str);
	printf(" | count = %d\n", count_original);
	printf("----------------------------------------\n");

	// Test 3: d
	printf("Test 3: %%d INTEGER (BASE10)\n");
	int	nd = 123;
	ft_printf("Mine    : ");
	count_mine = ft_printf("%d", nd);
	ft_printf(" | count = %d\n", count_mine);

	printf("Original: ");
	count_original = printf("%d", nd);
	printf(" | count = %d\n", count_original);
	printf("----------------------------------------\n");

	// Test 4: i
	printf("Test 4: %%i INTEGER\n");
	int	ni = -123;
	ft_printf("Mine    : ");
	count_mine = ft_printf("%i", ni);
	ft_printf(" | count = %d\n", count_mine);

	printf("Original: ");
	count_original = printf("%i", ni);
	printf(" | count = %d\n", count_original);
	printf("----------------------------------------\n");

	// Test 5: u
	printf("Test 5: %%u UNSIGNED\n");
	unsigned int	nu = 123;
	ft_printf("Mine    : ");
	count_mine = ft_printf("%u", nu);
	ft_printf(" | count = %d\n", count_mine);

	printf("Original: ");
	count_original = printf("%u", nu);
	printf(" | count = %d\n", count_original);
	printf("----------------------------------------\n");

	// Test 6: x
	printf("Test 6: %%x HEXADECIMAL LOWER\n");
	int	nx = 42;
	ft_printf("Mine    : ");
	count_mine = ft_printf("%x", nx);
	ft_printf(" | count = %d\n", count_mine);

	printf("Original: ");
	count_original = printf("%x", nx);
	printf(" | count = %d\n", count_original);
	printf("----------------------------------------\n");

	// Test 7: X
	printf("Test 7: %%X HEXADECIMAL UPPPER\n");
	int	nX = -42;
	ft_printf("Mine    : ");
	count_mine = ft_printf("%X", nX);
	ft_printf(" | count = %d\n", count_mine);

	printf("Original: ");
	count_original = printf("%X", nX);
	printf(" | count = %d\n", count_original);
	printf("----------------------------------------\n");

	// Test 8: p
	printf("Test 6: %%p POINTER ADRESS\n");
	int	*ptr = &nX;

	ft_printf("Mine    : ");
	count_mine = ft_printf("%p", ptr);
	ft_printf(" | count = %d\n", count_mine);

	printf("Original: ");
	count_original = printf("%p", ptr);
	printf(" | count = %d\n", count_original);
	printf("----------------------------------------\n");
} */
