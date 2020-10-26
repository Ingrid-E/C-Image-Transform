#ifndef _IMAGE_H_
#define _IMAGE_H_
#include <iostream>
#include"File.h"

class File;
class Image{
	private:
		int** aImage;
		int max;
		int height;
		int width;
		int type;
		
		void setHeight(int height);
		void setWidth(int width);
		void initImage();
		
	public:
		Image();
		/**
		 * Constructor
		 * @param rows 
		 * @param cols 
		 */	
		Image(int rows, int cols);
		/**
		 * Constructor de la clase
		 * @param rows 
		 * @param cols 
		 * @param maxValue 
		 */
		Image(int rows, int cols, int maxValue);
		/**
		 * Destructor
		*/
		~Image();
		/**
		 * Obtiene la altura de la imagen
		 * @return  altura
		 */
		int getHeight();
		/**
		 * Obtiene la anchura de la imagen
		 * @return  anchura
		 */
		int getWidth();
		/**
		 * Obtiene el valor de la matriz que representa
		 * la imagen, imagen[x][y]
		 * 
		 * @param x posicion x
		 * @param y posicion y 
		 * @return  anchura
		 */
		int getPixel(int x, int y);
		/**
		 * Establece el valor de la matriz que representa
		 * la imagen, imagen[x][y] = value
		 * 
		 * @param x posicion x
		 * @param y posicion y 
		 * @param  value
		 */
		int getMax();
		void setPixel(int x, int y, int value);
		/**
		 * Establece el valor de la matriz que representa
		 * la imagen, imagen[x][y] = value
		 * 
		 * @param x posicion x
		 * @param y posicion y 
		 * @param  value
		 * @param  channel
		 */
		void setPixel(int x, int y, int value, int channel);	
		/**
		 * Permite guardar una imagen
		 * 
		 * @param path
		 */
		 int saveImage(Image* imagen, string nombre);
		/**
		 */
		 void setType(int type);
		
};
#endif
