#include"header.h"

int insert_first(list_t **start, void *p)
{
	list_t *new;
	new = malloc(sizeof(list_t));
	if(!new){
		perror("malloc");
		return -1;
	}

	new->next = NULL;
	new->data = p;

	if(!(*start)){
		(*start) = new;
		return 0;
	}

	new->next = (*start);
	(*start) = new;
	
	return 0;
}

