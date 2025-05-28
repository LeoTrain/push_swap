#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1)
		return (1);
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < argc)
		{
			if (j != i)
			{
				if (atoi(argv[i + 1]) == atoi(argv[j + 1]))
				{
					printf("FOUND DUPLICATE: %d %d\n", atoi(argv[i + 1]), atoi(argv[j + 1]));
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	printf("Nothing found\n");
	return (0);
}
