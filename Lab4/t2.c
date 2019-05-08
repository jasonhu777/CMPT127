#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "imgops.h"


void draw_rectangle( uint8_t array[], 
		          unsigned int cols, 
		          unsigned int rows, 
		          int x,
		          int y,
		          int rect_width,
		          int rect_height,
		          uint8_t color ) {


	uint8_t start = x+(y*rect_width);

	
	if (rect_width > 0 && rect_height > 0) {
		for (int i = y; i < y + rect_height; i++) {
				for (int j = x; j < x + rect_width; j++) {
			
					if (j == x || j == x + rect_width - 1) {
						
						
						if (j < cols && i < rows) {
							set_pixel(array, cols, rows, j, i, color);
							
						}
					}
					if (i == y || i == y + rect_height - 1) {
						
						if (j < cols && i < rows) {
							set_pixel(array, cols, rows, j, i, color);	

						}
					}					
				}
		}
	}
			
	
	if (rect_width < 0 && rect_height < 0) {

		for (int i = y; i > y + rect_height; i--) {
			for (int j = x; j > x + rect_width; j--) {
				if ( j == x || j == x + rect_width + 1) {
					if ( j < cols && i < rows) {
						set_pixel(array, cols, rows, j, i, color);
					}
 				}
 				if ( i == y || i == y + rect_height + 1) {
 					if ( j < cols && i < rows) {
 						set_pixel(array, cols, rows, j, i, color);
 					}
 				}

			}
		}
	}
	if (rect_width < 0 && rect_height > 0) {
		for (int i = y; i < y + rect_height; i++) {
			for (int j = x; j > x + rect_width; j--) {
				if (j < cols && i < rows) {
					if ( j == x || j == x + rect_width +1) {
						set_pixel(array, cols, rows, j, i, color);
					}
					if (i == y || i == y + rect_height -1) {
						set_pixel(array, cols, rows, j, i, color);
					}
				}
			} 
		}
	}

	if (rect_width > 0 && rect_height < 0) {
		for (int i = y; i > y + rect_height; i--) {
			for (int j = x; j < x + rect_width; j++) {
				if ( j < cols && i < rows) {
					if ( j == x || j == x + rect_width-1) {
						set_pixel(array, cols, rows, j, i, color);
					}
					if (i == y || i == y + rect_height +1) {
						set_pixel(array, cols, rows, j, i, color);
					}
				}
			}
		}
	}

}
		

		