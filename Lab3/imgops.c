/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  memset(array, 0, cols * rows * sizeof(array[0]));
}


uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  uint8_t* ptr = malloc(cols * rows * sizeof(uint8_t));

  if (!ptr) {
    return NULL;
  }

  memcpy(ptr, array, cols * rows * sizeof(uint8_t));

  return ptr;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  
  uint8_t min = array[0];
  for (int i = 0; i < cols * rows; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  // your code here
  uint8_t max = array[0];
  for (int i = 0; i < cols * rows; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  for (int i = 0; i < cols * rows; i++) {
    if (array[i] == pre_color) {
      array[i] = post_color;
    }
  }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{

  uint8_t tmp = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols/2; j++) {
      tmp = array[j + i*cols];
      array[j + i*cols] = array[cols-1-j + i*cols];
      array[cols-1-j + i*cols] = tmp;

    }
  }
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
  uint8_t tmp = 0;
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows/2; j++) {
    
      tmp = array[i + j*cols];
      array[i + j*cols] = array[i + (rows - 1 - j)*cols];
      array[i + (rows - 1 - j)*cols] = tmp;
      

    }
  }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      // use get_pixel from Task 0
      // gets the value in the array at coordinate (j,i)
      if (get_pixel(array, cols, rows, j, i) == color) {
        *x = j;
        *y = i;
        return 1;
      }
    }
    
  }
  return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
  for (int i = 0; i < cols*rows; i++) {
    array[i] = 255 - array[i];
  }

}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  double pixel = 0.0;
  for (int i =0; i < cols*rows; i++) {
    pixel = round(scale_factor*array[i]);
    if (pixel >  255) {
      array[i] = 255;
    } else {
      array[i] = pixel;
    }
  }
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
  uint8_t minNum = min(array, cols, rows);
  uint8_t maxNum = max(array, cols, rows);
  uint8_t range = maxNum - minNum;

  for (int i = 0; i < cols*rows; i++) {
//round, 255-0
// newImg = ((255-0)/maxImg-minImg*(img-minImg))
   array[i] = round(255.0*(array[i] - minNum)/range);
//0-255 = 256?
    //array[i] = (256*(array[i]-minNum)/range);
  }

}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  uint8_t average = 0;

  uint8_t* new = malloc((cols/2) * (rows/2) * sizeof(uint8_t));

  for (int q = 0; q < rows/2; q++) {
    for (int p = 0; p < cols/2; p++) {
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.
      average = round((
        get_pixel(array, cols, rows, 2*p, 2*q) + 
        get_pixel(array, cols, rows, 2*p+1, 2*q) +
        get_pixel(array, cols, rows, 2*p+1, 2*q+1) +
        get_pixel(array, cols, rows, 2*p, 2*q+1))/4.0);

        set_pixel(new, cols/2, rows/2, p, q, average);

    }
  }
  return new;
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  if ((left != right) && (top != bottom)) {
    for (int i = left; i < right; i++) {
      for (int j = top; j < bottom; j++) {
        set_pixel(array, cols, rows, i, j, color);
      }
    }
  }
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  unsigned long int sum = 0;

  if ((left != right) && (top != bottom)) {
    for (int i = left; i < right; i++) {
      for (int j = top; j < bottom; j++) {
        sum += get_pixel(array, cols, rows, i, j);
      }    
    }
  }
  return sum;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  int col = 0;
  int row = 0;
  col = right - left;
  row = bottom - top;
  
  uint8_t* new = malloc(col*row*sizeof(uint8_t));
  if (!new) {
    return NULL;
  }

  if ((left != right) && (top != bottom)) {
    for (int i = left; i < right; i++) {
      for (int j = top; j < bottom; j++) {
        int pixel = 0;
        pixel = get_pixel(array, cols, rows, i, j);
        set_pixel(new, col, row, i-left, j-top, pixel);
        
      }
    }
    return new;
  }
return NULL;
}
