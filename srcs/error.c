#include "so_long.h"
#include "unistd.h"

int
	ft_put_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
