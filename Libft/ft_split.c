#include "libft.h"

int		count_word(char const *s, char c)
{
	int			cnt;
	int			i;
	int			flag;
	
	i = 0;
	cnt = 0;
	flag = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			flag = 0;
		else if (*(s + i) != c && flag == 0)
		{	
			cnt++;
			flag = 1;
		}
		i++;
	}
	return (cnt);
}

int		word_len(char const *s, char c)
{
	int			i;
	int			len;
	
	i = 0;
	len = 0;
	while(*(s + i) && *(s + i) == c)
		i++;
	while(*(s + i) && *(s + i) != c)
	{
		len++;
		i++;
	}
	return (len);
}

void	free_ret(char **ret, int idx)
{
	int				i;
	
	i = 0;
	while (i < idx)
	{
		free(*(ret + i));
		i++;
	}
	free(ret);
}

char	**put_word(char **ret, char const *s, char c, int cnt)
{
	int			i;	
	int			j;
	int			len;
	char		*s_ptr;
	
	i = 0;
	len = 0;
	s_ptr = (char*)s;
	while (i < cnt)
	{
		j = 0;
		len = word_len(s_ptr, c);
		*(ret + i) = (char*)malloc(sizeof(char) * (len + 1));
		if (!(*(ret + i)))
		{
			free_ret(ret, i);
			return (0);
		}
		while (*(s_ptr + j) == c)
			j++;
		ft_strlcpy(*(ret + i), s_ptr + j, len + 1);
		s_ptr += j + len;
		i++;
	}
	*(ret + i) = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char		**ret;
	int			word_cnt;
	
	if (!s)
		return (0);
	if (!c)
		return ((char**)s);
	word_cnt = count_word(s, c);
	ret = (char**)malloc(sizeof(char*) * (word_cnt + 1));
	if (!ret)
		return (0);
	ret = put_word(ret, s, c, word_cnt);
	return (ret);
}

/*int		main(void)
{
	char	str[] = "sunny1pll1write";
	char	**ret;
	int		i;

	ret = ft_split(str, '1');
	if(!ret)
		return (0);
	printf("original : %s\n", str);
	i = 0;
	while(*(ret + i))
	{
		printf("%d : %s\n", i, *(ret + i));
		i++;
	}
	return (0);
}
*/
