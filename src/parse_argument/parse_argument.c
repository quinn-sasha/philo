#include "philo.h"

static bool is_numeric(char *str) {
  if (*str == '\0')
    return false;
  int i = 0;
  while (str[i]) {
    if (!ft_isdigit(str[i]))
      return false;
    i++;
  }
  return true;
}

static int get_non_negative_int(const char *str) {
  if (!is_numeric(str))
    return -1;
  if (ft_strcmp(str, INT_MAX_STRING) > 0)
    return -1;
  return ft_atoi(str);
}

// Reference: https://github.com/usatie/philosophers/blob/master/philo/src/argsparse/argsparse.c
static int usage_error(void) {
	ft_putstr_fd(
		"USAGE:\n"
		"  ./philo number_of_philosophers time_to_die time_to_eat "
		"time_to_sleep [number_of_times_each_philosopher_must_eat]\n"
		"\n"
		"DESCRIPTION:\n"
		"  - number_of_philosophers is valid between 1 to MAX_PHILO.\n"
		"    (Default value for MAX_PHILO is 200.)\n"
		"  - number_of_times_each_philosopher_must_eat must be non-zero\n"
		"    value. When it is negative or not specified, the simulation\n"
		"    does not end until someone dies.\n"
		"VALID EXAMPLE:\n"
		"  ./philo 5 500 100 100\n"
		"  ./philo 5 500 100 100 10\n"
		"INVALID EXAMPLE:\n"
		"  ./philo 5 500 100\n"
		"  ./philo 5 500 100 100 10 100\n"
		"  ./philo 5 9999999999999999 100 100 10\n",
		STDERR_FILENO);
  return PARSE_ERROR;
}

int parse_argsument(t_argss *args, int argsc, char *argsv[]) {
  if (argsc != MIN_NUM_ARGUMENTS || argsc != MIN_NUM_ARGUMENTS + 1)
    return PARSE_ERROR;
  args->num_philo = get_non_negative_int(argsv[1]);
  if (args->num_philo <= 0)
    return usage_error();
  args->time_to_die_ms = get_non_negative_int(argsv[2]);
  if (args->time_to_die_ms < 0)
    return usage_error();
  args->time_to_eat_ms = get_non_negative_int(argsv[3]);
  if (args->time_to_die_ms < 0)
    return usage_error();
  args->time_to_sleep_ms = get_non_negative_int(argsv[4]);
  if (args->time_to_die_ms < 0)
    return usage_error();
  if (argsc == MIN_NUM_ARGUMENTS) {
    args->max_eat = -1;
    return PARSE_SUCCESS;
  }
  args->max_eat = get_non_negative_int(argsv[5]);
  if (args->max_eat <= 0)
    return usage_error();
  return PARSE_SUCCESS;
}
