#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image3.hpp"
#include <iostream>
#include <fstream>
using namespace std;


  /* Constructs an image of 0x0 pixels. */
  //Image();

  /* Constructs an image of 0x0 pixels. */
 // Image();

  Image:: Image() : cols(0), rows(0), pixels(NULL) {

  }

  /* Frees all memory allocated for img */
  Image::~Image() {
    if (pixels != NULL) {

      delete[] pixels;
    }
  }

  /* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolor. Returns 0 on success, or a
     non-zero error code.*/
  int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ) {
    if (pixels != NULL) {

      delete[] pixels;
    }

    rows = height;
    cols = width;

    pixels = new uint8_t*[height];
    if (pixels != NULL) {
      for (int i = 0; i < height; i++) {
        pixels[i] = new uint8_t[width];

      }
    }
    if (pixels != NULL) {
      for (int i = 0; i < height; i++) {
        for (int j = 0; j < rows; j++) {
          pixels[i][j] = fillcolor;
        }
      }

      return 0;
    }
    return 1;
  }

  /* Sets the color of the pixel at (x,y) to color. Returns 0 on
     success, else a non-zero error code. If (x,y) is not a valid
     pixel, the call fails and the image does not change.*/
  int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ) {
    if (pixels != NULL) {
      if (x < cols && y < rows) {
        pixels[y][x] = color;
        return 0;
      }

    }
    return 1;
  }

  /* Gets the color of the pixel at (x,y) and stores at the address
     pointed to by colorp. Returns 0 on success, else a non-zero error
     code. */
  int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ) {
    if (pixels != NULL) {
      if (colorp == NULL) {
        return 1;
      }
      if (x < cols && y < rows) {
        *colorp = pixels[y][x];
        return 0;
      }

    }
    return 1;
  }


  /* Saves the image in the file filename. In a format that can be
     loaded by load().  Returns 0 on success, else a non-zero error
     code. */
  int Image::save( const char* filename ) {

    if (filename != NULL) {
      ofstream fileOut(filename, ios::binary);

      if (fileOut == NULL) {
        return 1;
      }


    fileOut.write((char*)&rows, sizeof(uint8_t));
    fileOut.write((char*)&cols, sizeof(uint8_t));
    for (int i =0; i < cols; i++) {

      fileOut.write((char*)pixels[i], sizeof(uint8_t)*rows*cols);

    }


      return 0;
    }
    return 1;
  }

  /* Load the an image from the file filename, replacing the current
     image size and data. The file is in a format that was saved by
     save().  Returns 0 success, else a non-zero error code . */
  int Image::load( const char* filename ) {

    //if (filename != NULL) {
      ifstream fileIn(filename, ios::binary);
     // fileIn.open(filename, ios::binary);
      if (fileIn == NULL) {
        return 1;
      }


      fileIn.read((char*)&rows, sizeof(uint8_t));
      fileIn.read((char*)&cols, sizeof(uint8_t));
      //resize(cols, rows, 0);
      for (int i = 0; i < cols; i++) {
       fileIn.read((char*)pixels[i], sizeof(uint8_t)*rows*cols);
      }



      return 0;

    }
