#include"header.h"


int display(list_t **start, void (*fp)(list_t *))
{
	list_t *tmp;
	tmp = (*start);

	while(tmp){
		(*fp)(tmp);
		tmp = tmp->next;
	}
	printf("<<----------over---------->>\n");

	return 0;
}


