#include "main.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*list;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	list = (void *)malloc((len + 1) * sizeof(char));
	count = 0;
	if (!list)
		return (NULL);
	while (count < len && s[start])
	{
		list[count] = s[start];
		count++;
		start++;
	}
	list[count] = '\0';
	return (list);
}