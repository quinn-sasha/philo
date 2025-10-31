#include "libftsubset.h"

int	ft_putstr_fd(const char *str, int fd)
{
	int	num_bytes;

	if (str == NULL)
		return (ft_putstr_fd("(null)", fd));
	num_bytes = 0;
	while (*str)
	{
		num_bytes += ft_putchar_fd(*str, fd);
		str++;
	}
	return (num_bytes);
}
