#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*copy;
	unsigned int	index1;
	unsigned int	index2;

	index1 = 0;
	index2 = start;
	if (!s)
		return (0);
	copy = (char*)malloc(sizeof(*copy) * (unsigned long)(len + 1));
	if (!copy)
		return (0);
	while (index2 >= start && index2 < (len + (size_t)start))
	{
		copy[index1] = s[index2];
		index1++;
		index2++;
	}
	copy[index1] = '\0';
	return (copy);
}


char	*ft_strcpy(char *dst, const char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

size_t		ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		length;
	int		index;

	index = 0;
	length = 0;
	while (src[length] != '\0')
		length++;
	copy = (char*)malloc(sizeof(*copy) * (length + 1));
	if (!copy)
		return (0);
	while (src[index] != '\0')
	{
		copy[index] = src[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}

static int	countparts(char const *string, char delimiter)
{
	int		count;
	int		flag;

	flag = 0;
	count = 0;
	while (*string)
	{
		if (flag == 1 && *string == delimiter)
			flag = 0;
		if (flag == 0 && *string != delimiter)
		{
			flag = 1;
			count++;
		}
		string++;
	}
	return (count);
}

static int	wordcharactercounter(char const *string, char delimiter)
{
	int		length;

	length = 0;
	while (*string != delimiter && *string)
	{
		length++;
		string++;
	}
	return (length);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		wordcount;
	int		index;

	if (!s)
		return (0);
	index = 0;
	wordcount = countparts(s, c);
	array = (char**)malloc(sizeof(*array) * (countparts(s, c) + 1));
	if (!array)
		return (0);
	while (wordcount--)
	{
		while (*s == c && *s)
			s++;
		array[index] = ft_strsub((const char*)s, 0, wordcharactercounter(s, c));
		if (!array[index])
			return (0);
		s = s + wordcharactercounter(s, c);
		index++;
	}
	array[index] = NULL;
	return (array);
}

