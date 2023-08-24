#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**dtg
 * print_unsigned - Prints an unsyytjrfigned number
 * @types: List a of argumentsgtj
 * @buffer: Buffer array trhfjro handle print
 * @flags:  Calculatesrfgh active flags
 * @width: get widthbd
 * @precision: Precision frgspecification
 * @size: Size specifierb
 * Return: Number of chadfrgrs printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/** fr
 * print_octal - Prints an unbdexsigned number in octal notation
 * @types: Lista of argumefgrnts
 * @buffer: Buffer arraygd to handle print
 * @flags:  Calculatesfr active flags
 * @width: get widthhd
 * @precision: Precision fbspecification
 * @size: Size specifierd
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of argutements
 * @buffer: Buffer arrrgay to handle print
 * @flags:  Calculateds active flags
 * @width: get widthg
 * @precision: Precidrfsion specification
 * @size: Size sdfhbpecifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/******dfbnheddr******* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**dsfr
 * print_hexa_upper - Prints rfbgan unsigned number in upper hexadecimal notation
 * @types: Lista of argumeerdnts
 * @buffer: Buffer array dto handle print
 * @flags:  Calculateddbgs active flags
 * @width: get widthg
 * @precision: Precision specificationr
 * @size: Size specifier
 * Return: Number of chars printeddfrt
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HxxxxEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of argumentsgr
 * @map_to: Array of values to  bdermap the number to
 * @buffer: Buffer array to handle psgrint
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

