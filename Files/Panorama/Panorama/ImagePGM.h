#ifndef IMAGEPGM_H
#define IMAGEPGM_H
#include "Image.h"

class ImagePGM:public Image{


	public:
		/**
		 * Constructor
		*/
		ImagePGM();
		/**
		 * Constructor
		 * @param rows
		 * @param cols
		 * @param maxValue
		*/
		//ImagePGM(int rows, int cols, int maxValue);
		/**
		 * Destructor
		*/
		~ImagePGM();
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
