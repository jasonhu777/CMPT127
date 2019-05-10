#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"


void appendElement(list_t* list, element_t* ele) {
	if (ele != NULL) {
		ele->next = NULL;
	}
	if (list->head == NULL) {
		
		list->head = ele;
		list->tail = ele;
	} else {

		list->tail->next = ele;
		list->tail = ele;
	}
}

void catenate(list_t* list1, list_t* list2) {
	if (list2->head == NULL) {
		
		assert(list2->tail == NULL);
	}
	else if (list1->head == NULL) {
		assert(list1->tail == NULL);
		
		list1->head = list2->head;
		list1->tail = list2->tail;

	} else {
		list1->tail->next = list2->head;
		list1->tail = list2->tail;
	}
	free(list2);
}



void list_sort( list_t* list ) {
	
	if (list->head == list->tail) {
		return;
	}
	int pivot = list->head->val;
	element_t* ele_pivot = list->head;
	list->head = list->head->next;

	

	list_t* low = list_create();
	list_t* high = list_create();

	element_t* curr = list->head;
	element_t* next;


	while (curr != NULL) { 
		next = curr->next; 
		curr->next = NULL; 
		if (curr->val < pivot) {
			appendElement(low, curr);
		} else {
			
			appendElement(high, curr);
		}
		curr = next;
	}

	list->head = NULL;
	list->tail = NULL;

	list_sort(low);
	list_sort(high);

	catenate(list, low);

	appendElement(list, ele_pivot);

	
	catenate(list, high);

	
}

