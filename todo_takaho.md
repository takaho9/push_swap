int					parse_argv(int argc, char *argv, t_node **nodes,
						t_config *config);
void				index_nodes(t_stack *stack);
void				simple_sort(t_node **node, t_ops *ops);
void				complex_sort(t_node **node, t_ops *ops);
void				display_bench(t_ops ops, t_config config);