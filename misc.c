#include "filit.h"

int _x(int pos)
{
	return (pos % 4);
}

int _y(int pos)
{
	return (pos / 4);
}

void remove_symbols(char **s, char c)
{
	char *s_ptr;
	size_t size;
	char *ret;

	s_ptr = *s;
	size = 0;
	while (*s_ptr)
	{
		if (*s_ptr != c)
			size++;
		s_ptr++;
	}
	ret = ft_strnew(size);
	s_ptr = *s;
	size = (size_t) ret;
	while (**s)
	{
		if (**s != c)
		{
			*ret = **s;
			ret++;
		}
		(*s)++;
	}
	free(s_ptr);
	*s = (char *) (size);
}