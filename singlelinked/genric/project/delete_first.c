#include"header.h"

int delete_first(list_t **start)
{
	list_t *tmp;
	if(!(*start))
		return -1;

	tmp = (*start);

	(*start) = tmp->next;
	free(tmp);
	return 0;
}
