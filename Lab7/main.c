#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main( int argc, char* argv[] )
{
  // test the create function
  list_t* list = list_create();

  // check to see if the create function did everything it was supposed to
  if( list == NULL )
    {
      printf( "create: create failed to malloc\n" );
      return 1;
    }

  if( list->head != NULL )
    {
      printf( "create: head is not null!\n" );
      return 1;
    }

  if( list->tail != NULL )
    {
      printf( "create: tail is not null!\n" );
      return 1;
    }

  // now test all the other functions (except list_print) to see if
  // they do what they are supposed to

  // you code goes here
 
    //t2 create error
  element_t* ele1 = element_create(101);
  element_t* ele2 = element_create(999);
  if (ele1 == NULL || ele2 == NULL) {
    printf("malloc ele1 failed\n");
    return 1;
  }
  if (ele1->val != 101) {
    printf("value of ele wrong\n");
    return 1;
  }
  if (ele1->next != NULL) {
    printf("pointer not properly set to NULL\n");
    return 1;
  }
  ele1->next = ele2;
  free(ele1);
  ele1 = element_create(100);
  if (ele1->next != NULL) {
    printf("pointer not properly set to NULL\n");
    return 1;
  }

  //list append working for t1-t5
  for (int i = 0; i < 10; i++) {
    list_append(list, i);
  }
  //t1 to t5 all print properly
  list_print(list);
  if (list->tail->next != NULL) {
    printf("append pointer not set properly\n");
    return 1;
  }

  list_prepend(list, 99);
  list_print(list);
  if (list->head->val == 99) {
    printf("prepend success\n");
  }
  
  list_t* list2 = list_create();
  
  list_prepend(list2, 1);
  if (list2->tail != list2->head) {
    printf("prepend for empty list not successful\n");
    return 1;
  }
  list_print(list2);
  list_t* list3 = list_create();

  
  element_t* emptyEle = list_index(list3, 10);
  if (emptyEle != NULL) {
    printf("incorrect list_index should be NULL for empty\n");
    return 1;
  }


  element_t* secondEle = list_index(list, 2);
  if (secondEle->val != 1) {
    printf("wrong value for the index\n");
    return 1;
  }
  element_t* offEle = list_index(list, 30);
  if (offEle != NULL) {
    printf("misprinted index larger than list\n");
    return 1;
  }
  element_t* zeroEle = list_index(list, 0);
  if (zeroEle->val != 99) {
    printf("wrong value for index 0\n");
    return 1;


    return 0;
  }

  return 0;
