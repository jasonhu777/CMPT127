
#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include "image.hpp"

	//Constructor
	Image::Image() : cols(0), rows(0), pixels(NULL) {

	}

	//Deconstructor
  	Image::~Image() {
  		if (pixels !=NULL) {
  			delete[] pixels;
  		}
  	}
  /* Constructs an image of 0x0 pixels. */
  //Image();
  
  /* Frees all memory allocated for img */
  //~Image();
  
  /* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/ 
  int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ) {
  	delete[] pixels;

  	uint8_t pixels[width*height];
  	if (pixels != NULL) {
  		for (int i = 0; i < width*height; i++) {
  			pixels[i] = fillcolor;
  		}
  		return 0;
  	}
  	return 1;
  }
  
  /* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
  int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ) {
  	if (pixels != NULL) {
  		if (x < cols && y < rows) {
  			pixels[y*cols+x] = color;
  			return 0;
  		}
  		
  	}
  	return 1;
  }
  
  /* Gets the color of the pixel at (x,y) and stores at the address pointed to 
     by colorp. Returns 0 on success, else a non-zero error code. */
  int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ) {
  	if (pixels != NULL) {
  		if (x < cols && y < rows) {
  			*colorp = pixels[y*cols+x];
  			return 0;
  		}
  	}
  	return 1;
  }

