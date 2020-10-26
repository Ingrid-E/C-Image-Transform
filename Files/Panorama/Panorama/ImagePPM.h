#ifndef IMAGEPPM_H
#define IMAGEPPM_H
#include "Image.h"

class ImagePPM:public Image{



	public:
		/**
		 * Constructor
		 * @param rows
		 * @param cols
		 * @param maxValue
		*/
		ImagePPM();
		/**
		 * Destructor
		*/
		~ImagePPM();
		/**
		 * 
		 * @param rows
		 * @param cols
		*/
		void resize(int rows,int cols);
		/**
		 * 
		 * @param rows
		 * @param cols
		 * @param value
		*/
		void setPixel(int row,int col,int value);

};
#endif
