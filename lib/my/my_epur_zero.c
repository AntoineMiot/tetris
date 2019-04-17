/*
** EPITECH PROJECT, 2017
** my_epur_zero
** File description:
** my_epur_zero
*/
int my_strlen(char const *str);

char *my_epur_zero(char *str)
{
	if (my_strlen(str) == 1)
		return (str);
	while (str[0] == '0' && str[0] && str[1] != '\0')
			str++;
	return (str);
}