#include<stdio.h>
#include<string.h>
#include"header.h"

struct user {
	char name[20];
	int a;
	int b;
};
void disp(list_t *);
int dele(list_t *, void *);

int dele(list_t *del, void *p)
{
	int ret;
	struct user *cp = p;
	struct user *obj = del->data;
	ret = strcmp(obj->name,cp->name);
	return ret;
}

void disp(list_t *da)
{
	struct user *obj = da->data;
	printf("%s %d %d\n", obj->name, obj->a, obj->b);
	return;
}

int main()
{
	int ret;
	list_t *start = NULL;
	struct user *obj1, *obj2, *obj3;

	obj1 = malloc(sizeof(struct user));
	if(!obj1)
		exit(1);
	strcpy(obj1->name, "obj1 message");
	obj1->a = 1;
	obj1->b = 11;
	obj2 = malloc(sizeof(struct user));
	if(!obj2)
		exit(2);
	strcpy(obj2->name, "obj2 message");
	obj2->a = 2;
	obj2->b = 22;
	obj3 = malloc(sizeof(struct user));
	if(!obj3)
		exit(3);
	strcpy(obj3->name, "obj3 message");
	obj3->a = 3;
	obj3->b = 33;

	ret = insert_first(&start, obj1);

	ret = insert_last(&start, obj2);
	
	ret = insert_last(&start, obj3);

	display(&start, disp);
	printf("deletetig first\n");
	ret = delete_first(&start);
	display(&start, disp);
	printf("deleting last\n");
	ret = delete_last(&start);
	display(&start, disp);
	printf("inserting few objects\n");
	ret = insert_first(&start, obj1);
	ret = insert_last(&start, obj3);
	ret = insert_last(&start, obj2);
	ret = insert_first(&start, obj3);
	display(&start, disp);
	printf("deleting obj3\n");
	
	
	ret = delete_ele(&start,dele, obj3);
	display(&start, disp);
	
	return 0;
}


	
