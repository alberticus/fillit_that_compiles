#include "fillit.h"

int		cf1(char *input, int index, int line, int linesize)
{
	int count;

	count = 0;
	if (line == 0)
	{
		if (input[index + 1] == '#')
			count++;
		if (input[index - 1] == '#')
			count++;
		if (input[index + (linesize + 1)] == '#')
			count++;
	}
	return (count);
}

int		cf2(char *input, int index, int line, int linesize)
{
	int count;

	count = 0;
	if (line == linesize)
	{
		if (input[index + 1] == '#')
			count++;
		if (input[index - 1] == '#')
			count++;
		if (input[index - (linesize + 1)] == '#')
			count++;
	}
	return (count);
}

int		cf3(char *input, int index, int line, int linesize)
{
	int count;

	count = 0;
	if (line != 0 && line != linesize && line != linesize - 1)
	{
		if (input[index + 1] == '#')
			count++;
		if (input[index - 1] == '#')
			count++;
		if (input[index + (linesize + 1)] == '#')
			count++;
		if (input[index - (linesize + 1)] == '#')
			count++;
	}
	return (count);
}
