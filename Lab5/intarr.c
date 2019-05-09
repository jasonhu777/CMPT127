
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "intarr.h"

// Task 1
// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ) {

	assert (len >= 0);
	intarr_t* ptr = malloc(sizeof(intarr_t));
	if (ptr != NULL) {
		ptr->data = malloc(len*sizeof(int));
		if (ptr->data != NULL) {
			ptr->len = len;
			return ptr;
		}
	} 
	return NULL;
	

}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ) {
	if (ia != NULL ) {
		free (ia);
	}

}

// Task 2
// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val ) {
	if (ia == NULL) {
		return INTARR_BADARRAY;
	}
	int len = ia->len;
	if (index >= 0 && index < len) {
	//	(*ia).data[index] = val;
		ia->data[index] = val;
		return INTARR_OK;
	}
	return INTARR_BADINDEX;
}

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index, 
			    int* i ) {
	if (ia == NULL) {
		return INTARR_BADARRAY;
	}

	int len = ia->len;
	if (index >= 0 && index < len && i != NULL) {
		*i = ia->data[index];
		return INTARR_OK;
	}
	return INTARR_BADINDEX; 
}

//Task 3
// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
intarr_t* intarr_copy( const intarr_t* ia ) {
	if (ia != NULL) {
		int len = ia->len;
		intarr_t* copy = malloc(sizeof(intarr_t));
		if (copy != NULL) {
			copy->data = malloc(len*sizeof(int));
			if (copy->data != NULL) {
				copy->len = len;
				memcpy(copy->data, ia->data, len);
				return copy;
			}
		}
	}
	return NULL;

}

//Task 4
// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ) {

	if (ia == NULL) {
		return INTARR_BADARRAY;
	}

	int len = ia->len;
	for (int i = 0; i < len; i++) {
			int tmp = 0;
		for (int j = 0; j < len-i; j++) {
			if ((*ia).data[j] > (*ia).data[j+1]) {
				tmp = (*ia).data[j];
				(*ia).data[j] = (*ia).data[j+1];
				(*ia).data[j+1] = tmp;
			}
		}
	}
	return INTARR_OK;
}

//Task 5
// Find the first occurance of the target in the array, searching from
//Task 5
// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ) {
	if (ia == NULL) {
		return INTARR_BADARRAY;
	}
	int index = 0;
	for (int j = 0; j < ia->len; j++) {
		if (ia->data[j] == target) {
			*i = j;
			return INTARR_OK;
		}
	}
	return INTARR_NOTFOUND;
}

//Task 6
// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ) {
	if (ia == NULL) {
		return INTARR_BADARRAY;
	}
	int len = ia->len; 
	ia->data = realloc(ia->data, sizeof(int)*(len+1));
	if (ia->data == NULL) {
		return INTARR_BADALLOC;
	}
	ia->data[len] = val;
	ia->len++;
	return INTARR_OK;

}

// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ) {
	if (ia == NULL) {
		return INTARR_BADARRAY;
	}
	//(*ia).data
	int len = ia->len;

		 ia->data = realloc(ia->data, sizeof(int)*(len));
		if (ia->data == NULL || len <= 0) {
			return INTARR_BADINDEX;
		}
	*i = ia->data[len-1];
	ia->len--;
	return INTARR_OK;

}

//Task 7
// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ) {
	if (ia == NULL) {
		return INTARR_BADARRAY;
	}

	int oldLen = ia->len;
	ia->data = realloc(ia->data, sizeof(int)*newlen);
	if (ia->data == NULL) {
			return INTARR_BADALLOC;
	}
	if (newlen < oldLen) {
		ia->len = newlen;
		return INTARR_OK; 
	} else {
		for (int i = oldLen; i < newlen; i++) {
			ia->data[i] = 0;
		}
		ia->len = newlen;
		return INTARR_OK;
	}
	
	

}

//Task 8
// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last ) {

	if (ia == NULL) {
		return NULL;
	}
	int len = ia->len;
	intarr_t* copy = malloc(sizeof(intarr_t));
	if (copy == NULL || first < 0 || last >= len || last < first) {
		return NULL;
	}

	int newlen = last - first + 1;
	copy->len = newlen;
	copy->data = malloc(newlen*sizeof(int));
	if (copy->data == NULL) {
		return NULL;
	}
	//memcpy((*copy).data, (*ia).data, len);
	int original = first;
	for (int i = 0; i < newlen; i++) {
		
		copy->data[i] = ia->data[original];
		original++;
	}
	return copy;


}

