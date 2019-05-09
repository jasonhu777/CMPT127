#include <stdio.h>
#include <stdlib.h>

#include "intarr.h"

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ) {
	if (ia != NULL && filename != NULL) {
		FILE* f = fopen(filename, "w");
		if (f == NULL) {			
			return 1;
		
		}
		if (fwrite(&ia->len, sizeof(int), 1, f) != 1) {
			return 2;
		}
		if (fwrite(ia->data, sizeof(int), ia->len, f) != ia->len) {
			return 3;
		}
		fclose(f);
		return 0;
	}
	return 4;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename ) {
	if (filename != NULL) {
		FILE* f = fopen(filename, "r");
		if (f == NULL) {
			return NULL;
		}
		intarr_t* new = malloc(sizeof(intarr_t));
		if (new == NULL) {
			return NULL;
		}
		if (fread(&new->len, sizeof(int), 1, f) != 1) {
			return NULL;
		}
		new->data = malloc(new->len*sizeof(int));
		if (new->data == NULL) {
			return NULL;
		} 
		if (fread(new->data, sizeof(int), new->len, f) != new->len) {
			return NULL;
		}
		fclose(f);
		return new;
		
	}
	return NULL;
	
}