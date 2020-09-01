#include "get_next_line.h"

#include <stdio.h>
#define BUFFER_SIZE 10

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int				i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (!dst && !src)
		return (0);
	while (*(src + i) && i < size - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}

int	ft_strlcat(char *dst, const char *src, int size)
{
	int					i;
	int					j;

	i = 0;
	j = ft_strlen(dst);
	if (size <= j)
		return (size + ft_strlen(src));
	while (*(src + i) && i < size - j - 1)
	{
		*(dst + j + i) = *(src + i);
		i++;
	}
	*(dst + j + i) = '\0';
	return (j + ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;

	s_ptr = (char*)s;
	if (c == 0)
		return (s_ptr + ft_strlen(s_ptr));
	while (*s_ptr)
	{
		if (*s_ptr == c)
			return (s_ptr);
		s_ptr++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*ret;

	ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ret)
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		*(ret + i) = *(s1 + i);
		i++;
	}
	*(ret + i) = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	char				*s_ptr;
	unsigned	int		i;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	substr = (char*)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	s_ptr = (char*)s;
	i = 0;
	while (i < len)
	{
		*(substr + i) = *(s_ptr + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}

char 	*buf_join(char *dst, char *src)
{
	char	*str;
	int		d_len;
	int		s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (!(str = (char*)malloc(sizeof(char) * (d_len + s_len + 1))))
		return (0);
	ft_strlcpy(str, dst, d_len + 1);
	ft_strlcat(str, src, d_len + s_len + 1);
	if (!dst)
		free(dst);
	str[d_len + s_len] = '\0';
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int				rd;
	int				size;
	static	char	*buf[1024];
	char			*ptr;

	if (fd < 0)
		return (-1);
	if (!(buf[fd] = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!(*line = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	size = 0;
	if (buf[fd])
		*line = buf_join(*line, buf[fd]);
	while (((rd = read(fd, buf[fd], BUFFER_SIZE))) != 0)
	{
		size += rd;
		if (!(ptr = ft_strchr(&(buf[fd][rd + 1]),'\n')))
		{
			*line = buf_join(*line, buf[fd]);
			return (1);
		}
		*line = buf_join(*line, buf[fd]);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		ret;
	char	*line;
	int		fd;

	ret = 1;
	for (int i = 1; argv[i]; i++)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			return (0);
		printf("%d\n", fd);
		ret = 1;
		while (ret)
		{
			ret = get_next_line(fd, &line);
			if (!ret)
				break;
			printf("fd[%d] line : %s", fd, line);
			if (ret == -1)
			{
				write(1, "-1 !\n", 8);
				break;
			}
		}
		close(fd);
	}
	return (0);
}
