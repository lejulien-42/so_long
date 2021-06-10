
#include "so_long.h"
#include "get_next_line.h"
#include "fcntl.h"

void
	ft_getmap(t_game *game, char *path)
{
	int		fd;
	char	*line;
	char	*longmap;
	char	*tmp;
	int		length;
	int		old_length;

	old_length = 0;
	fd = open(path, O_RDONLY);
	longmap = NULL;
	if (fd == -1)
	{
		game->map = NULL;
		return ;
	}
	while (get_next_line(fd, &line))
	{
		length = ft_strlen(line);
		if (length)
		{
			tmp = ft_strjoin(longmap, line);
			free(longmap);
			longmap = ft_strdup(tmp);
			free(tmp);
		}
		if (length != 0)
		{
			if (old_length == 0 || length == old_length)
				old_length = length;
			else
			{
				free(line);
				game->map = NULL;
				return ;
			}
		}
		free(line);
	}
	free(line);
	game->mapX = old_length;
	game->mapY = ft_strlen(longmap) / old_length;
	game->map = longmap;
}
