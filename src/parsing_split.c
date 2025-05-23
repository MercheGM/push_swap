/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mergarci <mergarci@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/03/25 16:27:38 by mergarci		  #+#	#+#			 */
/*   Updated: 2024/03/25 16:27:38 by mergarci		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

/* Gets the first index where the character is different from the space */
static int	ft_ptr_index(char const *s, int i, int num_words)
{
	while (ft_isspace(s[i]) && num_words != 0)
		i++;
	return (i);
}
 

/* Free memory*/
static char	**ft_freemem(char	**buffer)
{
	int	size;

	size = 0;
	while (buffer[size])
		free(buffer[size++]);
	free(buffer);
	return (NULL);
}

/* Count number of words. */
static int	ft_count_words(char const *s)
{
	int	cont;
	int	i;

	if (ft_strlen(s) == 0)
		return (0);
	i = 0;
	cont = 1;
	ft_printf("empezamos en... ~%c~\n", s[i]);
	while (ft_isspace(s[i]))
		i++;
	ft_printf("empezamos en... %d\n", i);
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) && !ft_isspace(s[i - 1]))
			cont++;
		i++;
	}
	if (s[i] == '\0' && ft_isspace(s[i - 1]))
		cont--;
	return (cont);
}

/* Split by words using c as separator. Free memory if error.*/
static char	**ft_split_words(char const *s, int num_words, char **dst)
{
	int		i;
	int		ini;
	int		cont;

	cont = 0;
	i = ft_ptr_index(s, 0, num_words);
	ini = i;
	while (cont < num_words)
	{
		if (ft_isspace(s[i]) || s[i] == '\0')
		{
			if (!ft_isspace(s[i - 1]))
			{
				dst[cont] = ft_substr(s, ini, i - ini);
				if (!dst[cont++])
					return (ft_freemem(dst));
			}
			ini = i + 1;
		}
		i++;
	}
	dst[cont] = NULL;
	return (dst);
}

/* Reserve an array of strings resulting from separating
the string 's' into substrings using the character 'c' as a delimiter. 
The array must be terminated with a NULL pointer.*/
char	**ft_split_spaces(char const *s)
{
	char	**ptr;
	int		num_words;

	num_words = ft_count_words(s);
	ft_printf("num_words: %d\n", num_words);
	ptr = (char **)ft_calloc(num_words + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr = ft_split_words(s, num_words, ptr);
	return (ptr);
}

/*int main()
{
	
	char **array;
	int cont = 0;
	//char *invalidReadCheck = (char *)malloc(sizeof(char));
	// *invalidReadCheck = 0;
	// array = ft_split(invalidReadCheck, 0);
	char *str = "   hola a todsss";
	array = ft_split(str, ' ');
	while (array[cont] != NULL)
	{
		printf(".%s.\n", array[cont]);
		cont++;
	} 
	return 0;
}*/