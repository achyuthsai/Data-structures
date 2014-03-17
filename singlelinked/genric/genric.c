#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


struct user {
		char name[20];
		int a;
		int b;
};

struct node {
	struct user *data;
	struct node *next;
};

struct node *start = NULL;

int insert_first(struct user *p)
{

	struct node *new, *tmp;

	new = malloc(sizeof(struct node));
	if(!new){
		perror("malloc");
		exit(2);
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

void print(void)
{
	struct node *tmp;
	tmp = start;

	while(tmp){
		printf("name: %s, num1: %d, num2: %d\n", tmp->data->name, tmp->data->a, tmp->data->b);
		tmp = tmp->next;
	}

	printf("\n");
	return;
}


int main()
{

struct user *p;
struct user *p1;

	p =  malloc(sizeof(struct user));
	p1 = malloc(sizeof(struct user));
	strcpy(p->name, "sai");
	p->a = 10;
	p->b = 20;
	strcpy(p1->name, "praveen");
	p1->a = 30;
	p1->b = 40;


	insert_first(p);
	insert_first(p1);
	print();
	return 0;
}
