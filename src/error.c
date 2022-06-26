#include "fdf.h"

void	errors(int code)
{
	if (code == 1)
	{
		ft_putstr_fd("Fatal ERROR: Too few/much arguments!\n", 0);
		exit(0);
	}
	else if (code == 2)
	{
		ft_putstr_fd("Fatal ERROR: Found wrong line length!\n", 0);
		exit(0);
	}
	else if (code == 3)
	{
		ft_putstr_fd("Fatal ERROR: Memory allocation problem!\n", 0);
		exit(0);
	}	
}
