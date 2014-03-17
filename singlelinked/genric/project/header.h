#ifndef GENRIC
	#define GENRIC
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct node {
	void *data;
	struct node *next;
} list_t ;

extern int insert_first(list_t **,void *);
extern int insert_last(list_t **, void *);
extern int delete_first(list_t **);
extern int delete_last(list_t **);
extern int delete_ele(list_t **,int(*)(list_t *, void *), void *);
extern int display(list_t **,void(*)(list_t *));
#endif
