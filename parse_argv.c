include "push_swap.h"
int					parse_argv(int argc, char **argv, t_node **nodes, t_config *config)
{
  char *str;
  char **regular_argv;

  str = ft_join(argc-1, &argv[1], ' ');
  if (!str)
    return ERROR;


  regular_argv = split(str, ' ');
  free(str);
  while(regular_argv)
  {
    str = *regular_argv;
    if (is_num())

    regular_argv++;
  }

}

./push_swap --simple --bench 5 4 3 2 1
./push_swap --simple 5 4 3 2 1
