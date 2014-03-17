#include"header.h"

int insert_last(list_t **start, void *p)
{

	list_t *new, *tmp;
	new = malloc(sizeof(list_t));
	if(!new){
			perror("malloc");
			return -1;
	}

	new->data = p;
	new->next = NULL;
	if(!(*start)){
		(*start) = new;
		return 0;
	}

	tmp = (*start);
	while(tmp->next)
		tmp = tmp->next;
	
	tmp->next = new;

	return 0;
}
	


