#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "imgops.h"
#include <stdlib.h>





// starting from left most corner
//(x−a)^2+(y−b)^2=r^2
// if (x^2 + y^2 < radius^2) set_pixel

// center of circle at x,y with specified radius in pixel
// every pixel that contains a point inside the difined circle distance to {x,y} < radius muts be set to color
// r must be > 0
// xdistance absolute(x-j) ydistance absolute(y-i)
 

void draw_circle( uint8_t img[], 
                  unsigned int cols,
                  unsigned int rows,
		  int x,
		  int y,
		  int r,
		  uint8_t color ) {

	int xDist, yDist = 0;

	if ( r > 0) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
		
				xDist = abs(x-j);
				yDist = abs(y-i);
				

				if ((sqrt((pow(xDist-0.5, 2)) + (pow(yDist-0.5, 2)))) < r ||
					(sqrt((pow(xDist+0.5, 2)) + (pow(yDist+0.5, 2)))) < r) {
				
					set_pixel(img, cols, rows, j, i, color);
				}
			}
		}
	}


}