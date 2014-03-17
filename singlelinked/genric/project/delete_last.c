#include"header.h"

int delete_last(list_t **start)
{
	list_t *tmp, *prev;
	tmp = (*start);

	while(tmp->next){
		prev = tmp;
		tmp = tmp->next;
	}

	prev->next = NULL;
	free (tmp);
	return 0;
}

	
