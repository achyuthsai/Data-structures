#include"header.h"

int delete_ele(list_t **start, int (*fp)(list_t *, void *), void *p)
{
	list_t *tmp, *prev;
	int ret;

	tmp = (*start);
	prev  = (*start);

	ret = (*fp)((*start), p);
	if(ret==0){
		(*start) = tmp->next;
		free(tmp);
		return 0;
	}

	while(tmp){
		ret = (*fp)(tmp, p);
		if(ret==0){
			prev->next = tmp->next;
			free(tmp);
			return 0;
		}

		prev = tmp;
		tmp = tmp->next;

	}
	
		return 0;
}

