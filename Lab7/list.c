#include <stdio.h>
#include <stdlib.h>
#include "list.h"



list_t* list_create( void ) {
	list_t * list = malloc(sizeof(list_t));
	if (list != NULL) {
		list->head = NULL;
		list->tail = NULL;
	}
	return list;
}

void list_destroy( list_t* list ) {
	element_t* curr = list->head;
	element_t* next;
	while (curr != NULL) {
		next = curr->next;
		
		free(curr);
		curr = next;
	}
	free(list);	
}


element_t* element_create( int i ) {
	element_t* ele = malloc(sizeof(element_t));
	if (ele == NULL) {
		return NULL;
	}
	ele->val = i;
	ele->next = NULL;
	return ele;
	
}


int list_append( list_t* list, int i ) {
	element_t* ele = element_create(i);
	if (ele == NULL) {
		return 1;
	}
	if (list->head == NULL) {
		//empty list
		list->head = ele;
		list->tail = ele;
	} else {
		list->tail->next = ele;
		list->tail = ele;
	}
	return 0;

}


int list_prepend( list_t* list, int i ) {
	element_t* ele = element_create(i);
	if (ele == NULL) {
		return 1;
	}
	if (list->head == NULL) {
		//empty list
		list->head = ele;
		list->tail = ele;
	}
	else {
		ele->next = list->head;
		list->head = ele;
	}

	return 0;
}


element_t* list_index( list_t* list, unsigned int i ) {

	element_t* curr = list->head;
	int count = 0;
	while (curr != NULL) {
		if (count == i) {
			return curr;
		}
		count++;
		curr = curr->next;
	}
	return NULL;
	
}

void list_print( list_t* list ) {
	printf( "{");
	for (element_t* ele = list->head; ele; ele = ele->next) {
		printf(" %d", ele->val);
	}
	printf(" }\n");
}