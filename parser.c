#include "filit.h"

int findx(char *tetra)
{
	int x;
	int y;

	x = 0;

	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetra[x + (y * WIDTH)] == '#')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

int findy(char *tetra)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetra[x + (y * WIDTH)] == '#')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}


char *crop(char **tet_inpt)
{
	int pos;
	char *tetra;
	int x_ofs;
	int y_ofs;
	char *ret;

	ret = ft_memalloc(17);
	tetra = *tet_inpt;
	x_ofs = findx(tetra);
	y_ofs = findy(tetra);
	pos = 0;
	while (pos < 16)
	{
		if (tetra[pos] == '#')
		{
			ret[((_x(pos) - x_ofs) + WIDTH * (_y(pos) - y_ofs))] = 1;
		}
		pos++;
	}
	return (ret);
}

char **generate_arrays(char **tet_inpt)
{
	char size;
	char **tetraminos;
	char i;
	char *current;
	int size_f;
	size = (char) (ft_strlen(*tet_inpt) / 16);
	tetraminos = malloc(sizeof(char *) * 27);
	i = 0;
	current = ft_memalloc(17);
	while (size--)
	{
		tetraminos[i + 1] = ft_memalloc(17);
		i++;
	}
	size = (char) (ft_strlen(*tet_inpt) / 16);
	i = 0;
	size_f = size * 16;
	while (size--)
	{
		ft_memcpy(current, *tet_inpt, 16);
		tetraminos[i + 1] = crop(&current);
		tetraminos[i + 1][16] = (char) ('A' + i);
		*tet_inpt += 16;
		i++;
	}
	free((*tet_inpt - size_f));
	free(current);
	return (tetraminos);
}
