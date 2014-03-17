#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<unistd.h>
#include<string.h>


typedef struct user {
	char name[20];
	int a;
	int b;
}user_t;

typedef struct node{
	void *data;
	struct node *next;
} node_t;


node_t *start = NULL;

int insert_last(void *p)
{
	node_t *new, *tmp;

	new = malloc(sizeof(node_t));
	if(!new){
		perror("malloc");
		exit(5);
	}

	new->data = p;
	new->next = NULL;

	if(!start){
		start = new;
		return 0;
	}

	tmp = start;
	while(tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	return 0;
}
int insert_first(void *p)
{
	node_t *new, *tmp;

	new = malloc(sizeof(node_t));
	if(!new){
		perror("malloc");
		exit(4);
	}
	new->data = p;
	new->next = NULL;

	if(!start){
		start = new;
		return 0;
	}
	new->next = start;
	start = new;
	return 0;
}

int delete_first()
{
	node_t *tmp;
	tmp = start;
	if(!start)
		return -1;
	

	start = tmp->next;
	free(tmp);
	return 0;
}
int delete_last(void)
{
	node_t *tmp, *prev;
	tmp = start;
	if(!start)
		return -1;
	
	while(tmp->next){
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	free(tmp);
	return 0;
}
int del(node_t *tmp, void *p)
{
	int ret;
	user_t *new = p;
	user_t *del1 = (user_t *) tmp->data;

	ret = strcmp(new->name,del1->name);
	return ret;
}
	
int delete_ele(int (*dele)(node_t *, void *), void *p)
{
	node_t *tmp, *prev;
	int ret;

	tmp = start;
	prev = start;
	if(!start)
		return -1;
	ret = (*dele)(start,p);
	if(ret ==0){
		start = tmp->next;
		free(tmp);
		return 0;
	}
	while(tmp){
		ret = (*dele)(tmp, p);
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

			

void d_pointer(node_t *p)
{
	user_t *obj;
	obj = p->data;

	printf("%s %d %d\n", obj->name, obj->a, obj->b);

	return;
}

int display(void (*d_pointer)(node_t *))
{

	node_t *tmp = start;

	while(tmp){
		(*d_pointer)(tmp);
		tmp=tmp->next;
	}
	printf("<<---------------------------->>>\n");

	return 0;
}


int main()
{
	user_t *obj1, *obj2, *obj3;
	int ret;

	obj1 = malloc(sizeof(user_t));
	if(!obj1){
		perror("malloc");
		exit(1);
	}

	strcpy(obj1->name, "sai");
	obj1->a = 2;
	obj1->b = 3;

	obj3 = malloc(sizeof(user_t));
	if(!obj3){
		perror("malloc");
		exit(6);
	}

	strcpy(obj3->name, "baba");
	obj3->a = 1;
	obj3->b = 2;

	obj2 = malloc(sizeof(user_t));
	if(!obj2){
		perror("malloc");
		exit(2);
	}

	strcpy(obj2->name, "praveen");
	obj2->a = 4;
	obj2->b = 5;

	ret = insert_last(obj1);
	ret = insert_first(obj3);
	ret = insert_last(obj2);
	display(d_pointer);

	ret = delete_first();
	ret = delete_last();
	display(d_pointer);
	ret = insert_last(obj2);
	ret = insert_last(obj3);
	display(d_pointer);
	printf("deleting praveen profile\n");
	delete_ele(del,obj2);
	display(d_pointer);

	return 0;
}
