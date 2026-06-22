/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
     ||
     \/
 0110  0100
 */

unsigned char   reverse_bits(unsigned char octet)
{
	int i = 0;
	unsigned char result = 0;

	while(i < 8)
	{
		result = ((result << 1) | (octet & 1));
		octet >>= 1;
		i++;
	}
	return (result);
}

#include <stdio.h>

int	main(void)
{
	unsigned char original = 0b01000001; 
	unsigned char reversed = reverse_bits(original);

	printf("Original : 0b");
	for (int i = 7; i >= 0; i--)
		printf("%d", (original >> i) & 1);

	printf("\nReversed : 0b");
	for (int i = 7; i >= 0; i--)
		printf("%d", (reversed >> i) & 1);

	printf("\n");
	return (0);
}

